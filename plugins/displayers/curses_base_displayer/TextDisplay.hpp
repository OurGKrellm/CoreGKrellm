/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** TextDisplay
*/

#ifndef TEXTDISPLAY_HPP_
    #define TEXTDISPLAY_HPP_

#include <curses.h>
#include "IMonitorDisplay.hpp"

class TextDisplay : public IMonitorDisplay {
    public:
        TextDisplay();
        ~TextDisplay();

        State draw(std::vector<IMonitorModule *> &modules) final;

    protected:
    private:
        std::size_t remakeWidgets(std::vector<IMonitorModule *> &modules);
        void draw(IMonitorModule *module, WINDOW *window);
        WINDOW *window;
        std::vector<WINDOW *> widgets;
        std::vector<std::size_t> previousHashes;
        std::size_t vectorHash;
};

#endif /* !TEXTDISPLAY_HPP_ */
