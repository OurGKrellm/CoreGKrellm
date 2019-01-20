/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** PluginLoader
*/

#ifndef PLUGINLOADER_HPP_
    #define PLUGINLOADER_HPP_

#include <dlfcn.h>
#include <filesystem>
#include <cstring>
#include "ModuleFactory.hpp"
#include "ModuleHandler.hpp"

class PluginLoader {
    public:
        PluginLoader();
        ~PluginLoader();

        void unloadPlugins() noexcept;

        template<typename T>
        void loadPlugins(T *handler, const std::string &path) noexcept
        {
            std::vector<std::string> paths;
            if (!std::filesystem::exists(path))
                std::filesystem::create_directories(path);
            std::cout << "Loading plugins. ";
            for (const auto & entry : std::filesystem::directory_iterator(path)) {
                if (strcmp(entry.path().extension().c_str(), ".so") == 0)
                    paths.push_back(std::string(entry.path().c_str()));
            }
            std::cout << "Found " << paths.size() << " plugins." << std::endl;
            for (auto &path : paths) {
                try {
                    loadPlugin<T>(handler, path);
                } catch (const std::string& e) {
                    std::cerr << e << std::endl;
                }
            }
        }

    protected:
    private:

        template<typename T>
        void loadPlugin(T *handler, const std::string &str)
        {
            std::cout << "Opening " << str << " plugin." << std::endl;
            void *handle = dlopen(str.c_str(), RTLD_LAZY);

            if (!handle) {
                throw std::string("Cannot open plugin");
            }
            std::cout << "Loading entrypoint..." << std::endl;
            dlerror();
            void (*entrypoint)(T*) = (void (*)(T*)) dlsym(handle, "entrypoint");
            const char *dlsym_error = dlerror();
            if (dlsym_error) {
                auto copy = std::string(dlsym_error);
                dlclose(handle);
                throw std::string("Cannot load symbol 'entrypoint': ") + copy;
            }
            entrypoint(handler);
            _plugins.push_back(handle);
        }
        std::vector<void *> _plugins;
};

#endif /* !PLUGINLOADER_HPP_ */
