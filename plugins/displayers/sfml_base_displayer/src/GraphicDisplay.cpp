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
    : _window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Monitor"))
    , _e()
    , _globalFont(new sf::Font)
    , _drawableModule(*_globalFont)
    , _topBar(*_globalFont)
{
    _window->setVisible(true);
    _window->setFramerateLimit(30);
    _window->clear();
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
    _window->setVisible(true);
    _window->setFramerateLimit(30);
    _window->clear();
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
            if (_e.key.code == sf::Keyboard::Tab)
                _wantSwitch = true;
            if (_e.key.code == sf::Keyboard::Delete && modules.size() > 0)
                modules.pop_back();
            if (_e.key.code == sf::Keyboard::D)
                _topBar.getSelector()++;
            if (_e.key.code == sf::Keyboard::A)
                _topBar.getSelector()--;
            if (_e.key.code == sf::Keyboard::Return)
                modules.push_back(ModuleFactory::getFactory()->clone(_topBar.getSelector().getSelected()));
        }
    }   
}

void GraphicDisplay::drawModules(std::vector<IMonitorModule *> &modules)
{
    _window->draw(_topBar);
    size_t index = 0;
    size_t indey = 0;
    size_t cnt = 0;
    float x = 251;
    float y = 251;

    for (auto &elem: modules) {
        _drawableModule.setup(&*elem, sf::Vector2f(x * index, y * indey + (HEIGHT / 20)));
        index++;
        if (index == 4) {
            index = 0;
            indey++;
        }
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

    _topBar.setTextContent(std::to_string(modules.size()));

    if (!_window->isOpen()) {
        return State::QUIT;
    } else if (_wantSwitch) {
        _wantSwitch = false;
        return State::SWITCH;
    }
    return State::NONE;
}

void GraphicDisplay::unloadResources()
{
    _window->setVisible(false);
}

void GraphicDisplay::loadResources()
{
    _window->setVisible(true);
}

//-------------------- DrawableModule --------------------------

DrawableModule::DrawableModule(sf::Font &font)
    : _module(nullptr)
    , _font(font)
    , _box(sf::Vector2f(250, 250))
    , _title("sample", _font)
{
    _box.setFillColor(sf::Color(0xaaaaaaff));
    _title.setColor(sf::Color::Blue);
}

DrawableModule::DrawableModule(sf::Font &font, IMonitorModule *module)
    : _module(module)
    , _font(font)
    , _box(sf::Vector2f(250, 250))
    , _title("sample", _font)
{
    _box.setFillColor(sf::Color::Green);
    _title.setColor(sf::Color::Blue);
}

void DrawableModule::setup(IMonitorModule *module, sf::Vector2f offset)
{
    _module = module;
    _title.setString(_module->getTitle());
    _title.setScale(sf::Vector2f(0.5, 0.5));
    _title.setColor(sf::Color::White);

    auto string = _module->getContent().content;

    switch (_module->getContent().contentType) {
    case ContentType::CAMEMBERT:
        //drawable = new Camembert();
        break;
    case ContentType::PERCENTAGE:
        _drawable = new Percentage(string);
        break;
    case ContentType::MULTI_PERCENTAGE:
        _drawable = new MultiPercentage(string, _font);
        break;
    case ContentType::TEXT:
        _drawable = new Text(string, _font);
        dynamic_cast<Text *>(_drawable)->getText().setColor(sf::Color::Blue);
        dynamic_cast<Text *>(_drawable)->getText().scale(sf::Vector2f(0.4, 0.4));
        break;
    case ContentType::ARRAY:
        _drawable = new Array(string, _font);
        break;
    default:
        _drawable = new Text("Error", _font);
        dynamic_cast<Text *>(_drawable)->getText().setColor(sf::Color::Blue);
        break;
    };
    _box.setPosition(offset);
    _title.setPosition(offset);
    _drawable->move(offset + sf::Vector2f(0, HEIGHT / 20));
 
}

void DrawableModule::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_box);
    target.draw(_title);
    target.draw(*_drawable);
    delete _drawable;
}