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
#include "Image.h"

#include "cursor_png.h"
#include "fnaf_test_png.h"


int main(int argc, char **argv) {

    Game::init();

    Rectangle rec(10, 10, 10, 100, 0x1233ffff, true);
    Circle circ(10, 200, 50, 0xff00ffff, true);
    Image cursor(cursor_png, floatPair{10,10},floatPair{1, 1},0,0xffffffff);
    Image fnaf(fnaf_test_png, floatPair{120,120},floatPair{0.2, 0.2},0,0xffffffff);
    floatPair velocity{10, 10};

    // Loop forever
    while(1) {

        Game::updateWiimote();
	
	rec.draw();
	circ.draw();
        cursor.draw();
        fnaf.draw();

        if(fnaf.getPosition().x+fnaf.getHitbox().getSize().w >= 640 || fnaf.getPosition().x<=0){
                velocity.x*=-1;
        }
        if(fnaf.getPosition().y+fnaf.getHitbox().getSize().h >= 480 || fnaf.getPosition().y <= 0){
                velocity.y*=-1;
        }

        fnaf.move(velocity);

        // if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)  break;
        if(Game::wiimotePressed(WPAD_BUTTON_HOME)) break;


	Game::render();
        //GRRLIB_Render();  // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}
