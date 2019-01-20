/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** ModuleHandler
*/

#include "ModuleHandler.hpp"
#include "ModuleFactory.hpp"

ModuleHandler::ModuleHandler()
    : _modules()
    , _monitors()
    , _actualDisplay(nullptr)
    , _monitorIndex(0)
{
}

void ModuleHandler::loadDisplayer(IMonitorDisplay *display)
{
    _monitors.push_back(display);
}

ModuleHandler::~ModuleHandler()
{
}

bool ModuleHandler::handle()
{
    if (_actualDisplay == nullptr && _monitors.size() == 0)
        return false;
    else if (_actualDisplay == nullptr && _monitors.size() != 0) {
        _actualDisplay = _monitors[0];
        _actualDisplay->loadResources();
    }

    for (auto temp : _modules) {
        temp->UpdateContent();
    }

    auto state = _actualDisplay->draw(_modules);
    
    if (state == IMonitorDisplay::State::QUIT) {
        _actualDisplay->unloadResources();
        return false;
    } else if (state == IMonitorDisplay::State::SWITCH) {
        if (_monitorIndex + 1 >= _monitors.size())
            _monitorIndex = -1;
        _actualDisplay->unloadResources();
        _actualDisplay = _monitors[++_monitorIndex];
        _actualDisplay->loadResources();
    }
    return true;
}