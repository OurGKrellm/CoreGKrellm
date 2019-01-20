/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** TextDisplay
*/

#include <sstream>
#include <iostream>
#include "Utils.hpp"
#include "ModuleFactory.hpp"
#include "TextDisplay.hpp"
#include "Widget.hpp"
#include "Selector.hpp"

TextDisplay::TextDisplay()
:     window(nullptr)
    , vectorHash(0)
    , widgets()
    , selected(-1)
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

void TextDisplay::createModule(std::vector<IMonitorModule *> &modules)
{
    std::string choosedModule = "";
    Selector<std::string> selector(ModuleFactory::getFactory()->getNames());
    timeout(-1);
    while (choosedModule.size() == 0) {
        auto i = 0;
        wclear(this->window);
        for (auto temp : ModuleFactory::getFactory()->getNames()) {
            if (selector.getSelected().compare(temp) == 0)
                wattron(this->window, COLOR_PAIR(7));
            mvwaddstr(this->window, i, 0, temp.c_str());
            if (selector.getSelected().compare(temp) == 0)
                wattroff(this->window, COLOR_PAIR(7));
            i++;
        }
        auto temp = getch();
        if (temp == 27)
            return;
        if (temp == KEY_UP)
            selector--;
        if (temp == KEY_DOWN)
            selector++;
        if (temp == 10)
            choosedModule = selector.getSelected();
    }
    try {
        modules.push_back(ModuleFactory::getFactory()->clone(choosedModule));
    } catch (const std::runtime_error &e) {
        return;
    }
    timeout(33);
    wclear(this->window);
    vectorHash = -1;
}

void TextDisplay::eventHandler(int key, std::vector<IMonitorModule *> &modules)
{
    if (key == KEY_UP) {
        this->selected = std::max(this->selected - 4, -1);
    }
    if (key == KEY_DOWN) {
        this->selected = std::min(this->selected + 4, ((int) modules.size()) - 1);
    }
    if (key == KEY_LEFT) {
        this->selected = std::max(this->selected - 1, -1);
    }
    if (key == KEY_RIGHT) {
        this->selected = std::min(this->selected + 1, ((int) modules.size()) - 1);
    }
    if (key == 330) {
        if (this->selected != -1) {
            modules.erase(modules.begin() + this->selected);
            wclear(this->window);
            vectorHash = -1;
        }
    }
    if (key == 10) {
        createModule(modules);
    }
}

IMonitorDisplay::State TextDisplay::draw(std::vector<IMonitorModule *> &modules)
{
    auto tempSelected = this->selected >= widgets.size() ? -1 : this->selected;
    if (this->vectorHash != Utils::hashVector(modules))
        this->vectorHash = remakeWidgets(modules);
    for (auto widget : widgets) {
        if (tempSelected == 0)
            widget->setSelected(true);
        widget->draw();
        if (tempSelected == 0)
            widget->setSelected(false);
        tempSelected--;
    }
    wrefresh(this->window);
    auto temp = getch();
    if (temp == 9) {
        return (IMonitorDisplay::State::SWITCH);
    }
    if (temp == 27) {
        return (IMonitorDisplay::State::QUIT);
    }
    eventHandler(temp, modules);
    return (IMonitorDisplay::State::NONE);
}

void TextDisplay::loadResources()
{
        this->window = initscr();
        cbreak();
        noecho();
        timeout(33);
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
        init_pair(7, COLOR_BLACK, COLOR_WHITE);
        wclear(this->window);
}

void TextDisplay::unloadResources()
{
    vectorHash = -1;
    endwin();
}
