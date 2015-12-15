#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"


int main() {


    Game game;
    game.run();





/*
    sf::RenderWindow window(sf::VideoMode(640,480,32),"Frogger");
    sf::Color blueColor(0,0,55);
    // Load Font
    sf::Font font;
    font.loadFromFile("assets/Abduction.ttf");

      sf::Texture frog;

      if (!frog.loadFromFile("assets/frog.png"))
          return EXIT_FAILURE;


    sf::Sprite sprite;
    sprite.setTexture(frog);
    sprite.setScale(2.0,2.0);
    sprite.setPosition(window.getSize().x/2,window.getSize().y -30);
    //Set font position to the center of the screen
    sf::Text text("Frogger",font,11);
    text.setCharacterSize(32);
    text.setPosition(window.getSize().x/2 - text.getGlobalBounds().width/2,
                     window.getSize().y/2 - text.getGlobalBounds().height/2);


    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        if(event.type == sf::Event::KeyPressed)
        {

            window.clear(blueColor);
            std::cout << "HELLO" << std::endl;
            window.draw(sprite);
            window.display();
        }
        else {
            window.clear(blueColor);//Turn window color
            window.draw(text); // Initial Load Screen
            window.display();
        }

    }
*/
    return 0;
}
