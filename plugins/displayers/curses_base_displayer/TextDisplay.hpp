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
#include "Widget.hpp"

class TextDisplay : public IMonitorDisplay {
    public:
        TextDisplay();
        ~TextDisplay();

        void loadResources() final;
        State draw(std::vector<IMonitorModule *> &modules) final;
        void unloadResources() final;

    protected:
    private:
        void createModule(std::vector<IMonitorModule *> &modules);
        std::size_t remakeWidgets(std::vector<IMonitorModule *> &modules);
        void draw(IMonitorModule *module, WINDOW *window);
        void eventHandler(int key, std::vector<IMonitorModule *> &modules);
        WINDOW *window;
        std::vector<Widget *> widgets;
        std::vector<std::size_t> previousHashes;
        std::size_t vectorHash;
        int selected;
};

#endif /* !TEXTDISPLAY_HPP_ */
