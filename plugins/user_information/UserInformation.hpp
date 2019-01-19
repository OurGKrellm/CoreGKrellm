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
        ~UserInformation() override = default;
        void UpdateContent() override;
        Content getContent() override;
        std::string getTitle() override;
        ModulePosition getPosititon() override;
        IMonitorModule *clone() override;

    private:
        Content _content;
        std::string _title;
        ModulePosition _position;

};

#endif //CPP_RUSH3_2018_USERINFORMATION_HPP
