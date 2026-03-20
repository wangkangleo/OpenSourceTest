#pragma once

//#define SPDLOG_USE_STD_FORMAT

#include <thread>

#include "spdlog/spdlog.h"


class spdLogger
{
private:
    spdLogger();
public:
    static spdLogger * get_logger_inst();
    void init();
    ~spdLogger();
    spdLogger(const spdLogger&) = delete;
    spdLogger& operator=(const spdLogger&) = delete;


private:
    std::shared_ptr<spdlog::logger> m_logger;
};

#define logger_inst spdLogger::get_logger_inst()  
#define TraceLog(format, ...) logger_inst->trace(format, ##__VA_ARGS__);
#define DebugLog(format, ...) logger_inst->debug(format, ##__VA_ARGS__);
#define InfoLog(format, ...) logger_inst->info(format, ##__VA_ARGS__);
#define WarnLog(format, ...) logger_inst->warn(format, ##__VA_ARGS__);
#define ErrorLog(format, ...) logger_inst->error(format, ##__VA_ARGS__);
#define CriticalLog(format, ...) logger_inst->critical(format, ##__VA_ARGS__);