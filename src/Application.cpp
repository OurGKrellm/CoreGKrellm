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
