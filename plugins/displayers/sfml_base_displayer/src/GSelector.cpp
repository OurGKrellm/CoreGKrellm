/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** GSelector
*/

#include "GSelector.hpp"

GSelector::GSelector(std::vector<std::string> datas, sf::Font &font)
    : _selected(datas[0], font)
    , _selector(datas)
{
    _selected.setPosition(400, 5);
    _selected.setColor(sf::Color::Black);
}

void GSelector::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_selected);
}
