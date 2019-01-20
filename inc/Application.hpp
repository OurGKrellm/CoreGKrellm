/*
** EPITECH PROJECT, 2019
** Application.hpp
** File description:
** Application
*/

#ifndef _APP_HPP_
#define _APP_HPP_

#ifdef INSTALL_PATH
#   define STR_EXPAND2(tok) #tok
#   define STR_EXPAND(tok) STR_EXPAND2(tok)
#   define INSTALL_PATH_STR STR_EXPAND(INSTALL_PATH)
#else
#   define INSTALL_PATH_STR "."
#endif

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
