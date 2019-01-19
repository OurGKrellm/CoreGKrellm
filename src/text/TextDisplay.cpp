/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** TextDisplay
*/

#include "Utils.hpp"
#include "TextDisplay.hpp"

TextDisplay::TextDisplay()
: previousHash(0)
{
    this->window = initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
}

TextDisplay::~TextDisplay()
{
    endwin();
}


std::size_t TextDisplay::remakeWidgets(std::vector<IMonitorModule *> &modules)
{
    for (auto temp : this->widgets) {
        free(temp);
    }
    this->widgets = std::vector<WINDOW *>();
    for (auto temp : modules) {
        auto position = temp->getPosititon();
        this->widgets.push_back(subwin(this->window, position.size / 2.5, position.size, position.y, position.x));
        wborder(this->widgets.back(), '|', '|', '-', '-', '+', '+', '+', '+');
    }
    return (Utils::hash(modules));
}

IMonitorDisplay::State TextDisplay::draw(std::vector<IMonitorModule *> &modules)
{
    if (this->previousHash != Utils::hash(modules))
        this->previousHash = remakeWidgets(modules);
    auto module = modules.begin();
    auto win = this->widgets.begin();
    for (; module != modules.end(); module++, win++) {
        waddstr(*win, (*module)->getContent().content.c_str());
    }
    refresh();
    return (IMonitorDisplay::State::NONE);
}