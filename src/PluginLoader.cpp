/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** PluginLoader
*/

#include "PluginLoader.hpp"

PluginLoader::PluginLoader() : _plugins(std::vector<void *>())
{
}

PluginLoader::~PluginLoader()
{
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
