/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** IMonitorModule.hpp
*/

#ifndef CPP_RUSH3_2018_IMONITORMODULE_HPP
#define CPP_RUSH3_2018_IMONITORMODULE_HPP

#include <string>

typedef struct ModulePosition {
    unsigned int x;
    unsigned int y;
    unsigned int size;
} ModulePosition;

enum ContentType {
    CAMEMBERT,
    DIAGRAMME,
    TEXT,
    PERCENTAGE
};

typedef struct Content {
    ContentType contentType;
    std::string content;
} Content;

enum Modules {
    USER_INFORMATION,
    SYSTEME_INFORMATION,
    TIME,
    CPU,
    RAM,
    NETWORK
};

class IMonitorModule
{
    public:
        virtual ~IMonitorModule() = default;
        virtual void UpdateContent() = 0;
        virtual Content getContent() = 0;
        virtual std::string getTitle() = 0;
        virtual ModulePosition getPosititon() = 0;
};

#endif //CPP_RUSH3_2018_IMONITORMODULE_HPP
