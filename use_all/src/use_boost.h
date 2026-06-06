#ifndef USE_BOOST
#define USE_BOOST

#include <boost/filesystem.hpp>

#include <stdio.h>
#include <iostream>  



class UseBoost
{
public:
    UseBoost();
    ~UseBoost();

    bool init();
    void run();

    void filesystem();
};


#endif