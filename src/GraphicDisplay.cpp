/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** GraphicDisplay
*/

#include "GraphicDisplay.hpp"

GraphicDisplay::GraphicDisplay()
    : _window(sf::VideoMode(800, 600), "Monitor")
{}


void GraphicDisplay::draw(std::vector<IMonitorModule *> modules)
{
    // Setup Draw on modules.
}