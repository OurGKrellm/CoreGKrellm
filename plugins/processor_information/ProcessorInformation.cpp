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
#include <ProcessorInformation.hpp>

#include "ProcessorInformation.hpp"



uint64_t ProcessorInformation::convertFrequency(std::string str) {
    uint64_t frequency = 0;
    uint64_t multipliator = 1;
    if (str.find("GHz") != std::string::npos) {
        str = str.substr(0, str.find("GHz"));
        multipliator = 1000000000;
    } else if (str.find("MHz") != std::string::npos) {
        str = str.substr(0, str.find("MHz"));
        multipliator = 1000000;
    } else if (str.find("KHz") != std::string::npos) {
        str = str.substr(0, str.find("KHz"));
        multipliator = 1000;
    } else if (str.find("Hz") != std::string::npos) {
        str = str.substr(0, str.find("Hz"));
    }
    frequency = static_cast<uint64_t>(std::stod(str) * multipliator);
    return frequency;
}
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

std::string ProcessorInformation::getProcessorName(std::vector<std::string> vector) {
    std::string procName = "Unknown Processor";
    for (int i = 0; i < vector.size(); ++i) {
        if (vector[i].find("model name") != std::string::npos) {
            procName = vector[i].substr(vector[i].find(":") + 2, vector[i].length());
            return procName;
        }
    }
    return procName;
}

uint64_t ProcessorInformation::getProcessorFrequency() {
    uint64_t frequency = 0;
    std::string frequencyString = "";

    frequencyString = _model.substr(_model.find("@ ")  + 2, _model.length());
    frequency = convertFrequency(frequencyString);
    return frequency;
}

size_t ProcessorInformation::getProcessorNumberOfCore(std::vector<std::string> vector) {
    std::string procName = "";
    size_t nbCores = 0;
    for (int i = 0; i < vector.size(); ++i) {
        if (vector[i].find("processor") != std::string::npos)
            nbCores++;
    }
    return nbCores;
}

std::string ProcessorInformation::getCoreUtilisation(std::vector<std::string> vector) {
    std::stringstream procName;
    size_t nbCores = 0;

    for (int i = 0; i < vector.size(); ++i) {
        if (vector[i].find("cpu MHz") != std::string::npos) {
            double usage = (std::stod(
                    vector[i].substr(vector[i].find(":") + 2, vector[i].length()))
                    * 1000000);

            int percentage = static_cast<char>(usage / _frequency * 100);
            procName << "%" << percentage << ":CPU Core " << nbCores;
            nbCores++;
        }
    }
    return procName.str();
}

ProcessorInformation::ProcessorInformation() :
        _content({MULTI_PERCENTAGE, ""}),
        _pos({0, 0}),
        _title("Processor Information : ") {

}

void ProcessorInformation::UpdateContent() {
    std::stringstream cpuinfo;

    _content.content.clear();
    std::fstream input("/proc/cpuinfo", std::ios::in);
    if (!input.good())
        throw std::runtime_error("Cannot open /proc/cpuinfo");
    cpuinfo << input.rdbuf();
    std::vector<std::string> info = split(cpuinfo.str(), '\n');
    _model = getProcessorName(info);
    _frequency = getProcessorFrequency();
    _nbCores = getProcessorNumberOfCore(info);
    _content.content = getCoreUtilisation(info);
    _title += _model;
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

