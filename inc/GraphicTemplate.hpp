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
    ~Percentage() = default;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
private:
    int percent;
    sf::RectangleShape _back;
    sf::RectangleShape _front;
};

class MultiPercentage : public sf::Drawable, public sf::Transformable {
public:
    MultiPercentage(const std::string &percent);
    ~MultiPercentage();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
private:
    std::vector<std::tuple<std::string, Percentage>> _percentages;
};

#endif /* !GRAPHICTEMPLATE_HPP_ */
