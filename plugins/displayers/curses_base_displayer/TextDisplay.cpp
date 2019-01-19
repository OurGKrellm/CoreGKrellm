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
:     window(nullptr)
    , vectorHash(0)
{
}

TextDisplay::~TextDisplay()
{
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
    float percent_per_char = 100 / (WIDGET_W - 4);
    int char_to_print = percentage / percent_per_char;
    int toPrintPercentage = ((WIDGET_W - 4) / 2);
    int colorPair = 0;

    if (percentage < 33) {
        colorPair = 3;
    } else if (percentage < 66) {
        colorPair = 2;
    } else {
        colorPair = 1;
    }

    mvwaddstr(win, start_y, start_x, "/-------------------------------------------------\\");
    mvwaddch(win, start_y + 1, start_x, '|');
    mvwaddch(win, start_y + 1, start_x + WIDGET_W - 3, '|');
    mvwaddstr(win, start_y + 2, start_x, "\\-------------------------------------------------/");
    wattron(win, COLOR_PAIR(colorPair));
    for (int i = 0; i <= char_to_print; i++)
        mvwaddch(win, start_y + 1, start_x + i + 1, ' ');
    wattroff(win, COLOR_PAIR(colorPair));
    if (toPrintPercentage <= char_to_print)
        wattron(win, COLOR_PAIR(colorPair + 3));
    mvwaddstr(win, start_y + 1, start_x + toPrintPercentage, str.c_str());
    if (toPrintPercentage <= char_to_print)
        wattroff(win, COLOR_PAIR(colorPair + 3));
}

std::size_t TextDisplay::remakeWidgets(std::vector<IMonitorModule *> &modules)
{
    int i = 0;
    int j = 0;
    for (auto &temp : this->widgets) {
        wclear(temp);
        delwin(temp);
    }
    this->widgets = std::vector<WINDOW *>();
    for (auto temp : modules) {
        auto position = temp->getPosititon();
        this->widgets.push_back(subwin(this->window, WIDGET_H, WIDGET_W, position.y + (j * WIDGET_H), position.x + (i * WIDGET_W)));
        if (((i + 2) * WIDGET_W) <= COLS) {
            i++;
        } else {
            i = 0;
            j++;
        }
    }
    this->previousHashes.assign(modules.size(), 0);
    return (Utils::hashVector(modules));
}

void TextDisplay::draw(IMonitorModule *module, WINDOW *window)
{
    switch (module->getContent().contentType) {
        case TEXT:
            printMultiline(window, 3, 1, module->getContent().content.c_str());
            break;
        case PERCENTAGE:
            printPercentage(window, 7, 1, module->getContent().content.c_str());
            break;
    }
}

IMonitorDisplay::State TextDisplay::draw(std::vector<IMonitorModule *> &modules)
{
    if (this->vectorHash != Utils::hashVector(modules))
        this->vectorHash = remakeWidgets(modules);
    std::hash<IMonitorModule> hashFn;
    for (std::size_t i = 0; i < modules.size(); i++) {
        if (this->previousHashes.at(i) != hashFn(*modules.at(i))) {
            wclear(this->widgets.at(i));
            wborder(this->widgets.at(i), '|', '|', '-', '-', '+', '+', '+', '+');
            mvwaddstr(this->widgets.at(i), 1, 1, modules.at(i)->getTitle().c_str());
            mvwaddstr(this->widgets.at(i), 2, 0, "+---------------------------------------------------+");
            draw(modules.at(i), this->widgets.at(i));
            wrefresh(this->widgets.at(i));
            this->previousHashes.at(i) = hashFn(*modules.at(i));
        }
    }
    auto temp = getch();
    if (temp == 259) {
        modules.push_back(ModuleFactory::getFactory()->clone("ram"));
    }
    if (temp == 258) {
        delete modules.back();
        modules.pop_back();
    }
    if (temp == 9) {
        endwin();
        return (IMonitorDisplay::State::SWITCH);
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
}

void TextDisplay::unloadResources()
{
    vectorHash = 0;
    endwin();
}
