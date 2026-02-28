#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h" 
#include "spdlog/fmt/ostr.h" 
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

class spdLogger
{
private:
    spdLogger();
public:
    static spdLogger * get_logger_inst();
    ~spdLogger();
    spdLogger(const spdLogger&) = delete;
    spdLogger& operator=(const spdLogger&) = delete;

    bool test_basic();
};