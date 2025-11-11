#include <cstdint>
#include <ostream>
#include <tuple>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <optional>

/**
 * Bezout_sult: 线性方程结果，tuple<gcd(a,b), x, y>
 * modLequa_sult: 模线性方程结果, vector<uint64_t>
 */
namespace mat
{
    using Bezout_sult = std::tuple<uint64_t, uint64_t, uint64_t>; 
    using modLequa_sult = std::vector<uint64_t>;
}

//递归 欧几里得 (a > b)
uint64_t Euclid(uint64_t a, uint64_t b)
{
    if(b == 0) return a;
    else return Euclid(b, a % b);
}

//递归 计算线性方程（贝组等式）的系数 (ax + by = gcd(a, b))
mat::Bezout_sult Euclid_extend(uint64_t a, uint64_t b)
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
std::optional<mat::modLequa_sult> moduler_linear_equation_solver(uint64_t a, uint64_t b, uint64_t n)
{
    mat::modLequa_sult result;
    auto Bz_rst = Euclid_extend(a, n);
    auto d = std::get<0>(Bz_rst);
    if(b % d == 0)
    {
        uint64_t x0 = std::get<1>(Bz_rst) * (b / d) % n;
        for(int i = 0; i <= d-1; ++i)
        {
            result.push_back(x0 + i * (n / d));
        }
        return result;
    }
    else
    {
        return std::nullopt;       
    }
}

void showFunc()
{
    std::map<std::string, int> funcmap = {
        {"greatest common divisor", 1},
        {"solve Bezout", 2}, 
        {"solve mod_line_equation", 3}
    };
    for(auto &[func, key]: funcmap)
    {
        std::cout << func << ": " << key << std::endl;
    }
    std::cout << "choose mode: "; 
}

int main()
{
    showFunc();
    uint64_t a, b;
    std::cin >> a >> b;
    std::cout << Euclid(a, b) << std::endl;
    auto rst = Euclid_extend(a, b); 
    std::cout << std::get<0>(rst) << std::get<1>(rst) << std::get<2>(rst) << std::endl;
}

