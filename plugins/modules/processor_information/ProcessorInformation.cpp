/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** ProcessorInformation.cpp, created by herbosa
*/

#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "ProcessorInformation.hpp"

ProcessorInformation::ProcessorInformation() :
    _cpu_info(),
    _content({ContentType::MULTI_PERCENTAGE, ""}),
    _title(),
    _model(),
    _nbCores(0),
    _time_between_each_measure(30),
    _counter(30),
    _pos({0, 0})
{}

std::vector<std::string> ProcessorInformation::split(const std::string& str, char delim)
{
    std::vector<std::string> vec;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        vec.push_back(token);
    }
    return vec;
}

std::string ProcessorInformation::getProcessorName(std::vector<std::string> &vector) {
    std::string procName = "Unknown Processor";
    for (int i = 0; i < vector.size(); ++i) {
        if (vector[i].find("model name") != std::string::npos) {
            procName = vector[i].substr(vector[i].find(":") + 2, vector[i].length());
            return procName;
        }
    }
    return procName;
}

std::string ProcessorInformation::getCoreUtilisation(std::vector<std::string> &vector) {
    std::stringstream procName;
    size_t nbCores = 0;

    for (auto it = vector.begin(); it != vector.end(); it++) {
        std::vector<std::string> cpu_stat = split(*it, ' ');
        for (auto it_stat = cpu_stat.begin(); it_stat != cpu_stat.end(); it_stat++) {
            if (*it_stat == "")
                it_stat = cpu_stat.erase(it_stat);
        }
        long double loadavg = ((std::stold(cpu_stat[1]) + std::stold(cpu_stat[2])+std::stold(cpu_stat[3])) - (_cpu_info[nbCores].info[0]+_cpu_info[nbCores].info[1]+_cpu_info[nbCores].info[2])) / ((std::stold(cpu_stat[1])+std::stold(cpu_stat[2])+std::stold(cpu_stat[3])+std::stold(cpu_stat[4])) - (_cpu_info[nbCores].info[0] + _cpu_info[nbCores].info[1] + _cpu_info[nbCores].info[2] + _cpu_info[nbCores].info[3]));
        _cpu_info[nbCores].info[0] = std::stold(cpu_stat[1]);
        _cpu_info[nbCores].info[1] = std::stold(cpu_stat[2]);
        _cpu_info[nbCores].info[2] = std::stold(cpu_stat[3]);
        _cpu_info[nbCores].info[3] = std::stold(cpu_stat[4]);
        procName << "%" << (int) (loadavg * 100) << ":CPU Core " << nbCores;
        nbCores++;
    }
    return procName.str();
}

void ProcessorInformation::UpdateContent()
{
    std::stringstream cpuinfo;
    std::stringstream cpustat;

    if (_time_between_each_measure == _counter) {
        _counter = 0;
        _content.content.clear();
        _title.clear();
        std::fstream input("/proc/cpuinfo", std::ios::in);
        std::fstream stat("/proc/stat", std::ios::in);
        if (!input.good())
            throw std::runtime_error("Cannot open /proc/cpuinfo");
        if (!stat.good())
            throw std::runtime_error("Cannot open /proc/stat");
        cpuinfo << input.rdbuf();
        cpustat << stat.rdbuf();
        std::vector<std::string> info = split(cpuinfo.str(), '\n');
        std::vector<std::string> cpu_stat = split(cpustat.str(), '\n');
        for (auto it = cpu_stat.begin(); it != cpu_stat.end(); it++) {
            if (it->find("cpu") != 0) {
                while (it != cpu_stat.end()) {
                    it = cpu_stat.erase(it);
                }
                break;
            }
            if (_nbCores == 0)
                _cpu_info.push_back(
                    {"CPU Core " + std::to_string(_cpu_info.size()),
                     std::array<long double, 4>{0, 0, 0, 0}});
        }
        if (_nbCores == 0)
            _nbCores = cpu_stat.size();
        _model = getProcessorName(info);
        _content.content = getCoreUtilisation(cpu_stat);
        _title += _model;
        return;
    }
    _counter++;
}

Content ProcessorInformation::getContent() {
    return _content;
}

std::string ProcessorInformation::getTitle() {
    return _title;
}

ModulePosition ProcessorInformation::getPosititon() {
    return _pos;
}

IMonitorModule *ProcessorInformation::clone()
{
    return new ProcessorInformation();
}

