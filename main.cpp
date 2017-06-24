#include "Game.h"

int main() {
    //Program entry point
    Game game;


    //Game Loop
    while(!game.GetWindow()->is_Done()){

        //managing inputs
        game.HandleInput();

        //updating game
        game.Update();

        //Showing entities and tiles
        game.Render();

        //process state requests and reset clock for next frame
        game.LateUpdate();
    }

    return 0;
}