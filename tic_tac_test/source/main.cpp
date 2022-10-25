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

int main(int argc, char **argv) {

    Game g;
    g.init();

    GRRLIB_texImg *ponteiro = GRRLIB_LoadTexture(cursor_png);
    GRRLIB_ttfFont *roboto = GRRLIB_LoadTTF(Roboto_ttf, Roboto_ttf_size);

    Rectangle rec(100, 20, 100, 200, 0x00ff00ff, true);

    // Loop forever
    while(1) {

        g.update_wiimote();


        // If [PLUS] was pressed on the first Wiimote, break out of the loop
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_PLUS)  break;

        GRRLIB_Rectangle(288, 156, 7, 169, 0x147878FF, true); 
        rec.render();
        rec.move(1, 1);

        GRRLIB_DrawImg(g.ir1.x, g.ir1.y, ponteiro, 0, 0.25, 0.25, 0xffffffff);

        GRRLIB_Render();  // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}
