/*
** EPITECH PROJECT, 2019
** Application.hpp
** File description:
** Application
*/

#ifndef _APP_HPP_
#define _APP_HPP_

#include <vector>
#include <iostream>
#include "ModuleHandler.hpp"

class Application {
public:
    Application();
    ~Application() = default;

    void setup() noexcept;
    void run();
private:
    ModuleHandler _handler;
    bool _isRunning;
};

#endif /* _APP_HPP_ */
