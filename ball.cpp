#include "ball.h"

ball::ball(float startX , float startY)
{
    m_Position.y = startY;
    m_Position.x = startX;
    

    m_BallShape.setSize(sf::Vector2f(10, 10));
    m_BallShape.setPosition(m_Position);
}

sf::FloatRect ball::getPosition()
{
    return m_BallShape.getGlobalBounds();
}

sf::RectangleShape ball::getShape()
{
    return m_BallShape;
}

float ball::getXVelocity()
{
    return m_DirectionX;
}

void ball::bounceSides()
{
    m_DirectionX = -m_DirectionX;

}

void ball::bounceTop()
{
    m_DirectionY = -m_DirectionY;
}

void ball::missBottom()
{
    m_Position.x = 1280/ 2;
    m_Position.y = 0;
}

void ball::hitBall()
{
    m_DirectionY = -m_DirectionY;
}

void ball::update(sf::Time dt)
{
    m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
    m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();

    
    m_BallShape.setPosition(m_Position); 
}


