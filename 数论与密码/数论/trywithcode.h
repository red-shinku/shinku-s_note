#ifndef TRYWITHCODE_H
#define TRYWITHCODE_H

#include <cstdint>
#include <tuple>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <optional>
#include <functional>


/**
 * Bezout_sult: 线性方程结果，tuple<gcd(a,b), x, y>
 * modLequa_sult: 模线性方程结果, vector<int64_t>
 */
namespace mat
{
    using Bezout_sult = std::tuple<int64_t, int64_t, int64_t>; 
    using modLequa_sult = std::vector<int64_t>;
}

int64_t Euclid(int64_t a, int64_t b);
mat::Bezout_sult Euclid_extend(int64_t a, int64_t b);
std::optional<mat::modLequa_sult> moduler_linear_equation_solver(int64_t a, int64_t b, int64_t n);
int effective_bits(uint64_t x);
uint64_t moduler_exponentiation(uint64_t a, uint64_t b, uint64_t n);
void die();

#endif
