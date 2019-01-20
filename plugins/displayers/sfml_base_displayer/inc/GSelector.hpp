/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** GSelector
*/

#ifndef GSELECTOR_HPP_
	#define GSELECTOR_HPP_

#include <SFML/Graphics.hpp>
#include "Selector.hpp"

class GSelector : public sf::Drawable {
public:
	GSelector(std::vector<std::string> datas, sf::Font &font);
	~GSelector() = default;

    GSelector &operator++(int) { _selector++; _selected.setString(_selector.getSelected()); return *this; } 
    GSelector &operator--(int) { _selector--; _selected.setString(_selector.getSelected()); return *this; } 

    GSelector &operator++() { _selector++; _selected.setString(_selector.getSelected()); return *this; } 
    GSelector &operator--() { _selector--; _selected.setString(_selector.getSelected()); return *this; } 

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    const std::string &getSelected() { return _selector.getSelected(); }
private:
    sf::Text _selected;
    Selector<std::string> _selector;
};

#endif /* !GSELECTOR_HPP_ */
