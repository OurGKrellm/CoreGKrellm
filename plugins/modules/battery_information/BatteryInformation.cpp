/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** BatteryInformation.cpp
*/

#include <filesystem>
#include <fstream>
#include "BatteryInformation.hpp"

BatteryInformation::BatteryInformation()
    : _content({ContentType::MULTI_PERCENTAGE, ""})
    , _title("Battery Information")
    , _position({0, 0, 0})
    , _folder("/sys/class/power_supply")
    , _battery()
{
    for (auto &entry: std::filesystem::directory_iterator(_folder)) {
        if (std::string(entry.path().filename()).find("BAT") == 0) {
            _battery.push_back({
                std::string(entry.path().filename()),
                std::string(entry.path()) + "/capacity",
                std::string(entry.path()) + "/technology",
                std::string(entry.path()) + "/capacity_level",
            });
        }
    }
}

std::string BatteryInformation::getTitle()
{
    return _title;
}
ModulePosition BatteryInformation::getPosititon()
{
    return _position;
}
Content BatteryInformation::getContent()
{
    return _content;
}

void BatteryInformation::UpdateContent()
{
    std::stringstream res;

    for (auto it = _battery.begin(); it != _battery.end(); it++) {
        std::fstream capacity(it->capcity_file, std::ios::in);
        std::fstream technology(it->techno_file, std::ios::in);
        std::fstream status(it->status_file, std::ios::in);
        std::string capacity_value;
        std::string technology_value;
        std::string status_value;

        if (!capacity.good())
            throw std::runtime_error("Error while opening: " + it->capcity_file);
        if (!capacity.good())
            throw std::runtime_error("Error while opening: " + it->techno_file);
        if (!capacity.good())
            throw std::runtime_error("Error while opening: " + it->status_file);
        capacity >> capacity_value;
        technology >> technology_value;
        status >> status_value;
        res << "%" << (long int) (std::stol(capacity_value)) << ": " << it->name << " " << technology_value << " " << status_value;
    }
    _content.content.clear();
    _content.content = res.str();
}

BatteryInformation *BatteryInformation::clone()
{
    return new BatteryInformation();
}