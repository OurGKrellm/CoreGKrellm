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
    Array(const std::string &content, sf::Font &font);
    ~Array() = default;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
private:
    std::vector<std::tuple<sf::Text *, std::vector<sf::Text *>>> _map;
    sf::Font &_font;
    int _width;
    int _height;
    int _col;
    int _lin;
    std::vector<sf::RectangleShape*> _rectangles;
    std::vector<sf::Text*> _text;
    sf::RectangleShape _border;


};


class TopBar : public sf::Drawable, public sf::Transformable {
public:
    TopBar(sf::Font &font);
    ~TopBar();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
private:
    sf::Font &_font;
    int _nb;
    sf::Text _nbText;
    sf::RectangleShape _bar;
};

#endif /* !GRAPHICTEMPLATE_HPP_ */
