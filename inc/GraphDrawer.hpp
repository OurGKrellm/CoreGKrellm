/*
** EPITECH PROJECT, 2022
** cpp_rush3_2018
** File description:
** GraphDrawer.hpp, created by herbosa
*/
#ifndef CPP_RUSH3_2018_GRAPHDRAWER_HPP
#define CPP_RUSH3_2018_GRAPHDRAWER_HPP


class GraphDrawer {
public:
    Drawer(int width = 500, int height = 100, int posX = 0, int posY = 0)
            : _offset(0),
              _width(width),
              _height(height),
              _posX(posX),
              _posY(posY)
    {
        _border.setSize({static_cast<float>(_width), static_cast<float>(_height)});
        _border.setFillColor({100, 100, 100});
        _border.setPosition({static_cast<float>(_posX), static_cast<float>(_posY)});
        for (int i = 0; i < _width; i++) {
            _rectangles.push_back(new sf::RectangleShape({2.f, 0.f}));
        }
    };
    void PrintNewData(int perc, sf::RenderWindow &window);

private:
    std::vector<sf::RectangleShape*> _rectangles;
    sf::RectangleShape _border;
    int _offset;
    int _width;
    int _height;
    int _posX;
    int _posY;
};

#endif //CPP_RUSH3_2018_GRAPHDRAWER_HPP
