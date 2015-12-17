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
        sf::RenderWindow mWindow;
        sf::Event event;
        sf::Sprite frogSprite;
        sf::Sprite tractorSprite;
        sf::Sprite wood1Sprite;
        sf::Font font;

        //The following methods are private because they should not be accessed directly from the main() function
        void processEvents();
        void update();
        void initWindow(); //Add all backgrounds to window
        void initFrog(); //init frog on its position
        void initScorecard(); //init the scoreCard
        void initCars(); //Init random cars
        void initWood(); // Init random wood
        void render();
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
