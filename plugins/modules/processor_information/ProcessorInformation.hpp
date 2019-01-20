/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** ProcessorInformation.hpp, created by herbosa
*/
#ifndef CPP_RUSH3_2018_PROCESSORINFORMATION_HPP
#define CPP_RUSH3_2018_PROCESSORINFORMATION_HPP

#include <array>
#include <vector>
#include "IMonitorModule.hpp"

typedef struct CPU_INFO {
    std::string cpu_name;
    std::array<long double, 4> info;
} CPU_INFO;

class ProcessorInformation : public IMonitorModule {
public:
    ProcessorInformation();
    ~ProcessorInformation() override = default;
    void UpdateContent() override;
    Content getContent() override;
    std::string getTitle() override;
    ModulePosition getPosititon() override;
    IMonitorModule *clone() override;

private:
    std::vector<std::string> split(const std::string& str, char delim = ' ');
    std::string getProcessorName(std::vector<std::string> &vector);
    std::string getCoreUtilisation(std::vector<std::string> &vector);
    std::vector<CPU_INFO> _cpu_info;
    Content _content;
    std::string _title;
    std::string _model;
    size_t _nbCores;
    unsigned int _time_between_each_measure;
    unsigned int _counter;
    ModulePosition _pos;
};

#endif //CPP_RUSH3_2018_PROCESSORINFORMATION_HPP
