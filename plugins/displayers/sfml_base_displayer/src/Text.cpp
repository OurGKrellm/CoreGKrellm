/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Text
*/

#include "GraphicTemplate.hpp"

Text::Text(const std::string &content, sf::Font &font)
    : _font(font)
    , _text(content, _font)
{}

void Text::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_text);
}

void Text::move(sf::Vector2f offset)
{
    _text.move(offset);
}