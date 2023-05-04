#ifndef BOARD_HPP
#define BOARD_HPP

#include "Polynome.hpp"

class Board : public sf::Drawable
{
public :
    Board();
    void addPoint(sf::Vector2i, sf::Vector2u);

private :
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    void interpolation();

private :
    Polynome m_abscisse;
    Polynome m_poly;
    std::vector<sf::Vector2f> m_points_ref_win;
    std::vector<sf::Vector2f> m_points;

};

#endif //BOARD_HPP