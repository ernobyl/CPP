#include "HarlFilter.hpp"
#include <iostream>

Harl::Harl()
{
}

void Harl::_debug()
{
    std::cout << "[DEBUG] This is a debug message." << std::endl;
}

void Harl::_info()
{
    std::cout << "[INFO] This is information." << std::endl;
}

void Harl::_warning()
{
    std::cout << "[WARNING] You have been warned." << std::endl;
}

void Harl::_error()
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
            this->_debug();
        case 1:
            this->_info();
        case 2:
            this->_warning();
        case 3:
            this->_error();
            break;
        default:
            std::cout << "Level not recognized." << std::endl;
            break;
    }
}