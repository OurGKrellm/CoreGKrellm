/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Array.cpp
*/

#include "GraphicTemplate.hpp"

Array::Array(const std::string &csv, sf::Font &font)
    : _array()
{
    unsigned int csv_colonum = 0;

    for (int i = 0; csv[i] != 0 && csv[i] != '\n'; i++)
        if (csv[i] == ',')
            csv_colonum++;
}