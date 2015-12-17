//
// Created by Hammad Siddiqui on 12/15/15.
//

#include "Game.h"
#include <iostream>


/*
 * Constructor creates an empty window object of size 640x480 pixels
 * And then, it calls all the initialization of other elements.
 * */
Game::Game() : mWindow(sf::VideoMode(450,520,32),"Frogger"), scoreText("121", font, 11)  {

    mWindow.setFramerateLimit(10);
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
    initCars();
    initFrog();
    initWood();
    initScorecard();
   //mWindow.display();


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


void Game::initCars() {

    //Init truck
    sf::Texture truck;
    truck.loadFromFile("assets/truck.png");


    sf::Texture car3;
    car3.loadFromFile("assets/car3.png");

    sf::Texture car1;
    car1.loadFromFile("assets/car1.png");

    sf::Texture car2;
    car2.loadFromFile("assets/car2.png");

    sf::Texture tractor;
    if(!tractor.loadFromFile("assets/tractor.png"))
        std::cout << "Failed to load tracktor Sprite" << std::endl;




    //Init car1


    car1Sprite.setTexture(car1);
    car1Sprite.scale(2,2);
    car1Sprite.setPosition(1,ROAD_ROW_2_HEIGHT);
    mWindow.draw(car1Sprite);



    for (int i = 0; i < 4; ++i) {
        truckSprite[i].setTexture(truck);
        truckSprite[i].scale(2,2);
        truckSprite[i].setPosition(70 + (i*120),ROAD_ROW_1_HEIGHT);
        mWindow.draw(truckSprite[i]);

        car2Sprite[i].setTexture(car2);
        car2Sprite[i].scale(2,2);
        car2Sprite[i].setPosition(70 + (i*120), ROAD_ROW_3_HEIGHT);
        mWindow.draw(car2Sprite[i]);

        car3Sprite[i].setTexture(car3);
        car3Sprite[i].scale(2,2);
        car3Sprite[i].setPosition(170 + (i*120), ROAD_ROW_5_HEIGHT);
        mWindow.draw(car3Sprite[i]);

        tractorSprite[i].setTexture(tractor);
        tractorSprite[i].scale(2,2);
        tractorSprite[i].setPosition(120 + (i*120), ROAD_ROW_4_HEIGHT);
        mWindow.draw(tractorSprite[i]);
    }
    //Init tractor




}


void Game::renderCars() {
    //Code

    //Init truck
    sf::Texture truck;
    truck.loadFromFile("assets/truck.png");

    sf::Texture car3;
    car3.loadFromFile("assets/car3.png");

    sf::Texture car2;
    car2.loadFromFile("assets/car2.png");

    //Tractor
    sf::Texture tractor;
    if(!tractor.loadFromFile("assets/tractor.png"))
        std::cout << "Failed to load tracktor Sprite" << std::endl;

    for (int i = 0; i < 4; ++i) {
        tractorSprite[i].setTexture(tractor);
        mWindow.draw(tractorSprite[i]);


        truckSprite[i].setTexture(truck);
        mWindow.draw(truckSprite[i]);

        car3Sprite[i].setTexture(car3);
        //  car2Sprite[i].setPosition(1 + (i*10), ROAD_ROW_3_HEIGHT);
        mWindow.draw(car3Sprite[i]);

        car2Sprite[i].setTexture(car2);
        //car2Sprite[i].setPosition(1 + (i*10), ROAD_ROW_3_HEIGHT);
        mWindow.draw(car2Sprite[i]);
    }




}

void Game::initWood() {

    //Init woods
    sf::Texture wood1;
    if(!wood1.loadFromFile("assets/wood.png"))
        std::cout << "Failed to load wood Sprite" << std::endl;

    wood1Sprite.setTexture(wood1);
    wood1Sprite.scale(2,2);
    wood1Sprite.setPosition(1,WOOD_ROW_1);
    mWindow.draw(wood1Sprite);
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


void Game::renderFrog() {
    sf::Texture frog;

    if (!frog.loadFromFile("assets/frog.png"))
        std::cout << "Failed to load frog Sprite" << std::endl;

    frogSprite.setTexture(frog);
    frogSprite.setScale(2.0,2.0);
    //frogSprite.setPosition(mWindow.getSize().x/2  - frogSprite.getGlobalBounds().width/2 ,mWindow.getSize().y -70); //Initial position of the frog
    mWindow.draw(frogSprite);
}



void Game::initScorecard() {


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

    while(mWindow.pollEvent(event)) {

        switch (event.type) {
            case sf::Event::KeyPressed :
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased :
                handlePlayerInput(event.key.code, false);
                break;

            case sf::Event::Closed:
                mWindow.close();
                break;

            default:
                continue;
        }



    }
}


void Game::render() {
    mWindow.clear(sf::Color::Transparent);
    initWindow();
    renderFrog();
    renderCars();
    mWindow.draw(scoreText);
    mWindow.display();
}


void Game::update() {

    //All logic goes in here
    //Get current position of frog
        //While frogger is within the road range:
             //If position of frogger == position of any vehicle; Frog Dies (return True) else false and game continues
        //While frogger is within the river range
            //If position of frogger
    //Get new positions of all the vehicles which will be passed to render
    sf::Vector2f movement(0, 0);

    if (mIsMovingUp)
        movement.y -= 15;
    else if (mIsMovingDown)
        movement.y += 15;
    else if (mIsMovingLeft)
        movement.x -= 20;
    else if (mIsMovingRight)
        movement.x += 20;


    if(frogSprite.getPosition().x > 420){
        frogSprite.setPosition(420, frogSprite.getPosition().y);
        movement.x = 0;
        movement.y = 0;
    }
    else if (frogSprite.getPosition().y > 450) {
        frogSprite.setPosition(frogSprite.getPosition().x, 450);
        movement.x = 0;
        movement.y = 0;
    }
    else if(frogSprite.getPosition().x < 0){
        frogSprite.setPosition(0, frogSprite.getPosition().y);
        movement.x = 0;
        movement.y = 0;
    }

    else if(frogSprite.getPosition().y < 63){
        frogSprite.setPosition(frogSprite.getPosition().x, 63);
        movement.x = 0;
        movement.y = 0;
    }

    frogSprite.move(movement);


    //std::cout << movement.x << ", " << movement.y << std::endl;
    std::cout << frogSprite.getPosition().x << ", " << frogSprite.getPosition().y << std::endl;


    //Truck Sprite Movement
    sf::Vector2f leftMovement(-3, 0);
    sf::Vector2f rightMovement(3, 0);


    for (int i = 0; i < 4; ++i) {

        if(truckSprite[i].getPosition().x < -55) {
            truckSprite[i].setPosition(450, ROAD_ROW_1_HEIGHT);
        }
        truckSprite[i].move(leftMovement);

        car2Sprite[i].move(leftMovement);

        if(car2Sprite[i].getPosition().x < -55) {
            car2Sprite[i].setPosition(450, ROAD_ROW_3_HEIGHT);
        }

        car3Sprite[i].move(leftMovement);

        if(car3Sprite[i].getPosition().x < -55) {
            car3Sprite[i].setPosition(450, ROAD_ROW_5_HEIGHT);
        }

        tractorSprite[i].move(rightMovement);

        if(tractorSprite[i].getPosition().x > 450) {
            tractorSprite[i].setPosition(-10, ROAD_ROW_4_HEIGHT);
        }
    }






}



void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {

    if(key == sf::Keyboard::Up){
        mIsMovingUp = isPressed;
       // std::cout << "Up Pressed" << std::endl;
    }
    else if (key == sf::Keyboard::Down)
        mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::Left)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::Right)
        mIsMovingRight = isPressed;

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