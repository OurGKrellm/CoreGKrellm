/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** ModuleHandler
*/

#include "ModuleHandler.hpp"

ModuleHandler::ModuleHandler()
    : _modules()
    , _actualDisplay(nullptr)
{}

ModuleHandler::~ModuleHandler()
{
    //TODO: Cleanup _modules.
}

void ModuleHandler::loadModule(const std::string &title)
{
    //TODO: Load Modules.
}

bool ModuleHandler::handle()
{
    if (_actualDisplay == nullptr)
        return false;

    auto state = _actualDisplay->draw(_modules);

    if (state == IMonitorDisplay::State::QUIT) {
        return false;
    } else if (state == IMonitorDisplay::State::SWITCH) {
        std::cout << "Should switch." << std::endl;
    }
    return true;
}