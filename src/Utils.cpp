/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Utils
*/

#include "Utils.hpp"

std::size_t hash(std::vector<IMonitorModule *> const &modules)
{
    std::size_t seed = modules.size();
    for(auto& i : modules) {
        seed ^= ((std::size_t) i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
}