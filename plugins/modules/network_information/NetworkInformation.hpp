/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** NetworkInformation.hpp
*/

#ifndef CPP_RUSH3_2018_NETWORKINFORMATION_HPP
#define CPP_RUSH3_2018_NETWORKINFORMATION_HPP

#include <vector>
#include "IMonitorModule.hpp"

typedef struct NetworkInterface {
    std::string interface_name;
    std::string tx_file;
    std::string rx_file;
    unsigned int last_rx;
    unsigned int last_tx;
} NetworkInterface;

class NetworkInformation : public IMonitorModule
{
    public:
        NetworkInformation();
        ~NetworkInformation() override = default;
        void UpdateContent() override;
        Content getContent() override;
        std::string getTitle() override;
        ModulePosition getPosititon() override;
        IMonitorModule *clone() override;

    private:
        Content _content;
        std::string _title;
        ModulePosition _position;
        std::string _folder;
        std::vector<NetworkInterface> _networkInterface;
        unsigned int _time_between_each_measure;
        unsigned int _counter;
};

#endif //CPP_RUSH3_2018_NETWORKINFORMATION_HPP
