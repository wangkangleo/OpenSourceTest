#include "spd_logger.h"
    
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

std::string spdLogger::m_logger_name = "unname_log";

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

void spdLogger::init()
{
    spdlog::init_thread_pool(8192,2);
    spdlog::flush_every(std::chrono::seconds(2));

    std::string file_name = "logs/";
    auto sink = std::make_shared<spdlog::sinks::hourly_file_sink_mt>((file_name+m_logger_name).c_str());
    sink -> set_level(spdlog::level::trace);

    m_logger = std::make_shared<spdlog::logger>("spd_logger",spdlog::sinks_init_list({sink}));

    spdlog::initialize_logger(m_logger);
    spdlog::set_default_logger(m_logger);
}
