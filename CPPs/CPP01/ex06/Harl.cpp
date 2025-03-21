#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

int getComplainNumber(std::string level) {
    if (level == "DEBUG")
        return 1;
    if (level == "INFO")
        return 2;
    if (level == "WARNING")
        return 3;
    if (level == "ERROR")
        return 4;
    return 0;
}

void Harl::complain(std::string level) {
    int compainNumber = getComplainNumber(level);
    switch (compainNumber)
    {
        case 1:
            debug();
            break;
        case 2:
            info();
            break;
        case 3:
            warning();
            break;
        case 4:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}

void Harl::debug() {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
