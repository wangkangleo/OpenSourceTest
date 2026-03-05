#include "use_spdlog.h"


UsespdLog::UsespdLog()
{

}

UsespdLog::~UsespdLog()
{

}

bool UsespdLog::init()
{

    return true;
}

bool UsespdLog::run()
{
    logger_inst -> test();

    unsigned short test_hort = 666;
    const char * test_char = "777";
    InfoLog("ce shi yixia,%d,%s,%hu,%s",111,"222",test_hort,test_char);

    return true;
}
