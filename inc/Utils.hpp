/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Utils
*/

#ifndef UTILS_HPP_
    #define UTILS_HPP_

#include "IMonitorModule.hpp"

#include <vector>

class Utils {
    public:
        static std::size_t hashVector(std::vector<IMonitorModule *> const &modules);

    protected:
    private:
};

#endif /* !UTILS_HPP_ */
