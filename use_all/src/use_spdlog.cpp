#include "use_spdlog.h"


UsespdLog::UsespdLog()
{

}

UsespdLog::~UsespdLog()
{

}

bool UsespdLog::init()
{
    logger_inst->set_logger_name("test");
    return true;
}

/*template <typename T>
struct fmt::formatter<T, char, fmt::printf_context> 
    : fmt::internal::printf_arg_formatter<fmt::buffer_context<char>> {
    
    // ע�⣺printf_arg_formatter û�� parse ����
    // ����ֻ��Ҫʵ�� format ����
    
    template <typename Context>
    auto format(const T& value, Context& ctx) const -> decltype(ctx.out()) {
        using underlying_type = std::underlying_type_t<T>;
        auto int_value = static_cast<underlying_type>(value);
        return fmt::format_to(ctx.out(), "{}", int_value);
    }
};*/



void UsespdLog::test(test_enum num)
{
    //InfoLog("ce shi liang xia, %s, zhe shi shenm me", "????",(int)num);
    //std::string str = Sprintf("ce shi liang xia, %s, zhe shi shenm me, %d", "????",(int)num);
}

bool UsespdLog::run()
{
    //logger_inst -> test();

    test(two);

    InfoLog2("ce shi yixia, %p", this);
    //InfoLog2("ce shi yixia, %d", 666);

    return true;
}
