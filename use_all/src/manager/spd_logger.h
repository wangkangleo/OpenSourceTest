#pragma once

#include "spdlog/spdlog.h"

#include <thread>
#include <string>

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

    inline spdlog::logger* get_logger(){return m_logger.get();}
    inline static void set_logger_name(const char* name){m_logger_name = name;}
private:
    std::shared_ptr<spdlog::logger> m_logger;
    static std::string m_logger_name;
};

#define logger_inst spdLogger::get_logger_inst()
#define TraceLog(format, ...) logger_inst->get_logger()->trace(format, ##__VA_ARGS__);
#define DebugLog(format, ...) logger_inst->get_logger()->debug(format, ##__VA_ARGS__);
#define InfoLog(format, ...) logger_inst->get_logger()->info(format, ##__VA_ARGS__);
#define WarnLog(format, ...) logger_inst->get_logger()->warn(format, ##__VA_ARGS__);
#define ErrorLog(format, ...) logger_inst->get_logger()->error(format, ##__VA_ARGS__);
#define CriticalLog(format, ...) logger_inst->get_logger()->critical(format, ##__VA_ARGS__);