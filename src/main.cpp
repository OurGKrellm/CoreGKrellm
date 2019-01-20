#include <string>

/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** main
*/

#include <iostream>
#include <zconf.h>
#include "../plugins/processor_information/ProcessorInformation.hpp"

int main()
{
    //Application app;
    auto a = ProcessorInformation();

    while (1) {
        a.UpdateContent();

        std::cout << a.getContent().content << std::endl;
        usleep(1000000);
    }
    //app.setup();
    //app.run();
    return 0;
}
