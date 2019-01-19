/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** PluginLoader
*/

#include <dlfcn.h>
#include <filesystem>
#include <cstring>
#include "PluginLoader.hpp"

PluginLoader::PluginLoader() : _plugins(std::vector<void *>())
{
}

PluginLoader::~PluginLoader()
{
}

void PluginLoader::loadModule(ModuleFactory *factory, const std::string &str)
{
    std::cout << "Opening " << str << " module." << std::endl;
    void *handle = dlopen(str.c_str(), RTLD_LAZY);

    if (!handle) {
        throw std::string("Cannot open module");
    }
    std::cout << "Loading entrypoint..." << std::endl;
    dlerror();
    entrypoint_module_t entrypoint = (entrypoint_module_t) dlsym(handle, "entrypoint");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        auto copy = std::string(dlsym_error);
        dlclose(handle);
        throw std::string("Cannot load symbol 'entrypoint': ") + copy;
    }
    entrypoint(factory);
    _plugins.push_back(handle);
}

void PluginLoader::loadModules(ModuleFactory *factory) noexcept
{
    std::vector<std::string> paths;
    if (!std::filesystem::exists("./plugins/modules"))
        std::filesystem::create_directories("./plugins/modules");
    std::cout << "Loading module. ";
    for (const auto & entry : std::filesystem::directory_iterator("./plugins/modules")) {
        if (strcmp(entry.path().extension().c_str(), ".so") == 0)
            paths.push_back(std::string(entry.path().c_str()));
    }
    std::cout << "Found " << paths.size() << " modules." << std::endl;
    for (auto &path : paths) {
        try {
            loadModule(factory, path);
        } catch (const std::string& e) {
            std::cerr << e << std::endl;
        }
    }
    std::cout << "Successfully loaded " << _plugins.size() << " modules." << std::endl;
}

void PluginLoader::loadDisplayer(ModuleHandler *handler, const std::string &str)
{
    std::cout << "Opening " << str << " displayer." << std::endl;
    void *handle = dlopen(str.c_str(), RTLD_LAZY);

    if (!handle) {
        throw std::string("Cannot open displayer");
    }
    std::cout << "Loading entrypoint..." << std::endl;
    dlerror();
    entrypoint_displayer_t entrypoint = (entrypoint_displayer_t) dlsym(handle, "entrypoint");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        auto copy = std::string(dlsym_error);
        dlclose(handle);
        throw std::string("Cannot load symbol 'entrypoint': ") + copy;
    }
    entrypoint(handler);
    _plugins.push_back(handle);
}

void PluginLoader::loadDisplayers(ModuleHandler *handler) noexcept
{
    std::vector<std::string> paths;
    if (!std::filesystem::exists("./plugins/displayers"))
        std::filesystem::create_directories("./plugins/displayers");
    std::cout << "Loading displayer. ";
    for (const auto & entry : std::filesystem::directory_iterator("./plugins/displayers")) {
        if (strcmp(entry.path().extension().c_str(), ".so") == 0)
            paths.push_back(std::string(entry.path().c_str()));
    }
    std::cout << "Found " << paths.size() << " displayers." << std::endl;
    for (auto &path : paths) {
        try {
            loadDisplayer(handler, path);
        } catch (const std::string& e) {
            std::cerr << e << std::endl;
        }
    }
    std::cout << "Successfully loaded " << _plugins.size() << " displayers." << std::endl;
}

void PluginLoader::unloadPlugins() noexcept
{
    if (this->_plugins.size() <= 0)
        return;
    std::cout << "Unloading " << this->_plugins.size() << " plugins..." << std::endl;
    for (auto &handle : this->_plugins) {
        dlclose(handle);
    }
}
