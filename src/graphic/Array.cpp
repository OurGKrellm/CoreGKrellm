/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Array.cpp
*/

#include <vector>
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
        std::vector<sf::Text> value;

        while (from < end_line) {
            if (csv.find(',', from + 1) > end_line)
                value.push_back(sf::Text(csv.substr(from, csv.find('\n', from) - from), font));
            else
                value.push_back(sf::Text(csv.substr(from, csv.find(',', from) - from), font));
            from = csv.find(',', from + 1) + 1;
            if (from == 0)
                break;
            if (from > end_line)
                from = csv.find('\n', from);
        }
        from = end_line + 1;
        _map.push_back(std::tuple(sf::Text(name, font), value));
    }
}

void Array::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

}

void Array::move(sf::Vector2f offset)
{
}