#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.h"
#include "Paddle.h"
#include <sstream>


int main()
{
    sf::VideoMode VM(1280, 720);
    sf::RenderWindow window(VM, "Pong Clone");
    sf::Clock clock;
    ball myball(1280/2, 0.0);
    Paddle myPaddle(1280 / 2, 680);
    
    sf::Font font;
    font.loadFromFile("OpenSans-Bold.ttf");
    sf::Text fontHUD;
    fontHUD.setFont(font);
    fontHUD.setPosition(15, 0);
    fontHUD.setCharacterSize(30);
    fontHUD.setOutlineThickness(2);
    fontHUD.setOutlineColor(sf::Color::White);
    fontHUD.setFillColor(sf::Color::Red);


    int lives = 3;
    std::stringstream ss;
    ss << "LIVES: " << lives;

    fontHUD.setString(ss.str());

    sf::Time dt;
    sf::Event event;

    float bounceTimer = 0.10f;

    while(window.isOpen())
    {
        dt = clock.restart();
        bounceTimer -= dt.asSeconds();

        if (myball.getPosition().intersects(myPaddle.getPosition()))
        {
            if(bounceTimer < 0)
            {
                myball.hitBall();
                bounceTimer = 0.10f;
            }
            
        }

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || lives < 0)
        {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            myPaddle.moveLeft();
        }
        else
        {
            myPaddle.stopLeft();
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            myPaddle.moveRight();
        }
        else
        {
            myPaddle.stopRight();
        }
        
        if (myPaddle.getPosition().left < 0  )
        {
            myPaddle.stopLeft();
        }

        if (myPaddle.getPosition().left + myPaddle.getPosition().width > 1280)
        {
            myPaddle.stopRight();
        }



        if(myball.getPosition().left < 0 || myball.getPosition().left + myball.getPosition().width > 1280)
        {
            myball.bounceSides();
        }

        if(myball.getPosition().top < 0 && bounceTimer < 0)
        {
            myball.bounceTop();
            bounceTimer = 0.10f;
        }

        if(myball.getPosition().top + myball.getPosition().height > 720)
        {
            myball.missBottom();
            lives--;
            ss.str("");
            ss << "LIVES: " << lives;
            fontHUD.setString(ss.str());
        }








        window.clear();
        myball.update(dt);
        myPaddle.update(dt);
        

        window.draw(myball.getShape());
        window.draw(myPaddle.getShape());
        window.draw(fontHUD);
        window.display();
    }


    return 0;
}
