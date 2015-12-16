//
// Created by Hammad Siddiqui on 12/15/15.
//

#include "Game.h"
#include <iostream>
/*
 * Constructor creates an empty window object of size 640x480 pixels
 * And then, it calls all the initialization of other elements.
 * */
Game::Game() : mWindow(sf::VideoMode(450,520,32),"Frogger")  {
    //Load Font
    if(!font.loadFromFile("assets/Abduction.ttf"))
    {
        std::cout << "Failed to load font \"Abduction\"" << std::endl;
    }
    //paint out the entire window with blue color
    sf::Color blueColor(0,0,55);
    mWindow.clear(blueColor);
    //initialize frog to its position
    initWindow();
    initFrog();
    initScorecard();
    mWindow.display();


}


void Game::initWindow() {
    //Draw Top Grass
    /*
    sf::Texture grass;
    grass.loadFromFile("assets/finalGrass.png");
    sf::Sprite finalGrass;
    finalGrass.setTexture(grass);
    finalGrass.scale(2,2);
    finalGrass.setPosition(1,50);
    mWindow.draw(finalGrass);
*/
    //Draw pavements
    sf::Texture path;
    path.loadFromFile("assets/background.png");
    sf::Sprite footPath;
    footPath.setTexture(path);
    footPath.scale(2,2);
    footPath.setPosition(1,50);
    mWindow.draw(footPath);


}


void Game::initFrog() {
    sf::Texture frog;

    if (!frog.loadFromFile("assets/frog.png"))
        std::cout << "Failed to load frog Sprite" << std::endl;

    frogSprite.setTexture(frog);
    frogSprite.setScale(2.0,2.0);
    frogSprite.setPosition(mWindow.getSize().x/2,mWindow.getSize().y -70); //Initial position of the frog
    mWindow.draw(frogSprite);
}

void Game::initScorecard() {
    sf::Text scoreText("000",font,11);
    scoreText.setCharacterSize(20);
    scoreText.setPosition(mWindow.getSize().x/2 - scoreText.getGlobalBounds().width/2, 10);
    mWindow.draw(scoreText);

}


void Game::run() {
   // welcomeScreen();
    while(mWindow.isOpen()) {
        //Respond to Events in the Event Queue
        processEvents();
        //Update the Game according to the events
        update();
        //Render the update screen in the window.
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while(mWindow.pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            mWindow.close();
        }
    }
}


void Game::render() {
   // mWindow.clear();
   // mWindow.display();
}


void Game::update() {

    //All logic goes in here
}


/*



void Game::welcomeScreen() {
    mWindow.clear(blueColor);
    sf::Text text("Frogger",font,32);
    text.setCharacterSize(32);
    text.setPosition(mWindow.getSize().x/2 - text.getGlobalBounds().width/2,
                     mWindow.getSize().y/2 - text.getGlobalBounds().height/2);
    mWindow.draw(text);
    sf::Event pressed;
        while(mWindow.pollEvent(pressed)) {
            if(pressed.type == sf::Event::KeyPressed) {
                std::cout << "Hey pressed" << std::endl;
                break;
            }
        }
}


 */