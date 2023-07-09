#include "Paddle.h"

Paddle::Paddle(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;

    m_Space.setSize(sf::Vector2f(80, 5));
    m_Space.setFillColor(sf::Color::Red);
    m_Space.setOutlineColor(sf::Color::White);
    m_Space.setOutlineThickness(3);

    m_Space.setPosition(m_Position);
}

sf::RectangleShape Paddle::getShape()
{
    return m_Space;
}

sf::FloatRect Paddle::getPosition()
{
    return m_Space.getGlobalBounds();
}

void Paddle::moveLeft()
{
    m_MovingLeft = true;
}

void Paddle::moveRight()
{
    m_MovingRight = true;
}

void Paddle::stopLeft()
{
    m_MovingLeft = false;
}

void Paddle::stopRight()
{
    m_MovingRight = false;
}

void Paddle::update(sf::Time dt)
{
    if(m_MovingLeft )
    {
        m_Position.x -= m_Speed * dt.asSeconds();
    }

    if(m_MovingRight )
    {
        m_Position.x += m_Speed * dt.asSeconds();
    }

    m_Space.setPosition(m_Position);
}








