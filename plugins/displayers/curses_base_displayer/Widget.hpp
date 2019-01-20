/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Widget
*/

#ifndef WIDGET_HPP_
    #define WIDGET_HPP_

#include <curses.h>
#include "IMonitorModule.hpp"


class Widget {
    public:
        Widget(IMonitorModule *module, WINDOW *baseWindow, int posX, int posY);
        ~Widget();

        int getWidth() const { return WIDGET_W; }
        int getHeigth() const { return WIDGET_H; }
        WINDOW *getWindow() const { return window; }
        void setSelected(bool isSelected);

        void draw();

    protected:
    private:
        void drawModule(IMonitorModule *module, WINDOW *window);
        WINDOW *window;
        std::size_t previousHash;
        IMonitorModule *module;
        bool isSelected;
        const static int WIDGET_W = 53;
        const static int WIDGET_H = 17;
};

#endif /* !WIDGET_HPP_ */
