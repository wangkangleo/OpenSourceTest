#include <iostream>

#include "use_spdlog.h"

int main(int argc, char ** argv)
{
    std::cout<<"test open source code begin"<<std::endl;

    UsespdLog use_log;
    if(use_log.init())
    {
        use_log.run();
    }

    return 0;
}