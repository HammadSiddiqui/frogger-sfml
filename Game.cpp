//
// Created by Hammad Siddiqui on 12/15/15.
//

#include "Game.h"
#include <iostream>
#include <curses.h>

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
    initCarsAndWood();
    initFrog();
    initScorecard();
    mWindow.display();


}


void Game::initWindow() {

    //Draw the asset -> background
    sf::Texture path;
    path.loadFromFile("assets/background.png");
    sf::Sprite truckSprite;
    truckSprite.setTexture(path);
    truckSprite.scale(2,2);
    truckSprite.setPosition(1,50);
    mWindow.draw(truckSprite);


}


void Game::initCarsAndWood() {

    //Init truck
    sf::Texture truck;
    truck.loadFromFile("assets/truck.png");
    sf::Sprite truckSprite;
    truckSprite.setTexture(truck);
    truckSprite.scale(2,2);
    truckSprite.setPosition(1,TRUCK_HEIGHT);
    mWindow.draw(truckSprite);

    //Init car1
    sf::Texture car1;
    car1.loadFromFile("assets/car1.png");
    sf::Sprite car1Sprite;
    car1Sprite.setTexture(car1);
    car1Sprite.scale(2,2);
    car1Sprite.setPosition(1,CAR1_HEIGHT);
    mWindow.draw(car1Sprite);


    //Init car2
    sf::Texture car2;
    car2.loadFromFile("assets/car2.png");
    sf::Sprite car2Sprite;
    car2Sprite.setTexture(car2);
    car2Sprite.scale(2,2);
    car2Sprite.setPosition(1,CAR2_HEIGHT);
    mWindow.draw(car2Sprite);


    //Init car3
    sf::Texture car3;
    car3.loadFromFile("assets/car3.png");
    sf::Sprite car3Sprite;
    car3Sprite.setTexture(car3);
    car3Sprite.scale(2,2);
    car3Sprite.setPosition(1,CAR3_HEIGHT);
    mWindow.draw(car3Sprite);

    //Init tractor
    sf::Texture tractor;
    if(!tractor.loadFromFile("assets/tractor.png"))
        std::cout << "Failed to load tracktor Sprite" << std::endl;
    sf::Sprite tractorSprite;
    tractorSprite.setTexture(tractor);
    tractorSprite.scale(2,2);
    tractorSprite.setPosition(1,TRACTOR_HEIGHT);
    mWindow.draw(tractorSprite);



}


void Game::initFrog() {
    sf::Texture frog;

    if (!frog.loadFromFile("assets/frog.png"))
        std::cout << "Failed to load frog Sprite" << std::endl;

    frogSprite.setTexture(frog);
    frogSprite.setScale(2.0,2.0);
    frogSprite.setPosition(mWindow.getSize().x/2  - frogSprite.getGlobalBounds().width/2 ,mWindow.getSize().y -70); //Initial position of the frog
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
        else if (sf::Event::KeyPressed) {
            std::cout << "Key Pressed" << std::endl;
        }
    }
}


void Game::render() {
   // mWindow.clear();
   // mWindow.display();
}


void Game::update() {

    //All logic goes in here
    //Get current position of frog
        //While frogger is within the road range:
             //If position of frogger == position of any vehicle; Frog Dies (return True) else false and game continues
        //While frogger is within the river range
            //If position of frogger
    //Get new positions of all the vehicles which will be passed to render
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