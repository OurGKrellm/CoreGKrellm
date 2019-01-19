/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** GraphicDisplay
*/

#include "GraphicDisplay.hpp"
#include "GraphicTemplate.hpp"

//-------------------- GraphicDisplay ----------------------------

GraphicDisplay::GraphicDisplay()
    : _window(sf::VideoMode(800, 600), "Monitor")
    , _e()
    , _globalFont()
    , _drawableModule(_globalFont)
{
    if (_globalFont.loadFromFile("res/deja.ttf") == false)
        throw std::exception();
}

GraphicDisplay::GraphicDisplay(unsigned int width, unsigned int height)
    : _window(sf::VideoMode(width, height), "Monitor")
    , _e()
    , _globalFont()
    , _drawableModule(_globalFont)
{}

void GraphicDisplay::handleInput()
{
    while (_window.pollEvent(_e)) {
        if (_e.type == sf::Event::Closed)
            _window.close();
        if (_e.type == sf::Event::KeyPressed) {
            if (_e.key.code == sf::Keyboard::Tab)
                _wantSwitch = true;
            if (_e.key.code == sf::Keyboard::Escape)
                _window.close();
        }
    }   
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
    drawModules(modules);
    _window.display();

    if (!_window.isOpen()) {
        return State::QUIT;
    } else if (_wantSwitch) {
        _wantSwitch = false;
        return State::SWITCH;
    }
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