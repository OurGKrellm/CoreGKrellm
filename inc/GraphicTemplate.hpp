/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** GraphicTemplate
*/

#ifndef GRAPHICTEMPLATE_HPP_
	#define GRAPHICTEMPLATE_HPP_

#include <vector>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cstring>

class Camembert : public sf::Drawable, public sf::Transformable {
public:
    Camembert(const std::string &percents);
    ~Camembert();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
private:
    std::vector<int> _pourcentages;
    sf::RectangleShape _back;
    std::vector<sf::RectangleShape> _rectangles;
};

class Percentage : public sf::Drawable, public sf::Transformable {
public:
    Percentage(const std::string &percent);
    Percentage(int percent);
    ~Percentage() = default;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
private:
    int _percent;
    sf::RectangleShape _back;
    sf::RectangleShape _front;
};

class MultiPercentage : public sf::Drawable, public sf::Transformable {
public:
    MultiPercentage(const std::string &percent, sf::Font &font);
    ~MultiPercentage() = default;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
private:
    std::vector<std::tuple<sf::Text, Percentage>> _percentages;
};

class Array : public sf::Drawable, public sf::Transformable {
public:
    Array(const std::string &font);
    ~Array();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
private:
    std::vector<std::tuple<std::string, std::vector<std::string>>> map;
    sf::Font &font;
};

class TopBar : public sf::Drawable, public sf::Transformable {
public:
    TopBar(const std::string &name);
private:
    sf::Text nb;
    sf::Font &font;
};

#endif /* !GRAPHICTEMPLATE_HPP_ */
