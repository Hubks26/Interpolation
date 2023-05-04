#ifndef POLYNOME_HPP
#define POLYNOME_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <initializer_list>

class Polynome : public sf::Drawable
{
public :
    Polynome();
	Polynome(std::initializer_list<float>);
    Polynome(std::initializer_list<float>, sf::Color);
    float evaluate(float) const;
    Polynome operator+(const Polynome&) const;
    Polynome operator*(const Polynome&) const;
    Polynome operator*(float) const;
    void print() const;
	
private :
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	
public :
    std::vector<float> m_coefs;
    sf::Color m_color;
};

#endif //POLYNOME_HPP
