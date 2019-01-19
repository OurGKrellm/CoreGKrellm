/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** main
*/

#include <UserInformation.hpp>
#include "RamInformation.hpp"
#include <iostream>

int main()
{
    //Application app;

    auto *userInformation = new RamInformation();
    userInformation->UpdateContent();
    std::cout << userInformation->getContent().content << std::endl;
    /*app.setup();
    app.run();*/
    return 0;
}
