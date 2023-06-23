/*===========================================
        GRRLIB (GX Version)
        - Template Code -

        Minimum Code To Use GRRLIB
============================================*/
#include <grrlib.h>

#include <stdlib.h>
#include <wiiuse/wpad.h>
#include <time.h>
#include <math.h>


#include "Game.h"
#include "Rectangle.h"
#include "Circle.h"


int main(int argc, char **argv) {

    Game::init();

    Rectangle rec(10, 10, 10, 100, 0x1233ffff, true);
    Circle circ(10, 200, 50, 0xff00ffff, true);

    // Loop forever
    while(1) {

        Game::updateWiimote();
	
	rec.draw();
	circ.draw();

        // if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)  break;
        if(Game::wiimotePressed(WPAD_BUTTON_HOME)) break;


	Game::render();
        //GRRLIB_Render();  // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}
