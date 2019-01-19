/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** RamInformation.cpp
*/

#include <sstream>
#include <fstream>
#include <iostream>
#include "RamInformation.hpp"

RamInformation::RamInformation()
    : _content({ContentType::PERCENTAGE, ""})
    , _title("Ram Information")
    , _position({0, 0, 0})
    , _file("/proc/meminfo")
{}

Content RamInformation::getContent()
{
    return _content;
}

ModulePosition RamInformation::getPosititon()
{
    return _position;
}

std::string RamInformation::getTitle()
{
    return _title;
}

void RamInformation::UpdateContent()
{
    std::string ramtotal;
    std::string ramavailable;
    unsigned int percent;

    _content.content.clear();
    std::fstream input(_file, std::ios::in);
    if (!input.good())
        throw std::runtime_error("Cannot open " + _file);
    input >> ramtotal;
    input >> ramtotal;
    input >> ramavailable;
    input >> ramavailable;
    input >> ramavailable;
    input >> ramavailable;
    input >> ramavailable;
    input >> ramavailable;
    percent = (unsigned int) ((100 * std::stol(ramavailable)) / std::stol(ramtotal));
    percent = 100 - percent;
    _content.content = std::to_string(percent);
}

IMonitorModule *RamInformation::clone()
{
    return new RamInformation();
}