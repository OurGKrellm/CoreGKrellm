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

GraphicDisplay::GraphicDisplay(unsigned int width, unsigned int height)
    : _window(sf::VideoMode(width, height), "Monitor")
{}

void GraphicDisplay::handleInput()
{
    while (_window.pollEvent(_e)) {
        if (_e.type == sf::Event::Closed)
            _window.close();
    }   
}

void GraphicDisplay::update()
{

}

void GraphicDisplay::drawModules()
{
}

// Do the graphical draw
bool GraphicDisplay::draw(std::vector<IMonitorModule *> modules)
{
    _window.clear();

    handleInput();
    update();

    drawModules();

    _window.display();

    if (_window.isOpen())
        return true;
    else
        return false;
}