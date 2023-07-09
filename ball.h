#ifndef BALL_H
#define BALL_H

// #pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ball
{
private:
    sf::Vector2f m_Position;
    sf::RectangleShape m_BallShape;

    float m_Speed = 500;
    float m_DirectionX = 1.0f;
    float m_DirectionY = 1.0f;

public:
    ball(float startX  ,float startY );

    sf::FloatRect getPosition();
    sf::RectangleShape getShape();

    float getXVelocity();

    void bounceSides();

    void bounceTop();

    void missBottom();

    void hitBall();

    void update(sf::Time dt);
};

#endif