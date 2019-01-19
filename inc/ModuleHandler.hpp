/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** ModuleHandler
*/

#ifndef MODULEHANDLER_HPP_
	#define MODULEHANDLER_HPP_

#include <vector>
#include <iostream>
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "GraphicDisplay.hpp"
#include "TextDisplay.hpp"

class ModuleHandler {
public:
	ModuleHandler();
	~ModuleHandler();

    void loadModule(const std::string &title);
    bool handle();
private:
    std::vector<IMonitorModule *> _modules;
    std::vector<IMonitorDisplay *> _monitors;
    IMonitorDisplay *_actualDisplay;
    int _monitorIndex;
};

#endif /* !MODULEHANDLER_HPP_ */
