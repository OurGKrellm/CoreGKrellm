/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** entrypoint
*/

#include "GraphicDisplay.hpp"
#include "ModuleHandler.hpp"

extern "C" void entrypoint(ModuleHandler *handler)
{
    handler->loadDisplayer(new GraphicDisplay());
}
