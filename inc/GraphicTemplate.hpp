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

#define HEIGHT 800
#define WIDTH 1000

class IEntity : public sf::Drawable, public sf::Transformable {
public:
    virtual ~IEntity() = default;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    virtual void move(sf::Vector2f offset) = 0;
};

class Camembert : public IEntity {
public:
    Camembert(const std::string &percents);
    ~Camembert();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
    void move(sf::Vector2f offset);
private:
    std::vector<int> _pourcentages;
    sf::RectangleShape _back;
    std::vector<sf::RectangleShape> _rectangles;
};


class Percentage : public IEntity {
public:
    Percentage(const std::string &percent);
    Percentage(int percent);
    ~Percentage() = default;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
    void move(sf::Vector2f offset);
private:
    int _percent;
    sf::RectangleShape _back;
    sf::RectangleShape _front;
};


class MultiPercentage : public IEntity {
public:
    MultiPercentage(const std::string &percent, sf::Font &font);
    ~MultiPercentage() = default;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
    void move(sf::Vector2f offset);
private:
    std::vector<std::tuple<sf::Text, Percentage>> _percentages;
};

class Array : public IEntity {
public:
    Array(const std::string &content, sf::Font &font);
    ~Array();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
    void move(sf::Vector2f offset);
private:
    std::vector<std::tuple<sf::Text, std::vector<sf::Text>>> _map;
    sf::Font &_font;
};


class TopBar : public IEntity {
public:
    TopBar(sf::Font &font);
    ~TopBar();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
    void move(sf::Vector2f offset);
private:
    sf::Font &_font;
    int _nb;
    sf::Text _nbText;
    sf::RectangleShape _bar;
};

class Text : public IEntity {
public:
    Text(const std::string &content, sf::Font &font);
    ~Text() = default;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const final;
    void move(sf::Vector2f offset);
    sf::Text &getText() { return _text; }
private:
    sf::Font &_font;
    sf::Text _text;
};

#endif /* !GRAPHICTEMPLATE_HPP_ */
