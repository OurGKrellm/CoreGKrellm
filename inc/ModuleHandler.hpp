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

class ModuleHandler {
public:
	ModuleHandler();
	~ModuleHandler();

    void loadDisplayer(IMonitorDisplay *);
    bool handle();
private:
    std::vector<IMonitorModule *> _modules;
    std::vector<IMonitorDisplay *> _monitors;
    IMonitorDisplay *_actualDisplay;
    std::size_t _monitorIndex;
};

typedef void (*entrypoint_displayer_t)(ModuleHandler *);

#endif /* !MODULEHANDLER_HPP_ */
