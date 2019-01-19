/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** SystemInformation.hpp
*/

#ifndef CPP_RUSH3_2018_SYSTEMIFORMATION_HPP
#define CPP_RUSH3_2018_SYSTEMIFORMATION_HPP

#include "IMonitorModule.hpp"

class SystemInformation : public IMonitorModule
{
    SystemInformation();
    Content UpdateContent() override;
    std::string getContent() override;
    std::string getTitle() override;
    ModulePosition getPosititon() override;

};

#endif //CPP_RUSH3_2018_SYSTEMIFORMATION_HPP
