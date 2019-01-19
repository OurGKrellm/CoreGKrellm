/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** GraphicDisplay
*/

#include "GraphicDisplay.hpp"
#include "GraphicTemplate.hpp"
#include <iostream>

//-------------------- GraphicDisplay ----------------------------

GraphicDisplay::GraphicDisplay()
    : _window(new sf::RenderWindow(sf::VideoMode(800, 600), "Monitor"))
    , _e()
    , _globalFont(new sf::Font)
    , _drawableModule(*_globalFont)
    , _topBar(*_globalFont)
{
    if (_globalFont->loadFromFile("./res/deja.ttf") == false) {
        throw "Error while loading texture";
    }
}

GraphicDisplay::GraphicDisplay(unsigned int width, unsigned int height)
    : _window(nullptr)
    , _e()
    , _globalFont(new sf::Font)
    , _drawableModule(*_globalFont)
    , _topBar(*_globalFont)
{
    if (_globalFont->loadFromFile("./res/deja.ttf") == false)
        throw "Cannot load ./res/deja.tff";
}

void GraphicDisplay::handleInput()
{
    while (_window->pollEvent(_e)) {
        if (_e.type == sf::Event::Closed)
            _window->close();
        if (_e.type == sf::Event::KeyPressed) {
            if (_e.key.code == sf::Keyboard::Escape)
                _window->close();
        }
    }   
}

void GraphicDisplay::drawModules(std::vector<IMonitorModule *> &modules)
{
    _window->draw(_topBar);

    for (auto &elem: modules) {
        _drawableModule.setModule(&*elem);
        _window->draw(_drawableModule);
    }
}

// Do the graphical draw
IMonitorDisplay::State GraphicDisplay::draw(std::vector<IMonitorModule *> &modules)
{
    _window->clear();
    handleInput();
    drawModules(modules);
    _window->display();

    if (!_window->isOpen())
        return State::QUIT;
    return State::NONE;
}


//-------------------- DrawableModule --------------------------

DrawableModule::DrawableModule(sf::Font &font)
    : _module(nullptr)
    , _font(font)
{}

DrawableModule::DrawableModule(sf::Font &font, IMonitorModule *module)
    : _module(module)
    , _font(font)
{}

void DrawableModule::setModule(IMonitorModule *module)
{
    _module = module;
}

void DrawableModule::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Drawable *drawable;

    switch (_module->getContent().contentType) {
    case ContentType::CAMEMBERT:
        //drawable = new Camembert();
        break;
    case ContentType::PERCENTAGE:
        drawable = new Percentage(_module->getContent().content);
        break;
    case ContentType::TEXT:
        drawable = new sf::Text(_module->getContent().content, _font);
        break;
    default:
        drawable = new sf::Text("Error", _font);
        break;
    };
    target.draw(*drawable);
}