#include "Engine.hpp"
#include <iostream>

const sf::Time Engine::m_timePerFrame = sf::seconds(1.f/60.f);

Engine::Engine()
: m_window(sf::VideoMode(1000, 1000), "Interpolation", sf::Style::Fullscreen, sf::ContextSettings(0U, 0U, 8U))
{
}

void Engine::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		
		while (timeSinceLastUpdate > m_timePerFrame)
		{
			timeSinceLastUpdate -= m_timePerFrame;
			update();
		}

		render();
	}
}

void Engine::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			m_window.close();

		if (event.type == sf::Event::MouseButtonPressed)
			m_board.addPoint(sf::Mouse::getPosition(), m_window.getSize());
	}
}

void Engine::update()
{
}

void Engine::render()
{
	m_window.clear();

	m_window.draw(m_board);

	m_window.display();
}
