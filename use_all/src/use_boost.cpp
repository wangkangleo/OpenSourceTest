#include "use_boost.h"
#include "manager/network_manager.h"

UseBoost::UseBoost()
{

}
UseBoost::~UseBoost()
{

}

bool UseBoost::init()
{
    return true;
}
void UseBoost::run()
{
    filesystem();

    NetworkManager network_manager;
    network_manager.start();
}
void UseBoost::filesystem()
{
    std::cout<<"SConstruct size:"<<boost::filesystem::file_size("/home/wangkang/share/OpenSourceTest/use_all/SConstruct")<<"\n";
}