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
public:
    SystemInformation();
    ~SystemInformation() override = default;
    void UpdateContent() override;
    Content getContent() override;
    std::string getTitle() override;
    ModulePosition getPosititon() override;
    IMonitorModule *clone() override;
private:
    Content _content;
    std::string _title;
    ModulePosition _pos;
};

#endif //CPP_RUSH3_2018_SYSTEMIFORMATION_HPP
