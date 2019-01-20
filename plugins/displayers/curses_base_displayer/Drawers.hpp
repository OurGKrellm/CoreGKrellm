/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Utils
*/

#ifndef DRAWERS_HPP_
    #define DRAWERS_HPP_

#include <curses.h>
#include "Widget.hpp"

class Drawers {
    public:
        static void printMultiline(const Widget &widget, int start_y, int start_x, const std::string &str);
        static void printPercentage(const Widget &widget, int start_y, int start_x, const std::string &str);
        static void printMultiPercentage(const Widget &widget, int start_y, int start_x, const std::string &str);
        static void printArray(const Widget &widget, int start_y, int start_x, const std::string &str);
        static void printCamenbert(const Widget &widget, int start_y, int start_x, const std::string &str);
};

#endif /* !DRAWERS_HPP_ */
