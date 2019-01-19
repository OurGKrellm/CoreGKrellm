/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** TopBar
*/

#include "GraphicTemplate.hpp"

TopBar::TopBar(sf::Font &font)
    : _font(font)
    , _nb(0)
    , _nbText("0", _font)
    , _bar(sf::Vector2f(800, 40))
{
    _nbText.setColor(sf::Color::Black);
}

TopBar::~TopBar()
{}

void TopBar::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_bar);
    target.draw(_nbText);
}