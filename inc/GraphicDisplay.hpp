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

class GraphicDisplay : public IMonitorDisplay {
public:
	GraphicDisplay();
    GraphicDisplay(unsigned int width, unsigned int height);
	~GraphicDisplay() = default;

    bool draw(std::vector<IMonitorModule *> modules) final;
private:
    void handleInput();
    void update();
    void drawModules();

    sf::RenderWindow _window;
    int _modulesNumber;
    sf::Event _e;
};

#endif /* !GRAPHICDISPLAY_HPP_ */
