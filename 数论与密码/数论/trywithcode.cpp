#include "trywithcode.h"

//递归 欧几里得 (a > b)
int64_t Euclid(int64_t a, int64_t b)
{
    if(b == 0) return a;
    else return Euclid(b, a % b);
}

//递归 计算线性方程（贝组等式）的系数 (ax + by = gcd(a, b))
mat::Bezout_sult Euclid_extend(int64_t a, int64_t b)
{
    if(b == 0)
    {
        return {a, 1, 0};
    }
    else
    {
        auto [d, _x, _y] = Euclid_extend(b, a % b);
        return {d, _y, _x - (a / b) * _y}; 
    }
}

//求模线性方程的解
std::optional<mat::modLequa_sult> moduler_linear_equation_solver(int64_t a, int64_t b, int64_t n)
{
    mat::modLequa_sult result;
    auto Bz_rst = Euclid_extend(a, n);
    auto d = std::get<0>(Bz_rst);
    if(b % d == 0)
    {
        auto mod = [](int64_t x, int64_t n) { return (x % n + n) % n; };
        int64_t x0 = mod(std::get<1>(Bz_rst) * (b / d), n);
        for(int i = 0; i <= d-1; ++i)
        {
            result.push_back((x0 + i * (n / d)) % n);
        }
        return result;
    }
    else
    {
        return std::nullopt;       
    }
}

//求总有效位数
int effective_bits(uint64_t x)
{
    if(x == 0) return 0;
    else return 64 - __builtin_clzll(x);
}

//求模取幂(a的b次方mod n， a、b为非负整数， n为正整数)
uint64_t moduler_exponentiation(uint64_t a, uint64_t b, uint64_t n)
{
    if(n == 1) return 0;
    uint64_t rst = 1;
    for(int i = effective_bits(b) - 1; i >= 0; --i)
    {
        rst = (rst * rst) % n;
        auto nowbit_in_b = b >> i & 1ULL;
        if(nowbit_in_b == 1)
        {
            rst = (rst * a) % n;
        }
    }
    return rst;
}

void call_Euclid()
{
    int64_t a, b;
    std::cin >> a >> b;
    std::cout << Euclid(a, b) << std::endl;
}

void call_Euclid_extend()
{
    int64_t a, b; 
    std::cin >> a >> b;
    auto [d, x, y] = Euclid_extend(a, b);
    std::cout << "ax + by = gcd(a, b)" << "   "
        << "x: " << x << " " 
        << "y: " << y << " "
        << "gcd(a, b): " << d << std::endl;
}

void call_moduler_linear_equation_solver()
{
    int64_t a, b, n;
    std::cin >> a >> b >> n;
    auto results = moduler_linear_equation_solver(a, b, n);
    if(results == std::nullopt)
    {
        std::cout << "no result" << std::endl;
    }
    else 
    {
        for(auto result: results.value())
        {
            std::cout << result << " " ; 
        }
        std::cout << std::endl;
    }
}

void call_moduler_exponentiation()
{
    uint64_t a, b, n;
    std::cin >> a >> b >> n;
    std::cout << moduler_exponentiation(a, b, n) << std::endl;
}

void die()
{
    exit(1);
}

void showFunc()
{
    std::map<std::string, std::string> funcmap = {
        {"call Euclid", "euclid"},
        {"solve Bezout", "bezout"}, 
        {"solve moduler_line_equation", "mdlneq"},
        {"solve moduler_exponentiation", "mdexp"},
        {"show usable function", "showfunc"},
        {"end process", "die"}
    };
    for(auto &[func, key]: funcmap)
    {
        std::cout << func << ": " << key << std::endl;
    }
}

void callFunc()
{
    std::map<std::string, std::function<void()>> dofunc = {
        {"euclid", call_Euclid},
        {"bezout", call_Euclid_extend},
        {"mdlneq", call_moduler_linear_equation_solver},
        {"mdexp", call_moduler_exponentiation},
        {"die", die},
        {"showfunc", showFunc}
    };
    std::string name;
    std::cin >> name;
    if(dofunc.count(name) == 0)
    {
        std::cout << "no such function" << std::endl;
        return;
    }
    auto func = dofunc.at(name);
    func();
}
/*
int main()
{
    showFunc();
    while(true)
    {
        callFunc();
    }
}
*/
