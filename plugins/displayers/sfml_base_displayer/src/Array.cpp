/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Array.cpp
*/

#include <vector>
#include <iostream>
#include "string"
#include "GraphicTemplate.hpp"

Array::Array(const std::string &csv, sf::Font &font)
    : _map()
    , _font(font)
    {
    _lin = 0;
    _col = 0;
        _posX = 25;
        _posY = 0;
        if (csv.empty())
        return ;
    unsigned int nbr_line = 0;

    for (int i = 0; csv[i]; i++)
        if (csv[i] == '\n')
            nbr_line++;
    unsigned long from = 0;
    for (unsigned int i = 0; i < nbr_line; i++) {
        std::string name = csv.substr(from, csv.find(',', from) - from);
        unsigned long end_line = csv.find('\n', from);
        from = csv.find(',', from) + 1;
        std::vector<sf::Text *> value;


        while (from < end_line) {
            if (csv.find(',', from + 1) > end_line)
                value.push_back(new sf::Text(csv.substr(from, csv.find('\n', from) - from), font));
            else
                value.push_back(new sf::Text(csv.substr(from, csv.find(',', from) - from), font));
            from = csv.find(',', from + 1) + 1;
            if (from == 0)
                break;
            if (from > end_line)
                from = csv.find('\n', from);
        }
        from = end_line + 1;
        _map.push_back(std::make_tuple(new sf::Text(name, font), value));
        _col = static_cast<int>(value.size()) + 1;
        std::cout << _lin << std::endl;
    }
    if (_col <= 0)
        return ;
        _lin = nbr_line;
        _height = 200;
        _width = 200;
        _posX = 25;
        _posY = 0;

    _border.setSize({static_cast<float>(_width), static_cast<float>(_height)});
        _border.setPosition(_posX , _posY);
        _border.setFillColor({0, 0, 255});

        for (int i = 0; i <= (_lin * _col); i++) {
            _rectangles.push_back(new sf::RectangleShape({2.f, 0.f}));
        }

        for (auto [text, vec]: _map) {
            _text.push_back(text);
            for (auto &elem : vec) {
                _text.push_back(elem);
            }
        }

        size_t k = 0;
        for (int j = 0; j <= _lin && k < _text.size(); ++j) {
            for (int i = 0; i <= _col && k < _text.size(); ++i) {
                _rectangles[k]->setSize({static_cast<float>(_width / _col - 1), static_cast<float>(_height  / (_lin) - 2 )});
                _rectangles[k]->setPosition(_posX  + (i * _width / _col ) + 1, _posY + (j * _height / _lin) + 1);
                _text[k]->setPosition(_posX  + (i * _width / _col ) + 1 + ((10 - _text[k]->getString().getSize()) * (1 / 10) * (_width / _lin)), _posY + (j * _height / _lin) + (_height / ( 3 * _lin)) );
                _rectangles[k]->setFillColor({0, 0, 0});
                _text[k]->setCharacterSize(static_cast<unsigned int>(30));
                _text[k]->setFillColor({0, 255, 0});
                _text[k]->setCharacterSize(8);
                k++;
            }
        }

    }

void Array::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (_lin <= 0)
        return ;

    target.draw(_border);
    for (auto &rec : _rectangles) {
        target.draw(*rec);
    }
    for (auto &text : _text) {
        target.draw(*text);
    }
}

void Array::move(sf::Vector2f offset)
{
    if (_lin <= 0)
        return ;

    _posX = _posX + offset.x;
    _posY = _posY + offset.y;

    size_t k = 0;
    for (int j = 0; j < _lin && k < _text.size(); ++j) {
        for (int i = 0; i < _col && k < _text.size(); ++i) {
            _border.setPosition(_posX , _posY);
            _rectangles[k]->setPosition(_posX  + (i * _width / _col ) + 1, _posY + (j * _height / _lin) + 1);
            _text[k]->setPosition(_posX  + (i * _width / _col ) + 1 + ((10 - _text[k]->getString().getSize()) *  (_width / (10 * _lin) / 2)), _posY + (j * _height / _lin) + (_height / ( 3 * _lin)) );
            k++;
        }
    }

}