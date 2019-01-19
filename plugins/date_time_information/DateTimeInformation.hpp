/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** DateTime.hpp, created by herbosa
*/
#ifndef CPP_RUSH3_2018_DATETIME_HPP
#define CPP_RUSH3_2018_DATETIME_HPP

#include "IMonitorModule.hpp"

class DateTimeInformation : public IMonitorModule {
public:
    DateTimeInformation();

    ~DateTimeInformation() override = default;

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

#endif //CPP_RUSH3_2018_DATETIME_HPP
