/*
** EPITECH PROJECT, 2019
** Application.cpp
** File description:
** Application
*/

#include <exception>
#include <string.h>
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
    _pluginLoader.loadModules(&_factory);
    _pluginLoader.loadDisplayers(&_handler);
    std::cout << "Info: Launching the application." << std::endl;
}

void Application::run()
{
    while (_isRunning) {
       _isRunning = _handler.handle();
    }
    _pluginLoader.unloadPlugins();
}
