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
	~GraphicDisplay() = default;

    void draw(std::vector<IMonitorModule *> modules) final;
private:
    sf::RenderWindow _window;
    int _modulesNumber;
};

#endif /* !GRAPHICDISPLAY_HPP_ */
