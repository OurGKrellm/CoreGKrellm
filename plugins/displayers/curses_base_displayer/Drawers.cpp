/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Utils
*/

#include <sstream>
#include <curses.h>
#include "Utils.hpp"
#include "Drawers.hpp"

void Drawers::printMultiline(const Widget &widget, int start_y, int start_x, const std::string &str)
{
    int i = 0;
    std::stringstream ss(str);
    std::string toPrint;

    while (std::getline(ss, toPrint, '\n')) {
        mvwaddstr(widget.getWindow(), start_y + i, start_x, toPrint.c_str());
        i++;
    }
}

void Drawers::printPercentage(const Widget &widget, int start_y, int start_x, const std::string &str)
{
    int percentage = std::stol(str);
    float percent_per_char = 100 / (widget.getWidth() - 4);
    int char_to_print = percentage / percent_per_char;
    int toPrintPercentage = ((widget.getWidth() - 4) / 2);
    int colorPair = 0;

    if (percentage < 33) {
        colorPair = 3;
    } else if (percentage < 66) {
        colorPair = 2;
    } else {
        colorPair = 1;
    }

    mvwaddstr(widget.getWindow(), start_y, start_x, "/-------------------------------------------------\\");
    mvwaddch(widget.getWindow(), start_y + 1, start_x, '|');
    mvwaddch(widget.getWindow(), start_y + 1, start_x + widget.getWidth() - 3, '|');
    mvwaddstr(widget.getWindow(), start_y + 2, start_x, "\\-------------------------------------------------/");
    wattron(widget.getWindow(), COLOR_PAIR(colorPair));
    for (int i = 0; i <= char_to_print; i++)
        mvwaddch(widget.getWindow(), start_y + 1, start_x + i + 1, ' ');
    wattroff(widget.getWindow(), COLOR_PAIR(colorPair));
    if (toPrintPercentage <= char_to_print)
        wattron(widget.getWindow(), COLOR_PAIR(colorPair + 3));
    mvwaddstr(widget.getWindow(), start_y + 1, start_x + toPrintPercentage, str.c_str());
    if (toPrintPercentage <= char_to_print)
        wattroff(widget.getWindow(), COLOR_PAIR(colorPair + 3));
}


void Drawers::printMultiPercentage(const Widget &widget, int start_y, int start_x, const std::string &str)
{
    int i = 0;
    std::stringstream ss(str);
    std::string toPrint;

    while (std::getline(ss, toPrint, '%')) {
        if (toPrint.size() != 0) {
            printPercentage(widget, start_y + (i * 2), start_x, toPrint.c_str());
            i++;
        }
    }
}

void Drawers::printArray(const Widget &widget, int start_y, int start_x, const std::string &str)
{
    
    mvwaddstr(widget.getWindow(), start_y, start_x, str.c_str());
}

void Drawers::printCamenbert(const Widget &widget, int start_y, int start_x, const std::string &str)
{
    printMultiline(widget, start_y, start_x, "Not implemented\nswitch to another backend !");
}
