/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** IMonitorDisplay.hpp, created by herbosa
*/
#ifndef CPP_RUSH3_2018_IMONITORDISPLAY_HPP
#define CPP_RUSH3_2018_IMONITORDISPLAY_HPP

#include "IMonitorModule.hpp"
#include <vector>

class IMonitorDisplay {
public:
    enum State {
        QUIT,
        SWITCH,
        NONE
    };

    virtual ~IMonitorDisplay() = default;
    virtual void loadResources() = 0;
    virtual State draw(std::vector<IMonitorModule *> &modules) = 0;
    virtual void unloadResources() = 0;
};

#endif //CPP_RUSH3_2018_IMONITORDISPLAY_HPP
