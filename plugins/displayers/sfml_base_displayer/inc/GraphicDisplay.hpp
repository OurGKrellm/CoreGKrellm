/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** GraphicDisplay
*/

#ifndef GRAPHICDISPLAY_HPP_
    #define GRAPHICDISPLAY_HPP_

#include "IMonitorDisplay.hpp"
#include <SFML/Graphics.hpp>
#include "GraphicTemplate.hpp"
#include "ModuleFactory.hpp"
#include "Selector.hpp"
#include <memory>

class DrawableModule : public sf::Drawable {
public:
    DrawableModule(sf::Font &font);
    DrawableModule(sf::Font &font, IMonitorModule *module);
    ~DrawableModule() = default;

    void setup(IMonitorModule *module, sf::Vector2f offset);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
private:
    IMonitorModule *_module;
    sf::Font &_font;
    sf::RectangleShape _box;
    sf::Text _title;
    IEntity *_drawable;
};

class GraphicDisplay : public IMonitorDisplay {
public:
    GraphicDisplay();
    GraphicDisplay(unsigned int width, unsigned int height);
    ~GraphicDisplay();

    void loadResources() final;
    void unloadResources() final;
    IMonitorDisplay::State draw(std::vector<IMonitorModule *> &modules) final;
private:
    void handleInput(std::vector<IMonitorModule *> &modules);
    void update();
    void drawModules(std::vector<IMonitorModule *> &modules);

    sf::RenderWindow *_window;
    sf::Event _e;
    sf::Font *_globalFont;
    DrawableModule _drawableModule;
    TopBar _topBar;
    bool _wantSwitch;
};

#endif /* !GRAPHICDISPLAY_HPP_ */
