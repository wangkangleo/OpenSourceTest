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

void spdLogger::init()
{
    spdlog::init_thread_pool(8192,2);
    spdlog::flush_every(std::chrono::seconds(2));

    auto sink = std::make_shared<spdlog::sinks::hourly_file_sink_mt>("logs/log");
    sink -> set_level(spdlog::level::trace);

    m_logger = std::make_shared<spdlog::logger>("spd_logger",spdlog::sinks_init_list({sink}));

    spdlog::initialize_logger(m_logger);
    spdlog::set_default_logger(m_logger);
}

bool spdLogger::test()
{
    spdlog::info("Welcome to spdlog version {}.{}.{}  !", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR,
                     SPDLOG_VER_PATCH);


    for (int i = 1; i < 101; ++i) {
        m_logger->info("Async message %d, i hope %s", i, "success");
    }


    return true;
}

bool spdLogger::debug(const char* format, ...)
{
    //std::string msg = fmt::sprintf(fmt::v12::string_view(format),);
    return true;
}


bool spdLogger::info(std::string msg)
{
    m_logger->info(msg);

    return true;
}