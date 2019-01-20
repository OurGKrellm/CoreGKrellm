/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** BatteryInformation.hpp
*/

#ifndef CPP_RUSH3_2018_BATTERYINFORMATION_HPP
#define CPP_RUSH3_2018_BATTERYINFORMATION_HPP

#include <vector>
#include "IMonitorModule.hpp"

typedef struct Battery {
    std::string name;
    std::string capcity_file;
    std::string techno_file;
    std::string status_file;
} Battery;

class BatteryInformation : public IMonitorModule
{
    public:
        BatteryInformation();
        ~BatteryInformation() override = default;
        void UpdateContent() override;
        Content getContent() override;
        std::string getTitle() override;
        ModulePosition getPosititon() override;
        BatteryInformation *clone() override;
    private:
        Content _content;
        std::string _title;
        ModulePosition _position;
        std::string _folder;
        std::vector<Battery> _battery;
};


#endif //CPP_RUSH3_2018_BATTERYINFORMATION_HPP
