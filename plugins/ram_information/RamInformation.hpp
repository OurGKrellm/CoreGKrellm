/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** RamInformation.hpp
*/

#ifndef CPP_RUSH3_2018_RAMINFORMATION_HPP
#define CPP_RUSH3_2018_RAMINFORMATION_HPP

#include "IMonitorModule.hpp"

class RamInformation : public  IMonitorModule
{
    public:
        RamInformation();
        ~RamInformation() override = default;
        void UpdateContent() override;
        Content getContent() override;
        std::string getTitle() override;
        ModulePosition getPosititon() override;
        IMonitorModule *clone() override;

    private:
        Content _content;
        std::string _title;
        ModulePosition _position;
        std::string _file;
};

#endif //CPP_RUSH3_2018_RAMINFORMATION_HPP
