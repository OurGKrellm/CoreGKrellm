/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** SystemInformation.cpp, created by herbosa
*/

#include <iostream>
#include <sys/utsname.h>
#include <sstream>
#include "SystemInformation.hpp"

SystemInformation::SystemInformation() :
_content({TEXT, ""}),
_pos({0, 0}),
_title("System Informations")
{

}

void SystemInformation::UpdateContent() {
    struct utsname sysinfo;
    if (uname(&sysinfo) == -1)
        throw std::runtime_error("uname call error");
    std::stringstream info;
    info << "Operating system :" << sysinfo.sysname << std::endl
    << "Release Kernel Version :" << sysinfo.release << std::endl
    << "Kernel Build Timestamp :" << sysinfo.version << std::endl
    << "Machine Architecture :" << sysinfo.machine << std::endl;
    _content.content = info.str();
}

Content SystemInformation::getContent() {
    return _content;
}

std::string SystemInformation::getTitle() {
    return _title;
}

ModulePosition SystemInformation::getPosititon() {
    return _pos;
}

IMonitorModule *SystemInformation::clone()
{
    return new SystemInformation();
}