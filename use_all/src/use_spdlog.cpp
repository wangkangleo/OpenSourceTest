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

/*template <typename T>
struct fmt::formatter<T, char, fmt::printf_context> 
    : fmt::internal::printf_arg_formatter<fmt::buffer_context<char>> {
    
    // 注意：printf_arg_formatter 没有 parse 方法
    // 我们只需要实现 format 方法
    
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
    std::string str = Sprintf("ce shi liang xia, %s, zhe shi shenm me, %d", "????",num);
}

bool UsespdLog::run()
{
    logger_inst -> test();

    test(two);

    unsigned short test_hort = 666;
    const char * test_char = "777";
    //InfoLog("ce shi yixia,%d,%s,%hu,%s",111,"222",test_hort,test_char);

    return true;
}
