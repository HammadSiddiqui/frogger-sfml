//
// Created by Hammad Siddiqui on 12/15/15.
//

#ifndef FROGGER_GAME_H
#define FROGGER_GAME_H


#define ROAD_ROW_1_HEIGHT 290
#define ROAD_ROW_2_HEIGHT 315
#define ROAD_ROW_3_HEIGHT 355
#define ROAD_ROW_4_HEIGHT 379
#define ROAD_ROW_5_HEIGHT 415
#define WOOD_ROW_1 100

#include <SFML/Graphics.hpp>

class Game {
    private:
        int score;
        sf::RenderWindow mWindow;
        sf::Event event;
        sf::Text scoreText;
        sf::Sprite frogSprite;
        sf::Sprite tractorSprite[4];
        sf::Sprite truckSprite[4];
        sf::Sprite car1Sprite;
       // sf::Sprite car2Sprite;
        sf::Sprite car2Sprite[4];
        sf::Sprite car3Sprite[4];
        sf::Sprite wood1Sprite;
        sf::Font font;

        //The following methods are private because they should not be accessed directly from the main() function
        void processEvents(); //Continuous fire of Events from the mWindow into the Event Queue.
        void update(); //Performs all the logic based on the Events in the Event Queue
        void initWindow(); //Adds static background (Grass and Roads) to mWindow object
        void initFrog(); //init frog on its position
        void initScorecard(); //init the scoreCard
        void initCars(); //Init random cars
        void initWood(); // Init random wood
        void render(); //Calls all renders after the sprite positions are updated
        void renderFrog(); //Render the frog based on its new updated position
        void renderCars();
        void renderScoreCard();
        void handlePlayerInput(sf::Keyboard::Key key,
       bool isPressed);

    public:
        bool mIsMovingUp, mIsMovingDown, mIsMovingLeft,mIsMovingRight;
        Game(); //Constructor would call all init's
         //calls process, update and render methods from private.
        void run(); //While Window open

   //     void welcomeScreen();



};


#endif //FROGGER_GAME_H
