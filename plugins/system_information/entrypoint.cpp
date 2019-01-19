/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** entrypoint
*/

#include "ModuleFactory.hpp"
#include "SystemInformation.hpp"

extern "C" void entrypoint(ModuleFactory *factory)
{
    factory->registerModule(new SystemInformation(), std::string("system"));
}
