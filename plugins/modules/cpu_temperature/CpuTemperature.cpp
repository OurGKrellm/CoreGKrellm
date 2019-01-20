/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** CpuTemperatur.cpp
*/


#include <exception>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include "CpuTemperature.hpp"

CpuTemperature::CpuTemperature()
    : _content({ContentType::PERCENTAGE, ""})
    , _title("CPU Temperature")
    , _position({0, 0, 0})
{}

std::string CpuTemperature::getTitle()
{
    return _title;
}

Content CpuTemperature::getContent()
{
    return _content;
}

ModulePosition CpuTemperature::getPosititon()
{
    return _position;
}

void CpuTemperature::UpdateContent()
{
    std::stringstream temp;
    int temperature;

    _content.content.clear();
    std::fstream input("/sys/class/thermal/thermal_zone0/temp", std::ios::in);
    if (!input.good())
        throw std::runtime_error("Cannot open /sys/class/thermal/thermal_zone0/temp");
    temp << input.rdbuf();
    temperature = (int) (std::stol(temp.str()) / 1000);
    _content.content += std::to_string(temperature);
}

IMonitorModule *CpuTemperature::clone()
{
    return new CpuTemperature();
}