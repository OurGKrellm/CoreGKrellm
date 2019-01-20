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
#include "ModuleFactory.hpp"
#include "PluginLoader.hpp"

class Application {
public:
    Application();
    ~Application() {};

    void setup() noexcept;
    void run();
private:
    ModuleHandler _handler;
    ModuleFactory _factory;
    PluginLoader _pluginLoader;
    bool _isRunning;
};


#endif /* _APP_HPP_ */
