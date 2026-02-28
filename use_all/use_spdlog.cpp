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
    logger_inst -> test_basic();
    return true;
}
