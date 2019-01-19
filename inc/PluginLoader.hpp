/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** PluginLoader
*/

#ifndef PLUGINLOADER_HPP_
    #define PLUGINLOADER_HPP_

#include "ModuleFactory.hpp"
#include "ModuleHandler.hpp"

class PluginLoader {
    public:
        PluginLoader();
        ~PluginLoader();
        void loadModules(ModuleFactory *factory) noexcept;
        void loadDisplayers(ModuleHandler *handler) noexcept;
        void unloadPlugins() noexcept;

    protected:
    private:
        void loadModule(ModuleFactory *factory, const std::string &str);
        void loadDisplayer(ModuleHandler *handler, const std::string &str);
        std::vector<void *> _plugins;
};

#endif /* !PLUGINLOADER_HPP_ */
