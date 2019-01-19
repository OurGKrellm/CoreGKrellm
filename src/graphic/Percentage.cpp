/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Percentage
*/

#include "GraphicTemplate.hpp"

Percentage::Percentage(const std::string &percent)
    : _percent(atoi(percent.data()))
    , _back(sf::Vector2<float>(100, 20))
    , _front(sf::Vector2<float>(_percent, 20))
{
    _front.setFillColor(sf::Color::Green);
    _back.setFillColor(sf::Color::White);
}

Percentage::Percentage(int percent)
    : _percent(percent)
    , _back(sf::Vector2<float>(100, 20))
    , _front(sf::Vector2<float>(_percent, 20))
{
    _front.setFillColor(sf::Color::Green);
    _back.setFillColor(sf::Color::White);
}

void Percentage::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_back);
    target.draw(_front);
}

// ----------------------- Multi Percentage --------------------------

MultiPercentage::MultiPercentage(const std::string &percent, sf::Font &font)
    : _percentages()
{
    std::string data;

    for (size_t i = 0; percent[i]; ++i) {
        if (percent[i] == '%') {
            int nb = atoi(percent.data() + ++i);
            while (percent[i] != ':' || percent[i++] != 0);
            if (percent[i] == 0)
                throw std::exception();
            const char * offset = strchr(percent.data() + i, '%');
            if (offset = 0) 
                data = std::string(percent.begin() + i, percent.end());
            else
                data = std::string(percent.data() + i, offset);
            _percentages.push_back(
                std::tuple(sf::Text(data, font), Percentage(nb))
            );
        }
    }
}

void MultiPercentage::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto &elem: _percentages) {
        target.draw(std::get<0>(elem));
        target.draw(std::get<1>(elem));
    }
}
