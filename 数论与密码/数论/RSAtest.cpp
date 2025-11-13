#include "trywithcode.h"
#include <cstdint>
#include <functional>
#include <iostream>
#include <string>

//加密（明文，公钥对(e, n))
uint64_t encode(uint8_t M, uint64_t e, uint64_t n)
{
    return moduler_exponentiation(M, e, n); 
}

//密文（密文，私钥对(d, n)）
uint64_t decode(uint8_t C, uint64_t d, uint64_t n)
{
    return moduler_exponentiation(C, d, n);
}

void call_encode()
{
    uint8_t M;
    uint64_t e, n;
    std::cin >> e >> n;
    while (std::cin >> M) 
    {
        std::cout << encode(M, e, n);     
    } 
    std::cout << std::endl;
}

void call_decode()
{
    uint8_t C;
    uint64_t d, n;
    std::cin >> d >> n;
    while (std::cin >> C) 
    {
        std::cout << decode(C, d, n);     
    } 
    std::cout << std::endl;
}

void chooseMode()
{
    static std::map<std::string, std::function<void()>> modefunc = {
        {"encode", call_encode},
        {"decode", call_decode},
        {"die", die}
    };
    std::string mode;
    std::cin >> mode;
    auto call_mode = modefunc.at(mode);
    call_mode();
}

int main()
{
    while(true)
    {
        chooseMode();
    }
}
