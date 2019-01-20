/*
** EPITECH PROJECT, 2019
** Application.cpp
** File description:
** Application
*/

#include <exception>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include "Application.hpp"
#include "PluginLoader.hpp"

Application::Application()
    : _handler()
    , _factory(ModuleFactory())
    , _pluginLoader(PluginLoader())
    , _isRunning(true)
{}

void Application::setup() noexcept
{
    chdir(INSTALL_PATH_STR);
    std::cout << INSTALL_PATH_STR << std::endl;
    _pluginLoader.loadPlugins<ModuleFactory>(&_factory, std::string("./plugins/modules"));
    _pluginLoader.loadPlugins<ModuleHandler>(&_handler, std::string("./plugins/displayers"));
    std::cout << "Info: Launching the application." << std::endl;
}

void Application::run()
{
    while (_isRunning) {
       _isRunning = _handler.handle();
    }
    _pluginLoader.unloadPlugins();
}
