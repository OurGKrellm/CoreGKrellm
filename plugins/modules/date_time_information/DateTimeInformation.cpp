/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** DateTimeInformation.cpp, created by herbosa
*/

#include <chrono>
#include <sstream>
#include "DateTimeInformation.hpp"

DateTimeInformation::DateTimeInformation() :
_content({TEXT, ""}),
_pos({0, 0}),
_title("Date and Time Informations")
{

}

void DateTimeInformation::UpdateContent() {
    std::time_t currentTime = std::time(nullptr);
    std::stringstream str;
    str << "Current Time : " <<  std::ctime(&currentTime) << std::endl;
    _content.content = str.str();
}

Content DateTimeInformation::getContent() {
    return _content;
}

std::string DateTimeInformation::getTitle() {
    return _title;
}

ModulePosition DateTimeInformation::getPosititon() {
    return _pos;
}

IMonitorModule *DateTimeInformation::clone()
{
    return (new DateTimeInformation());
}
