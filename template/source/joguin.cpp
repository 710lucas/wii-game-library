#include "game-lib.h"

#include "fnaf_test_png.h"

int main(){
    Game g;
    g.init();

    Image player(fnaf_test_png);

    while(1){
        g.update_wiimote();

        if(g.wiimote_pressed(WPAD_BUTTON_HOME)) break;

        if (g.wiimote_pressed(WPAD_BUTTON_UP) or g.wiimote_hold(WPAD_BUTTON_UP))
            player.move(0, 1);
        if (g.wiimote_pressed(WPAD_BUTTON_DOWN) or g.wiimote_hold(WPAD_BUTTON_DOWN))
            player.move(0, -1);
        if (g.wiimote_pressed(WPAD_BUTTON_LEFT) or g.wiimote_hold(WPAD_BUTTON_LEFT))
            player.move(-1, 0);
        if (g.wiimote_pressed(WPAD_BUTTON_RIGHT) or g.wiimote_hold(WPAD_BUTTON_RIGHT))
            player.move(1, 0);

        player.render();

        GRRLIB_Render();
    }
}