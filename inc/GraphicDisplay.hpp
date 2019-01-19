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

class DrawableModule : public sf::Drawable {
public:
    DrawableModule(sf::Font &font);
    DrawableModule(sf::Font &font, IMonitorModule *module);
    ~DrawableModule() = default;

    void setModule(IMonitorModule *module);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
private:
    void drawCamembert();
    void drawText();
    void drawPercentage();
    IMonitorModule *_module;
    sf::Font &_font;
};

class GraphicDisplay : public IMonitorDisplay {
public:
    GraphicDisplay();
    GraphicDisplay(unsigned int width, unsigned int height);
    ~GraphicDisplay() = default;

    IMonitorDisplay::State draw(std::vector<IMonitorModule *> &modules) final;
private:
    void handleInput();
    void update();
    void drawModules(std::vector<IMonitorModule *> &modules);

    sf::RenderWindow _window;
    sf::Event _e;
    sf::Font _globalFont;
    DrawableModule _drawableModule;
    bool _wantSwitch;
};

#endif /* !GRAPHICDISPLAY_HPP_ */
