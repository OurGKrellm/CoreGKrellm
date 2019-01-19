/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** ModuleFactory
*/

#include <iostream>
#include "ModuleFactory.hpp"

ModuleFactory *ModuleFactory::_singleton = nullptr;

ModuleFactory::ModuleFactory()
    : instances()
{
    if (_singleton == nullptr)
        _singleton = this;
}

ModuleFactory::~ModuleFactory()
{
}

bool ModuleFactory::registerModule(IMonitorModule *module, const std::string &title)
{
    if (title.size() == 0) {
        std::cerr << "Cannot register module: No name given" << std::endl;
        return false;
    }
    if (module == nullptr) {
        std::cerr << "Cannot register module " << title << ": pointer is null" << std::endl;
        return false;
    }
    for (auto &temp : this->instances) {
        if (temp.first.compare(title) == 0) {
            std::cerr << "Canno register module: " << title << ", name already registered" << std::endl;
            return false;
        }
    }
    this->instances[title] = module;
    std::cout << "Module " << title << " registered." << std::endl;
    return true;
}

IMonitorModule *ModuleFactory::clone(const std::string &title) const
{
    try {
        return this->instances.at(title)->clone();
    } catch (const std::out_of_range &e) {
        throw std::runtime_error("No such module, ALORS CA CRASH PUTAIN !");
    }
}

std::vector<std::string> ModuleFactory::getNames() const
{
    std::vector<std::string> names;
    for (auto &temp : this->instances) {
        names.push_back(temp.first);
    }
    return (names);
}

ModuleFactory *ModuleFactory::getFactory()
{
    return ModuleFactory::_singleton;
}
