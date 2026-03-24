#ifndef USE_SPDLOG
#define USE_SPDLOG

#include "spd_logger.h"

//#define logger_inst spdLogger::get_logger_inst()  

//#define DebugLog(format, ...) logger_inst->debug(format, ##__VA_ARGS__);
//#define InfoLog(format, ...) logger_inst->info(fmt::v12::sprintf(format, ##__VA_ARGS__));

//#define Sprintf(format, ...) fmt::v12::sprintf(format, ##__VA_ARGS__);

enum test_enum
{
    one=1,
    two =2,
};

class UsespdLog
{
public:
    UsespdLog();
    ~UsespdLog();

    bool init();
    bool run();

    void test(test_enum num);
};


#endif