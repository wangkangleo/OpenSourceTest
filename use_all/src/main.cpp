#include <iostream>

#include "use_spdlog.h"
#include "use_boost.h"

int main(int argc, char ** argv)
{
    std::cout<<"test open source code begin"<<std::endl;

    UsespdLog use_log;
    if(use_log.init())
    {
        use_log.run();
    }

    UseBoost use_boost;
    if(use_boost.init())
    {
        use_boost.run();
    }

    while(true)
    {
        sleep(1000);
    }

    return 0;
}