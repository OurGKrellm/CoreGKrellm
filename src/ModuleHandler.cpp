/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** ModuleHandler
*/

#include "ModuleHandler.hpp"

ModuleHandler::ModuleHandler()
    : _modules()
    , _monitors{new GraphicDisplay(), new TextDisplay()}
    , _actualDisplay(_monitors[0])
    , _monitorIndex(0)
{
}

ModuleHandler::~ModuleHandler()
{
    for (auto &elem: _monitors) {
        delete elem;
    }
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
        if (_monitorIndex + 1 >= _monitors.size())
            _monitorIndex = -1;
        _actualDisplay = _monitors[++_monitorIndex];
    }
    return true;
}