#pragma once

//#define SPDLOG_USE_STD_FORMAT

#include <thread>

#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h" 
#include "spdlog/fmt/ostr.h" 
#include "spdlog/async.h"
#include "spdlog/details/log_msg.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/hourly_file_sink.h"
#include "spdlog/fmt/bundled/printf.h"
#include "spdlog/fmt/bundled/format.h"

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

    bool test();
    bool debug(const char* format, ...);

    bool info(std::string msg);

private:
    std::shared_ptr<spdlog::logger> m_logger;
};


