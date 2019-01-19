/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Percentage
*/

#include "Percentage.hpp"

Percentage::Percentage(const std::string &percent)
    : _percent(std::to_string(percent))
    , _back(sf::Vector2(100, 20))
    , _front(sf::Vector2(_percent, 20))
{
    _front.setColor(sf::Color::Green);
    _back.setColor(sf::Color::White);
}

void draw(sf::RenderTarget &target, sf::RenderStates states) const final
{
    target.draw(_back);
    target.draw(_front);
}