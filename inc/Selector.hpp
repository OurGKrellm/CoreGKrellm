/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Selector
*/

#ifndef SELECTOR_HPP_
    #define SELECTOR_HPP_

#include <algorithm>

template<typename T>
class Selector {
public:
    Selector(const std::vector<T> &datas)
        : _internal(datas)
    {}

    ~Selector() = default;

    Selector &operator++(int)
    {
        std::rotate(_internal.begin(), _internal.begin() + 1, _internal.end());
    }

    Selector &operator++()
    {
        std::rotate(_internal.begin(), _internal.begin() + 1, _internal.end());
    }

    Selector &operator--(int)
    {
        std::reverse(_internal.begin(), _internal.end());
        std::rotate(_internal.begin(), _internal.begin() + 1, _internal.end());
        std::reverse(_internal.begin(), _internal.end());
    }

    Selector &operator--()
    {
        std::reverse(_internal.begin(), _internal.end());
        std::rotate(_internal.begin(), _internal.begin() + 1, _internal.end());
        std::reverse(_internal.begin(), _internal.end());
    }

    const T &getSelected() const
    {
        return _internal[0];
    }

    const std::vector<T> &getAll() const
    {
        return _internal;
    }

private:
    std::vector<T> _internal;
};

#endif /* !SELECTOR_HPP_ */
