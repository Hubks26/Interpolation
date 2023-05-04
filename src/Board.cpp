#include "Board.hpp"

#include <iostream>

Board::Board()
: m_abscisse({0.f}, sf::Color(128, 128, 128))
{
}

void Board::addPoint(sf::Vector2i mousePosition, sf::Vector2u winSize)
{
    m_points_ref_win.push_back({float(mousePosition.x), float(mousePosition.y)});
    m_points.push_back({20*float(mousePosition.x)/float(winSize.x)-10, 20*(1-float(mousePosition.y)/float(winSize.y))-10});

    interpolation();
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::CircleShape point;
    point.setRadius(10.f);
    point.setOrigin(10.f, 10.f);
    point.setFillColor(sf::Color::Red);

    for(std::size_t i = 0; i < m_points.size(); ++i)
    {
        point.setPosition(m_points_ref_win[i]);
        target.draw(point);
    }

    target.draw(m_poly);
    target.draw(m_abscisse);
}

void Board::interpolation()
{
    m_poly = Polynome({0.f});

    for(std::size_t i = 0; i < m_points.size(); ++i)
    {
        Polynome interpolateur = Polynome({1.f});

        for(std::size_t j = 0; j < m_points.size(); ++j)
        {
            if(j != i)
                interpolateur = interpolateur * Polynome({-m_points[j].x, 1}) * (1.f/(m_points[i].x - m_points[j].x));
        }

        m_poly = m_poly + (interpolateur * (m_points[i].y));
    }
}