#ifndef USE_SPDLOG
#define USE_SPDLOG

#include "spd_logger.h"

#define logger_inst spdLogger::get_logger_inst()  

class UsespdLog
{
public:
    UsespdLog();
    ~UsespdLog();

    bool init();
    bool run();

};


#endif