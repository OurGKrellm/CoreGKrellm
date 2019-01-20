/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** GraphDrawer.cpp, created by herbosa
*/

#include <SFML/Graphics/RenderWindow.hpp>
#include "GraphDrawer.hpp"


void GraphDrawer::PrintNewData(int perc, sf::RenderWindow &window) {
    _rectangles[_offset]->setSize({2.f, static_cast<float>(perc * _height / 100) > _height
                                        ? _height : static_cast<float>(perc * _height / 100)});
    _rectangles[_offset]->setFillColor({static_cast<sf::Uint8>(200 - perc),
                                        static_cast<sf::Uint8>(100 + perc), 0});
    _rectangles[_offset]->setPosition({static_cast<float>(_posX + _offset * 2) ,
                                       _posY +  _height - _rectangles[_offset]->getSize().y});
    window.draw(_border);
    for (auto &_rectangle : _rectangles)
        window.draw(*_rectangle);
    if (_offset * 2 < _width )
        _offset += 1;
    else {
        for (auto &_rectangle : _rectangles)
            _rectangle->setPosition(0.f, 0.f);
        _offset = 0;
    }
}
