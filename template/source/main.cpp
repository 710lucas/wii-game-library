/*===========================================
        GRRLIB (GX Version)
        - Template Code -

        Minimum Code To Use GRRLIB
============================================*/
#include <grrlib.h>

#include <stdlib.h>
#include <wiiuse/wpad.h>
#include <time.h>


#include"game-lib.h"

#include "Roboto_ttf.h"
#include "cursor_png.h"
#include "fnaf_test_png.h"

int main(int argc, char **argv) {

    Game g;
    g.init();

    Image ponteiro(cursor_png);
    ponteiro.set_scale(0.25, 0.25);
    Image fnaf(fnaf_test_png, 100, 200);
    GRRLIB_ttfFont *roboto = GRRLIB_LoadTTF(Roboto_ttf, Roboto_ttf_size);

    Text texto(Roboto_ttf, Roboto_ttf_size);

    Rectangle rec(100, 200, 100, 100, 0x00ff00ff, true);

    Rectangle rec2(400, 200, 100, 100, 0xff00ffff, true);

    int velx = 2;
    int vely = -0;
    int vel2x = 15;
    int vel2y = -2;

    // Loop forever
    while(1) {

        g.update_wiimote();


        // If [PLUS] was pressed on the first Wiimote, break out of the loop

        // if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)  break;
        if(g.wiimote_pressed(WPAD_BUTTON_HOME)) break;


        rec.render();
        rec2.render();

        if(vely > 0){
            texto.set_font_size(texto.get_font_size()+1);
        }

        else if(vely<0 and texto.get_font_size()>0 and rec.get_w() > 0){
            texto.set_font_size(texto.get_font_size()-1);
        }

        texto.print("ROTMG", rec.get_pos().x, rec.get_pos().y);


        if(rec.get_pos().x >= 640-rec.get_w() || rec.get_pos().x<0  or rec.is_coliding(rec2)){
            velx *= -1;
        }
        if(rec.get_pos().y>=480-rec.get_h() || rec.get_pos().y<0 or rec.is_coliding(rec2)){
            vely *= -1;
        }
        if(rec2.get_pos().x >= 640-rec2.get_w() || rec2.get_pos().x<0  or rec2.is_coliding(rec)){
            vel2x *= -1;
        }
        if(rec2.get_pos().y>=480-rec2.get_h() || rec2.get_pos().y<0 or rec2.is_coliding(rec)){
            vel2y *= -1;
        }

        if(rec.clicked(g)){
            rec.set_color(0xff0000ff);
        }
        else
            rec.set_color(0x0000ffff);

        if(rec.is_coliding(rec2))
            rec2.set_color(0x00ffffff);
        else 
            rec2.set_color(0xff00ffff);

        rec.move(velx, vely);
        rec2.move(vel2x, vel2y);
        ponteiro.render(g.ir1.x, g.ir1.y);
        fnaf.render();

        GRRLIB_Render();  // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}
