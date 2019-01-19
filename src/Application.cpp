/*
** EPITECH PROJECT, 2019
** Application.cpp
** File description:
** Application
*/

#include "Application.hpp"

Application::Application()
    : _handler()
    , _isRunning(true)
{}

void Application::setup() noexcept
{
    std::cout << "Info: Launching the application." << std::endl;
}

void Application::run()
{
    while (_isRunning) {
        // How to get input.
        // How to set _isRunning to false.
        _handler.handle();
    }
}