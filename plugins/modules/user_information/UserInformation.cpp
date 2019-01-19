/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** UserInformation.cpp
*/

#include <exception>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include "UserInformation.hpp"

UserInformation::UserInformation()
    : _content({ContentType::TEXT, ""})
    , _title("User Information")
    , _position({0, 0, 0})
{}

std::string UserInformation::getTitle()
{
    return _title;
}

Content UserInformation::getContent()
{
    return _content;
}

ModulePosition UserInformation::getPosititon()
{
    return _position;
}

void UserInformation::UpdateContent()
{
    char *username;
    std::stringstream hostname;

    _content.content.clear();
    std::fstream input("/etc/hostname", std::ios::in);
    if (!input.good())
        throw std::runtime_error("Cannot open /etc/hostname");
    hostname << input.rdbuf();
    username = std::getenv("USER");
    if (username == nullptr)
        throw std::runtime_error("Cannot get user env variable.");
    _content.content += username;
    _content.content += "@";
    _content.content += hostname.str();
}

IMonitorModule *UserInformation::clone()
{
    return new UserInformation();
}