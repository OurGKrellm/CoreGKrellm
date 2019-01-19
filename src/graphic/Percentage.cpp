/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Percentage
*/

#include "GraphicTemplate.hpp"

Percentage::Percentage(const std::string &percent)
    : _percent(atoi(percent.data()))
    , _back(sf::Vector2<float>(200, HEIGHT / 20))
    , _front(sf::Vector2<float>(_percent, HEIGHT / 20))
{
//  _back.move(sf::Vector2f(25, 70));
//  _front.move(sf::Vector2f(25, 70));
    _front.setFillColor(sf::Color::Green);
    _back.setFillColor(sf::Color::White);
}

Percentage::Percentage(int percent)
    : _percent(percent)
    , _back(sf::Vector2<float>(200, 20))
    , _front(sf::Vector2<float>(_percent, 20))
{
//  _back.move(sf::Vector2f(25, 70));
//  _front.move(sf::Vector2f(25, 70));
    _front.setFillColor(sf::Color::Green);
    _back.setFillColor(sf::Color::White);
}

void Percentage::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_back);
    target.draw(_front);
}

void Percentage::move(sf::Vector2f offset)
{
    _back.move(offset);
    _front.move(offset);
}

// ----------------------- Multi Percentage --------------------------

MultiPercentage::MultiPercentage(const std::string &percent, sf::Font &font)
    : _percentages()
{
    std::string data;
    size_t koko = 50;
    size_t index = 0;

    for (size_t i = 0; percent[i]; ++i) {
        if (percent[i] == '%') {
            int nb = atoi(percent.data() + ++i);
            while (percent[i] != ':' && percent[i] != 0)
                i++;
            if (percent[i] == 0)
                throw std::exception();
            const char * offset = strchr(percent.data() + i, '%');
            if (offset == 0) 
                data = std::string(percent.begin() + i, percent.end());
            else
                data = std::string(percent.data() + i, offset);

            Percentage perc(nb);
            sf::Text text(data, font);

            perc.move(sf::Vector2f(20, index ));
            text.move(sf::Vector2f(0, index * koko));
            index++;
            _percentages.push_back(
                std::tuple(text, perc)
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

void MultiPercentage::move(sf::Vector2f offset)
{
    for (auto &elem: _percentages) {
        std::get<0>(elem).move(offset);
        std::get<1>(elem).move(offset);
    }
}