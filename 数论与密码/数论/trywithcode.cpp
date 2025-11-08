#include <cstdint>
#include <tuple>
#include <vector>
#include <iostream>
#include <optional>

/**
 * Bezout_sult: 线性方程结果，<gcd(a,b), x, y>
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
    else Euclid(b, a % b);
}

//递归 计算线性方程（贝组等式）的系数 (ax + by = gcd(a, b))
mat::Bezout_sult Euclid_extend(uint64_t a, uint64_t b, mat::Bezout_sult rst = std::make_tuple(0, 0, 0))
{
    if(b == 0)
    {
        std::get<0>(rst) = a;
        std::get<1>(rst) = 1;
        std::get<2>(rst) = 0;
    }
    else
    {
        rst = Euclid_extend(b, a % b, rst);
        auto _x = std::get<1>(rst);
        auto _y = std::get<2>(rst);
        std::get<1>(rst) = _y;
        std::get<2>(rst) = _x - (a / b) * _y;
        return rst; 
    }
}

//求模线性方程的解
std::optional<mat::modLequa_sult> moduler_linear_equation_solver(uint64_t a, uint64_t b, uint64_t n)
{
    mat::modLequa_sult result;
    auto Bz_rst = Euclid_extend(a, b);
    auto d = std::get<0>(Bz_rst);
    if(d % b == 0)
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

