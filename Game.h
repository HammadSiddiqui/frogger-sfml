//
// Created by Hammad Siddiqui on 12/15/15.
//

#ifndef FROGGER_GAME_H
#define FROGGER_GAME_H


#include <SFML/Graphics.hpp>

class Game {
    private:
        sf::RenderWindow mWindow;
        sf::Sprite frogSprite;
        sf::Font font;
        sf::Color blueColor;

    public:
        Game(); //Constructor would call all init's
        void initWindow(); //Add all backgrounds to window
        void initFrog(); //init frog on its position
        void initScorecard(); //init the scoreCard
        void initCarsAndWood(); //Init random cars and wood and also program their movement operation
        void update(); //update car positions and scorecard score and frog's position based on user input.
        void run(); //While Window open
        void processEvents();
        void welcomeScreen();
        void render();


};


#endif //FROGGER_GAME_H
