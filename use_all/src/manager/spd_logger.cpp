#include "spd_logger.h"
    

spdLogger::spdLogger()
{

}

spdLogger * spdLogger::get_logger_inst()
{
    static spdLogger logger;
    return &logger;
}
    
spdLogger::~spdLogger()
{

}

bool spdLogger::test()
{
    spdlog::info("Welcome to spdlog version {}.{}.{}  !", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR,
                     SPDLOG_VER_PATCH);

    spdlog::flush_every(std::chrono::seconds(3));

    auto async_file =
        spdlog::basic_logger_mt<spdlog::async_factory>("async_file_logger", "logs/async_log.txt");


    for (int i = 1; i < 101; ++i) {
        async_file->info("Async message #{}", i);
    }

    auto daily_logger = spdlog::daily_logger_mt("daily_logger", "logs/daily.txt", 2, 30);
    daily_logger->info("test_day");

    auto hour_logger = spdlog::hourly_logger_mt("hourly_logger", "logs/hourly.txt");

    std::thread t([&]{
        while(1)
        {
            Sleep(10000);
            daily_logger->info("test_day !!!");
            hour_logger->info("test_hour !!!");
        }
    });

    t.join();

    return true;
}
