/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** IMonitorModule.hpp
*/

#ifndef CPP_RUSH3_2018_IMONITORMODULE_HPP
#define CPP_RUSH3_2018_IMONITORMODULE_HPP

#include <string>
#include <functional>

typedef struct ModulePosition {
    unsigned int x;
    unsigned int y;
    unsigned int size;
} ModulePosition;

enum ContentType {
    CAMEMBERT,
    TEXT,
    PERCENTAGE,
    MULTI_PERCENTAGE//Format Content.content = "%25:CPU 1%34:CPU 2" -> 2 pourcentages, 25% titre 'CPU 1', 34% titre 'CPU 2'
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
        virtual IMonitorModule *clone() = 0;
};

namespace std {
    template<>
    struct hash<IMonitorModule> {
        size_t operator()(IMonitorModule &module) const {
            std::hash<std::string> hashFn;
            return hashFn(module.getContent().content);
        }
    };
}

#endif //CPP_RUSH3_2018_IMONITORMODULE_HPP
