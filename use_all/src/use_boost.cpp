#include "use_boost.h"


UseBoost::UseBoost()
{

}
UseBoost::~UseBoost()
{

}

bool UseBoost::init()
{
    return true;
}
void UseBoost::run()
{
    filesystem();
}
void UseBoost::filesystem()
{
    std::cout<<"SConstruct size:"<<boost::filesystem::file_size("/home/wangkang/share/OpenSourceTest/use_all/SConstruct")<<"\n";
}