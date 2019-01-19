/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** IMonitorDisplay.hpp, created by herbosa
*/
#ifndef CPP_RUSH3_2018_IMONITORDISPLAY_HPP
#define CPP_RUSH3_2018_IMONITORDISPLAY_HPP

class IMonitorDisplay {
public:
    virtual ~IMonitorDisplay() = 0;
    virtual void draw(IMonitorModule *module) = 0;
};

#endif //CPP_RUSH3_2018_IMONITORDISPLAY_HPP
