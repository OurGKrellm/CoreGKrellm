/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** ProcessorInformation.hpp, created by herbosa
*/
#ifndef CPP_RUSH3_2018_PROCESSORINFORMATION_HPP
#define CPP_RUSH3_2018_PROCESSORINFORMATION_HPP

#include <vector>
#include "IMonitorModule.hpp"

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
    std::string getProcessorName(std::vector<std::string> vector);
    uint64_t getProcessorFrequency();
    size_t  getProcessorNumberOfCore(std::vector<std::string> vector);
    std::string getCoreUtilisation(std::vector<std::string> vector);
    uint64_t convertFrequency(std::string str);

    Content _content;
    std::string _title;
    std::string _model;
    uint64_t _frequency;
    size_t _nbCores;
    ModulePosition _pos;
};

#endif //CPP_RUSH3_2018_PROCESSORINFORMATION_HPP
