//
// Created by Hammad Siddiqui on 12/15/15.
//

#include "Game.h"
#include <iostream>
/*
 * Constructor creates an empty window object of size 640x480 pixels
 * And then, it calls all the initialization of other elements.
 * */
Game::Game() : mWindow(sf::VideoMode(640,480,32),"Frogger")  {
    //Load Font
    if(!font.loadFromFile("assets/Abduction.ttf"))
    {
        std::cout << "Failed to load font \"Abduction\"" << std::endl;
    }
    //paint out the entire window with blue color
    sf::Color blueColor(0,0,55);
    mWindow.clear(blueColor);
    //initialize frog to its position
    initFrog();
    initScorecard();

}

void Game::initFrog() {
    sf::Texture frog;

    if (!frog.loadFromFile("assets/frog.png"))
        std::cout << "Failed to load frog Sprite" << std::endl;

    frogSprite.setTexture(frog);
    frogSprite.setScale(2.0,2.0);
    frogSprite.setPosition(mWindow.getSize().x/2,mWindow.getSize().y -30); //Initial position of the frog
    mWindow.draw(frogSprite);
}

void Game::initScorecard() {
    sf::Text scoreText("000",font,11);
    scoreText.setCharacterSize(20);
    scoreText.setPosition(mWindow.getSize().x/2 - scoreText.getGlobalBounds().width/2, 30);
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
    mWindow.display();
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