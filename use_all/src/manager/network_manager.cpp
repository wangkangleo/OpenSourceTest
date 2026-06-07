#include "network_manager.h"

#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/asio/write.hpp>

#include <iostream>

using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::co_spawn;
using boost::asio::detached;
//using boost::asio::redirect_error;   用错误码来取代抛异常(后期再用)
using boost::asio::use_awaitable;

namespace this_coro = boost::asio::this_coro;

awaitable<void> read(tcp::socket socket)
{
    try
    {
        char data[1024];
        for(;;)
        {
            std::size_t n = co_await socket.async_read_some(boost::asio::buffer(data),use_awaitable);
            std::cout<<"network_manager.cpp accept message: "<< std::string(data,n) << "\n";
            co_await boost::asio::async_write(socket,boost::asio::buffer(data,n),use_awaitable);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr <<"network_manager.cpp read exception: "<< e.what() << "\n";
    }

}

awaitable<void> listener()
{
    try
    {
        auto executor = co_await this_coro::executor;  //异步获取协程调度器,获取不到则挂起
        tcp::acceptor acceptor(executor,{tcp::v4(),1998}); //ip和端口(ip不写表示接受任意ip的连接请求,写了的话则指定固定ip)
        for(;;)
        {
            tcp::socket socket = co_await acceptor.async_accept(use_awaitable); //异步等待连接请求,获取不到则挂起
            std::cout<<"network_manager.cpp accept a new connection: "<< socket.remote_endpoint()<<"\n";
            co_spawn(executor,read(std::move(socket)),detached); //开启一个新的协程处理消息
        }
    }
    catch(const std::exception& e)
    {
        std::cerr <<"network_manager.cpp listener exception: " << e.what() << "\n";
    }
}


NetworkManager::NetworkManager()
{

}
NetworkManager::~NetworkManager()
{

}

bool NetworkManager::start()
{

    boost::asio::io_context io_context(1);
    boost::asio::signal_set signals(io_context,SIGINT,SIGTERM);
    signals.async_wait([&](auto,auto){
        io_context.stop();  //收到SIGINT,SIGTERM这两个信号 停止
    });
    co_spawn(io_context,listener(),detached);

    std::cout<<"network_manager.cpp io_context.run() start\n";

    io_context.run();


    return true;
}

