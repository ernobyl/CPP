#include "HarlFilter.hpp"
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
    int levelIndex = -1;
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            levelIndex = i;
            break;
        }
    }
    switch (levelIndex)
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        default:
            std::cout << "Level not recognized." << std::endl;
            break;
    }
}