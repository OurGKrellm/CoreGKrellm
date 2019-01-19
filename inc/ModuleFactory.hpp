/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** ModuleFactory
*/

#ifndef MODULEFACTORY_HPP_
    #define MODULEFACTORY_HPP_

#include <map>
#include <vector>
#include "IMonitorModule.hpp"

class ModuleFactory {
    public:
        ModuleFactory();
        ~ModuleFactory();
        bool registerModule(IMonitorModule *, const std::string &title);
        IMonitorModule *clone(const std::string &title) const;
        std::vector<std::string> getNames() const;
        static ModuleFactory *getFactory();

    private:
        static ModuleFactory *_singleton;
        std::map<std::string, IMonitorModule *> instances;
};

typedef void (*entrypoint_module_t)(ModuleFactory *);

#endif /* !MODULEFACTORY_HPP_ */
