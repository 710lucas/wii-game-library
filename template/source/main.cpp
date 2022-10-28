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


#include"game-lib.h"

#include "Roboto_ttf.h"
#include "cursor_png.h"
#include "fnaf_test_png.h"

int main(int argc, char **argv) {

    Game g;
    g.init();

    Image ponteiro(cursor_png);
    ponteiro.set_scale(0.25, 0.25);
    Image fnaf(fnaf_test_png, 10, 20);
    fnaf.set_scale(0.5, 0.5);
    GRRLIB_ttfFont *roboto = GRRLIB_LoadTTF(Roboto_ttf, Roboto_ttf_size);

    Text texto(Roboto_ttf, Roboto_ttf_size);

    Rectangle rec(100, 200, 100, 100, 0x00ff00ff, true);

    Rectangle rec2(400, 200, 100, 100, 0xff00ffff, true);

    std::vector<std::vector<int>> teste = {
        {1, 0, 0},
        {1, 1, 1},
        {2, 2, 3}
    };

    Tilemap t(teste);
    Circle c(100, 200, 30, 0xffaa12ff, true);



    int velx = 2;
    int vely = -0;
    int vel2x = 15;
    int vel2y = -2;
    int vel3x = 1;
    int vel3y = -2;
    float x = 0;

    // Loop forever
    while(1) {

        g.update_wiimote();


        // If [PLUS] was pressed on the first Wiimote, break out of the loop

        // if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)  break;
        if(g.wiimote_pressed(WPAD_BUTTON_HOME)) break;

        rec.render();
        rec2.render();
        x+=0.1;
        c.move(cos(pow(x,2)/sin(x))*10, cos(x)*2);

        if(vely > 0){
            texto.set_font_size(texto.get_font_size()+1);
        }

        else if(vely<0 and texto.get_font_size()>0 and rec.get_w() > 0){
            texto.set_font_size(texto.get_font_size()-1);
        }

        texto.print("ROTMG", rec.get_pos().x, rec.get_pos().y);


        if(rec.get_pos().x >= 640-rec.get_w() || rec.get_pos().x<0  or rec.is_colliding(rec2)){
            velx *= -1;
        }
        if(rec.get_pos().y>=480-rec.get_h() || rec.get_pos().y<0 or rec.is_colliding(rec2)){
            vely *= -1;
        }
        if(rec2.get_pos().x >= 640-rec2.get_w() || rec2.get_pos().x<0  or rec2.is_colliding(rec)){
            vel2x *= -1;
        }
        if(rec2.get_pos().y>=480-rec2.get_h() || rec2.get_pos().y<0 or rec2.is_colliding(rec)){
            vel2y *= -1;
        }

        if(fnaf.get_rec().get_pos().y>=480-fnaf.get_rec().get_h() || fnaf.get_rec().get_pos().y<0 or fnaf.get_rec().is_colliding(rec)or fnaf.get_rec().is_colliding(rec2)){
            vel3y *= -1;
        }
        if(fnaf.get_rec().get_pos().x>=640-fnaf.get_rec().get_w() || fnaf.get_rec().get_pos().x<0 or fnaf.get_rec().is_colliding(rec)or fnaf.get_rec().is_colliding(rec2)){
            vel3x *= -1;
        }
        if(rec.clicked(g)){
            rec.set_color(0xff0000ff);
        }
        else
            rec.set_color(0x0000ffff);

        if(rec.is_colliding(rec2))
            rec2.set_color(0x00ffffff);
        else 
            rec2.set_color(0xff00ffff);

        rec.move(velx, vely);
        rec2.move(vel2x, vel2y);
        ponteiro.render(g.ir1.x, g.ir1.y);
        fnaf.move(vel3x, vel3y);
        fnaf.render();
        c.render();

        GRRLIB_Render();  // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}
