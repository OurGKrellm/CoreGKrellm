/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** UserInformation.hpp
*/

#ifndef CPP_RUSH3_2018_USERINFORMATION_HPP
#define CPP_RUSH3_2018_USERINFORMATION_HPP

#include "IMonitorModule.hpp"

class UserInformation : public IMonitorModule
{
    public:
        UserInformation();
        Content UpdateContent() override;
        std::string getContent() override;
        std::string getTitle() override;
        ModulePosition getPosititon() override;

    private:
        Content content;

};

#endif //CPP_RUSH3_2018_USERINFORMATION_HPP
