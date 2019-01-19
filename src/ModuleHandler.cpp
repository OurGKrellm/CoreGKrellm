/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** ModuleHandler
*/

#include "ModuleHandler.hpp"

ModuleHandler::ModuleHandler()
    : _modules()
{}

ModuleHandler::~ModuleHandler()
{
    //TODO: Cleanup _modules.
}

void ModuleHandler::loadModule(const std::string &title)
{
    //TODO: Load Modules.
}

void ModuleHandler::handle()
{
    for (auto &elem: _modules) {
        _actualDisplay->draw(elem);
    }
}