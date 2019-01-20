/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** NetworkInformation.cpp
*/

#include <stdint.h>
#include <filesystem>
#include <iostream>
#include <fstream>
#include "NetworkInformation.hpp"

NetworkInformation::NetworkInformation()
    : _content({ContentType::PERCENTAGE, ""})
    , _title("Network Information")
    , _position({0, 0, 0})
    , _folder("/sys/class/net/")
    , _time_between_each_measure(0)
    , _counter(0)
{

    for (auto &entry: std::filesystem::directory_iterator(_folder))
        _networkInterface.push_back({
            std::string(entry.path().filename()),
            std::string(entry.path()) + "/statistics/tx_bytes",
            std::string(entry.path()) + "/statistics/rx_bytes",
            0,
            0
        });
}

std::string NetworkInformation::getTitle()
{
    return _title;
}

ModulePosition NetworkInformation::getPosititon()
{
    return _position;
}

Content NetworkInformation::getContent()
{
    return _content;
}

void NetworkInformation::UpdateContent()
{
    std::string res;
    std::string interface("Interface,");
    std::string download("Download,");
    std::string upload("Upload,");
    unsigned int actual_up;
    unsigned int actual_down;

    if (_time_between_each_measure == _counter) {
        _counter = 0;
        _content.content.clear();
        for (auto it = _networkInterface.begin();
             it != _networkInterface.end(); it++) {
            std::fstream tx(it->tx_file, std::ios::in);
            std::fstream rx(it->rx_file, std::ios::in);
            std::string tx_bytes;
            std::string rx_bytes;

            if (!rx.good())
                throw std::runtime_error("Error while opening: " + it->rx_file);
            if (!tx.good())
                throw std::runtime_error("Error while opening: " + it->tx_file);
            rx >> rx_bytes;
            tx >> tx_bytes;
            actual_down = (unsigned int) std::stol(rx_bytes);
            actual_up = (unsigned int) std::stol(tx_bytes);
            interface += it->interface_name + ",";
            download += std::to_string((actual_down - it->last_rx) / 1000) + ",";
            upload += std::to_string((actual_up - it->last_tx) / 1000) + ",";
            it->last_tx = actual_up;
            it->last_rx = actual_down;
        }
        interface[interface.size() - 1] = '\n';
        download[download.size() - 1] = '\n';
        upload[upload.size() - 1] = '\n';
        _content.content += interface;
        _content.content += download;
        _content.content += upload;
        return;
    }
    _counter++;
}