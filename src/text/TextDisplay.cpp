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

const int WIDGET_W = 53;
const int WIDGET_H = 17;

TextDisplay::TextDisplay()
: previousHash(0)
{
}

TextDisplay::~TextDisplay()
{
    endwin();
}


void printMultiline(WINDOW *win, int start_y, int start_x, const std::string &str)
{
    int i = 0;
    std::stringstream ss(str);
    std::string toPrint;

    while (std::getline(ss, toPrint, '\n')) {
        mvwaddstr(win, start_y + i, start_x, toPrint.c_str());
        i++;
    }
}

void printPercentage(WINDOW *win, int start_y, int start_x, const std::string &str)
{
    int percentage = std::stol(str);
    float percent_per_char = 100 / WIDGET_W;
    int char_to_print = percentage / percent_per_char;

    if (percentage < 33) {
        wattron(win, COLOR_PAIR(3));
    } else if (percentage < 66) {
        wattron(win, COLOR_PAIR(2));
    } else {
        wattron(win, COLOR_PAIR(1));
    }
    for (int i = 0; i <= percent_per_char; i++)
        mvwaddch(win, start_y, start_x + i, ' ');
    wattron(win, COLOR_PAIR(0));
}

std::size_t TextDisplay::remakeWidgets(std::vector<IMonitorModule *> &modules)
{
    int i = 0;
    int j = 0;
    for (auto &temp : this->widgets) {
        delwin(temp);
    }
    this->widgets = std::vector<WINDOW *>();
    for (auto temp : modules) {
        auto position = temp->getPosititon();
        this->widgets.push_back(subwin(this->window, WIDGET_H, WIDGET_W, position.y + (j * WIDGET_H), position.x + (i * WIDGET_W)));
        wborder(this->widgets.back(), '|', '|', '-', '-', '+', '+', '+', '+');
        if (((i + 2) * WIDGET_W) <= COLS) {
            i++;
        } else {
            i = 0;
            j++;
        }
    }
    return (Utils::hash(modules));
}

void TextDisplay::draw(IMonitorModule *module, WINDOW *window)
{
    switch (module->getContent().contentType) {
        case TEXT:
            printMultiline(window, 3, 1, module->getContent().content.c_str());
            break;
        case PERCENTAGE:
            printPercentage(window, 3, 1, module->getContent().content.c_str());
            break;
    }
}

IMonitorDisplay::State TextDisplay::draw(std::vector<IMonitorModule *> &modules)
{
    if (this->window == nullptr) {
        this->window = initscr();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        start_color();
        init_pair(0, COLOR_WHITE, COLOR_BLACK);
        init_pair(1, COLOR_RED, COLOR_RED);
        init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
        init_pair(3, COLOR_GREEN, COLOR_GREEN);
    }
    if (this->previousHash != Utils::hash(modules))
        this->previousHash = remakeWidgets(modules);
    auto module = modules.begin();
    auto win = this->widgets.begin();
    for (; module != modules.end(); module++, win++) {
        mvwaddstr(*win, 1, 1, (*module)->getTitle().c_str());
        mvwaddstr(*win, 2, 0, "+---------------------------------------------------+");
        draw(*module, *win);
        wrefresh(*win);
    }
    auto temp = getch();
    if (temp == 259) {
        modules.push_back(ModuleFactory::getFactory()->clone("ram"));
    }
    if (temp == 9) {
        endwin();
        return (IMonitorDisplay::State::SWITCH);
    }
    return (IMonitorDisplay::State::NONE);
}
