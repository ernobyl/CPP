#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
}

void Harl::debug()
{
    std::cout << "[DEBUG] This is a debug message." << std::endl;
}

void Harl::info()
{
    std::cout << "[INFO] This is information." << std::endl;
}

void Harl::warning()
{
    std::cout << "[WARNING] You have been warned." << std::endl;
}

void Harl::error()
{
    std::cout << "[ERROR] You have failed at coding." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[] =
    {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
    };
    void (Harl::*functions[])(void) =
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            (this->*functions[i])();
    }
}