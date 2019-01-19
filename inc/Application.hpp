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

class Application {
public:
    Application();
    ~Application() {};

    void setup() noexcept;
    void run();
private:
    void loadPlugins() noexcept;
    void unloadPlugins() noexcept;
    void loadPlugin(const std::string &str);
    ModuleHandler _handler;
    ModuleFactory _factory;
    bool _isRunning;
    std::vector<void *> _plugins;
};


#endif /* _APP_HPP_ */
