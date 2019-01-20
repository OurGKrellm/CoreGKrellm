/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** TextDisplay
*/

#include <sstream>
#include "Utils.hpp"
#include "ModuleFactory.hpp"
#include "TextDisplay.hpp"

TextDisplay::TextDisplay()
:     window(nullptr)
    , vectorHash(0)
    , widgets()
{
}

TextDisplay::~TextDisplay()
{
}

std::size_t TextDisplay::remakeWidgets(std::vector<IMonitorModule *> &modules)
{
    int i = 0;
    int j = 0;

    this->widgets = std::vector<Widget *>();

    for (auto temp : modules) {
        this->widgets.push_back(new Widget(temp, this->window, i, j));
        if (((i + 2) * this->widgets.back()->getWidth()) <= COLS) {
            i++;
        } else {
            i = 0;
            j++;
        }
    }
    return (Utils::hashVector(modules));
}

IMonitorDisplay::State TextDisplay::draw(std::vector<IMonitorModule *> &modules)
{
    if (this->vectorHash != Utils::hashVector(modules))
        this->vectorHash = remakeWidgets(modules);
    for (auto widget : widgets) {
        widget->draw();
    }
    auto temp = getch();
    if (temp == 259) {
        modules.push_back(ModuleFactory::getFactory()->clone("ram"));
    }
    if (temp == 9) {
        return (IMonitorDisplay::State::SWITCH);
    }
    if (temp == 27) {
        return (IMonitorDisplay::State::QUIT);
    }

    return (IMonitorDisplay::State::NONE);
}

void TextDisplay::loadResources()
{
        this->window = initscr();
        cbreak();
        noecho();
        halfdelay(3);
        curs_set(0);
        keypad(stdscr, TRUE);
        start_color();
        init_pair(0, COLOR_WHITE, COLOR_BLACK);
        init_pair(1, COLOR_RED, COLOR_RED);
        init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
        init_pair(3, COLOR_GREEN, COLOR_GREEN);
        init_pair(4, COLOR_WHITE, COLOR_RED);
        init_pair(5, COLOR_WHITE, COLOR_YELLOW);
        init_pair(6, COLOR_WHITE, COLOR_GREEN);
        wclear(this->window);
}

void TextDisplay::unloadResources()
{
    vectorHash = -1;
    endwin();
}
