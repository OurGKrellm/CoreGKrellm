/*
** EPITECH PROJECT, 2019
** Application.cpp
** File description:
** Application
*/

#include <dlfcn.h>
#include <exception>
#include <filesystem>
#include <string.h>
#include "Application.hpp"

Application::Application()
    : _handler()
    , _isRunning(true)
    , _factory(ModuleFactory())
    , _plugins(std::vector<void *>())
{}

void Application::loadPlugin(const std::string &str)
{
    std::cout << "Opening " << str << " plugin." << std::endl;
    void *handle = dlopen(str.c_str(), RTLD_LAZY);

    if (!handle) {
        std::cout << dlerror() << std::endl;
        throw std::string("Cannot open plugin");
    }
    std::cout << "Loading entrypoint..." << std::endl;
    dlerror();
    entrypoint_t entrypoint = (entrypoint_t) dlsym(handle, "entrypoint");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        auto copy = std::string(dlsym_error);
        dlclose(handle);
        throw std::string("Cannot load symbol 'entrypoint': ") + copy;
    }
    std::cout << "Calling entrypoint..." << std::endl;
    entrypoint(&this->_factory);
    _plugins.push_back(handle);
}

void Application::loadPlugins() noexcept
{
    std::vector<std::string> paths;
    if (!std::filesystem::exists("./plugins"))
        std::filesystem::create_directory("./plugins");
    std::cout << "Loading plugins. ";
    for (const auto & entry : std::filesystem::directory_iterator("./plugins")) {
        if (strcmp(entry.path().extension().c_str(), ".so") == 0)
            paths.push_back(std::string(entry.path().c_str()));
    }
    std::cout << "Found " << paths.size() << " plugins." << std::endl;
    for (auto &path : paths) {
        try {
            loadPlugin(path);
        } catch (const std::string& e) {
            std::cerr << e << std::endl;
        }
    }
    std::cout << "Successfully loaded " << _plugins.size() << " plugins." << std::endl;
}

void Application::setup() noexcept
{
    loadPlugins();
    std::cout << "Info: Launching the application." << std::endl;
}

void Application::run()
{
    this->_factory.clone("test");
    while (_isRunning) {
        // How to get input.
        // How to set _isRunning to false.
        _isRunning = _handler.handle();
    }
    unloadPlugins();
}

void Application::unloadPlugins() noexcept
{
    if (this->_plugins.size() <= 0)
        return;
    std::cout << "Unloading plugins..." << std::endl;
    for (auto &handle : this->_plugins) {
        dlclose(handle);
    }
}