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
 , isSelected(false)
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

    if (previousHash != hashFn(*this->module)) {
            wclear(this->window);
            if (isSelected)
                wattron(this->window, COLOR_PAIR(4));
            wborder(this->window, '|', '|', '-', '-', '+', '+', '+', '+');
            mvwaddstr(this->window, 2, 0, "+---------------------------------------------------+");
            if (isSelected)
                wattroff(this->window, COLOR_PAIR(4));
            mvwaddstr(this->window, 1, 1, module->getTitle().c_str());
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
        case MULTI_PERCENTAGE:
            Drawers::printMultiPercentage(*this, 3, 1, module->getContent().content.c_str());
            break;
        case CAMEMBERT:
            Drawers::printCamenbert(*this, 3, 1, module->getContent().content.c_str());
            break;
        case ARRAY:
            Drawers::printArray(*this, 3, 1, module->getContent().content.c_str());
            break;
    }
}

void Widget::setSelected(bool isSelected)
{
    this->isSelected = isSelected;
    this->previousHash = 0;
}