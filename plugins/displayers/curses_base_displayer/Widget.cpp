/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Widget
*/

#include "Widget.hpp"
#include "Utils.hpp"
#include "Drawers.hpp"
#include <iostream>

Widget::Widget(IMonitorModule *module, WINDOW *baseWindow, int posX, int posY)
 : module(module)
{
    this->window = subwin(baseWindow, WIDGET_H, WIDGET_W, posY * WIDGET_H, posX * WIDGET_W);
}

Widget::~Widget()
{
    std::cerr << "test" << std::endl;
    wclear(window);
    delwin(window);
}

void Widget::draw()
{
    std::hash<IMonitorModule> hashFn;

    if (previousHash != hashFn(*module)) {
            wclear(this->window);
            wborder(this->window, '|', '|', '-', '-', '+', '+', '+', '+');
            mvwaddstr(this->window, 1, 1, module->getTitle().c_str());
            mvwaddstr(this->window, 2, 0, "+---------------------------------------------------+");
            drawModule(module, this->window);
            wrefresh(this->window);
            previousHash = hashFn(*module);
    }
}

void Widget::drawModule(IMonitorModule *module, WINDOW *window)
{
    switch (module->getContent().contentType) {
        case TEXT:
            Drawers::printMultiline(*this, 3, 1, module->getContent().content.c_str());
            break;
        case PERCENTAGE:
            Drawers::printPercentage(*this, 7, 1, module->getContent().content.c_str());
            break;
    }
}
