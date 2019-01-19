/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** GraphicDisplay
*/

#include "GraphicDisplay.hpp"


//-------------------- GraphicDisplay ----------------------------

GraphicDisplay::GraphicDisplay()
    : _window(sf::VideoMode(800, 600), "Monitor")
    , _e()
    , _drawableModule()
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

void GraphicDisplay::drawModules(std::vector<IMonitorModule *> &modules)
{
    for (auto &elem: modules) {
        _drawableModule.setModule(&*elem);
        _window.draw(_drawableModule);
    }
}

// Do the graphical draw
IMonitorDisplay::State GraphicDisplay::draw(std::vector<IMonitorModule *> &modules)
{
    _window.clear();

    handleInput();
    update();

    drawModules(modules);

    _window.display();

    if (_window.isOpen())
        return State::NONE;
    else
        return State::QUIT;
}


//-------------------- DrawableModule --------------------------

DrawableModule::DrawableModule()
    : _module(nullptr)
{}

DrawableModule::DrawableModule(IMonitorModule *module)
    : _module(module)
{}

void DrawableModule::setModule(IMonitorModule *module)
{
    _module = module;
}

void DrawableModule::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    switch (_module->getContent().contentType) {
    case :
    };
}