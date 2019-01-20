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
            std::cout << "test" << std::endl;
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
        _lin = static_cast<int>(value.size());

    }
        _col = nbr_line;
        _height = 400;
        _width = 200;
        _border.setSize({static_cast<float>(_width), static_cast<float>(_height)});
        _border.setFillColor({0, 0, 255});

        for (int i = 0; i < (_lin * _col); i++) {
            _rectangles.push_back(new sf::RectangleShape({2.f, 0.f}));
        }

        for (auto [text, vec]: _map) {
            _text.push_back(text);
            for (auto &elem : vec) {
                _text.push_back(elem);
            }
        }

        size_t k = 0;
        for (int j = 0; j < _lin; ++j) {
            for (int i = 0; i < _col; ++i) {
                _rectangles[k]->setSize({static_cast<float>(_width / _col - 1), static_cast<float>(_height  / (_lin) - 2 )});
                _rectangles[k]->setPosition((i * _width / _col ) + 1,  (j * _height / _lin) + 1);
                _text[k]->setPosition((i * _width / _col ) + 1,  (j * _height / _lin) + 1);
                _rectangles[k]->setFillColor({0, 0, 0});
                _text[k]->setCharacterSize(static_cast<unsigned int>(30));
                _text[k]->setFillColor({0, 255, 0});
                k++;
            }
        }
}

void Array::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_border);
    for (auto &rec : _rectangles) {
        target.draw(*rec);
    }
    for (auto &text : _text) {
        target.draw(*text);
    }
}