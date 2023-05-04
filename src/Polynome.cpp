#include "Polynome.hpp"
#include <iostream>

Polynome::Polynome()
{
    m_color = sf::Color::White;
}

Polynome::Polynome(std::initializer_list<float> coefs)
{
    for(float i : coefs)
    {
        m_coefs.push_back(i);
    }

    m_color = sf::Color::White;
}

Polynome::Polynome(std::initializer_list<float> coefs, sf::Color color)
{
    for(float i : coefs)
    {
        m_coefs.push_back(i);
    }

    m_color = color;
}

float Polynome::evaluate(float x) const
{
    float res = 0.f;
    for(size_t i = 0; i < m_coefs.size(); ++i)
    {
        res += m_coefs[i]*pow(x, i);
    }
    return res;
}

Polynome Polynome::operator+(const Polynome& other) const 
{
    Polynome resultat;
    std::vector<float> coefs;
    
    for (std::size_t i = 0; i < std::max(m_coefs.size(), other.m_coefs.size()); ++i)
    {
        if(i >= m_coefs.size()){
            coefs.push_back(other.m_coefs[i]);
        }
        else if(i >= other.m_coefs.size()){
            coefs.push_back(m_coefs[i]);
        }
        else {
            coefs.push_back(m_coefs[i] + other.m_coefs[i]);
        }
    }

    resultat.m_coefs = coefs;
    return resultat;
}

Polynome Polynome::operator*(const Polynome& other) const 
{
    Polynome resultat;
    std::vector<float> coefs;

    for (std::size_t i = 0; i < this->m_coefs.size() + other.m_coefs.size() - 1; ++i)
    {
        float coef = 0.f;

        for (std::size_t j = 0; j <= i; ++j)
        {
            if(j < m_coefs.size() && i-j < other.m_coefs.size())
            {
                coef += this->m_coefs[j]*other.m_coefs[i-j];
            }
        }

        coefs.push_back(coef);
    }

    resultat.m_coefs = coefs;
    return resultat;
}

Polynome Polynome::operator*(float lambda) const 
{
    Polynome resultat;
    std::vector<float> coefs;
    
    for (std::size_t i = 0; i < m_coefs.size(); ++i)
    {
        coefs.push_back(m_coefs[i] * lambda);
    }

    resultat.m_coefs = coefs;
    return resultat;
}

void Polynome::print() const
{
    for(std::size_t i=0; i<m_coefs.size(); ++i)
    {
        if(i != m_coefs.size()-1) 
            std::cout << m_coefs[i] << " X**" << i << " + ";
        else
            std::cout << m_coefs[i] << " X**" << i;
    }
    std::cout << std::endl;
}

void Polynome::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    int win_x = target.getSize().x;
    int win_y = target.getSize().y;


    float min_x, max_x;//min_y, max_y;
    uint res;

    min_x = -10.f;
    max_x = 10.f;
    res = 500;

    sf::VertexArray lines(sf::LinesStrip, res);

    for(uint i = 0; i<res; ++i)
    {
        lines[i].position = sf::Vector2f(
            win_x*(min_x*(1-float(i)/res) + max_x*(float(i)/res)+10)/20, 
            win_y*(1-(evaluate(min_x*(1-float(i)/res) + max_x*(float(i)/res))+10)/20)
        );
        lines[i].color = m_color;
    }

    target.draw(lines);
}