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

bool spdLogger::test_basic()
{
    spdlog::info("Welcome to spdlog version {}.{}.{}  !", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR,
                     SPDLOG_VER_PATCH);

    auto async_file =
        spdlog::basic_logger_mt<spdlog::async_factory>("async_file_logger", "logs/async_log.txt");


    for (int i = 1; i < 101; ++i) {
        async_file->info("Async message #{}", i);
    }

    return true;
}


