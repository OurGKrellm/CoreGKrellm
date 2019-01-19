/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** ModuleHandler
*/

#ifndef MODULEHANDLER_HPP_
	#define MODULEHANDLER_HPP_

#include <vector>
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class ModuleHandler {
public:
	ModuleHandler();
	~ModuleHandler();

    void loadModule(const std::string &title);
    void handle();
private:
    std::vector<IMonitorModule *> _modules;
    std::vector<IMonitorDisplay *> _monitors;
    IMonitorDisplay *_actualDisplay;
};

#endif /* !MODULEHANDLER_HPP_ */
