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
    : _window(new sf::RenderWindow(sf::VideoMode(width, height), "Monitor"))
    , _e()
    , _globalFont(new sf::Font)
    , _drawableModule(*_globalFont)
    , _topBar(*_globalFont)
{
    if (_globalFont->loadFromFile("./res/deja.ttf") == false)
        throw "Cannot load ./res/deja.tff";
}

GraphicDisplay::~GraphicDisplay()
{
    delete _window;
    delete _globalFont;
}

void GraphicDisplay::handleInput(std::vector<IMonitorModule *> &modules)
{
    while (_window->pollEvent(_e)) {
        if (_e.type == sf::Event::Closed)
            _window->close();
        if (_e.type == sf::Event::KeyPressed) {
            if (_e.key.code == sf::Keyboard::Escape)
                _window->close();
            if (_e.key.code == sf::Keyboard::Up)
                modules.push_back(ModuleFactory::getFactory()->clone("user"));
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
    handleInput(modules);
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
    , _box(sf::Vector2f(100, 100))
    , _title("sample", _font)
{
    _title.setColor(sf::Color::Blue);
}

DrawableModule::DrawableModule(sf::Font &font, IMonitorModule *module)
    : _module(module)
    , _font(font)
    , _box(sf::Vector2f(100, 100))
    , _title("sample", _font)
{
    _title.setColor(sf::Color::Blue);
}

void DrawableModule::setModule(IMonitorModule *module)
{
    _module = module;
    _title.setString(_module->getTitle());
}

void DrawableModule::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Drawable *drawable;
    auto strin = _module->getContent().content;

    switch (_module->getContent().contentType) {
    case ContentType::CAMEMBERT:
        //drawable = new Camembert();
        break;
    case ContentType::PERCENTAGE:
        drawable = new Percentage(strin);
        break;
    case ContentType::TEXT:
        std::cout << strin << std::endl;
        drawable = new sf::Text(strin, _font);
        break;
    case ContentType::ARRAY:
        //drawable = new Array(strin, _font);
        break;
    default:
        drawable = new sf::Text("Error", _font);
        break;
    };
    target.draw(*drawable);
    delete drawable;
}