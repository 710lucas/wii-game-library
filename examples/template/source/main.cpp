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
#include "Sprite.h"
#include "Image.h"

#include "cursor_png.h"
#include "fnaf_test_png.h"
#include "sprite_png.h"


int main(int argc, char **argv) {

    Game::init();

    Rectangle rec(630, 0, 10, 480, 0xff00ffff, true);
    Circle circ(10, 200, 50, 0xff00ffff, true);
    Image cursor(cursor_png, floatPair{10,10},floatPair{1, 1},0,0xffffffff);
    Image fnaf(fnaf_test_png, floatPair{120,120},floatPair{1, 1},0,0xffffffff);
    floatPair velocity{2, 2};
    floatPair spriteVelocity{2, 2};
    Sprite sprite(sprite_png, u32Pair{16, 16}, floatPair{30, 50}, floatPair{4, 4}, 0, 0xffffffff);

    int wait = 0;


    // Loop forever
    while(1) {

        Game::updateWiimote();
        wait++;
	
        rec.draw();
        circ.draw();
        cursor.draw();
        fnaf.draw();
        if(wait > 5){
            wait = 0;
            sprite.nextFrame();
        }
        if(sprite.getFrame()*sprite.getTileSize().x >= sprite.getTexture()->w){
            sprite.setFrame(0);
        }
        sprite.draw(); 

        sprite.move(spriteVelocity);
        if(sprite.getPosition().x+sprite.getHitbox().getSize().w >= 640 || sprite.getPosition().x<=0){
                spriteVelocity.x*=-1;
        }
        if(sprite.getPosition().y+sprite.getHitbox().getSize().h >= 480 || sprite.getPosition().y <= 0){
                spriteVelocity.y*=-1;
        }

        if(fnaf.getPosition().x+fnaf.getHitbox().getSize().w >= 640 || fnaf.getPosition().x<=0){
                velocity.x*=-1;
        }
        if(fnaf.getPosition().y+fnaf.getHitbox().getSize().h >= 480 || fnaf.getPosition().y <= 0){
                velocity.y*=-1;
                rec.setSize(10, 200);
        }

        fnaf.move(velocity);
        rec.move(-0.01, 0);
        fnaf.getHitbox().draw();


        // if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)  break;
        if(Game::wiimotePressed(WPAD_BUTTON_HOME)) break;


	Game::render();
        //GRRLIB_Render();  // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}
