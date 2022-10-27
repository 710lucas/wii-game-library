#include "game-lib.h"


void Game::init(){
    GRRLIB_Init();
    WPAD_Init();
    WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);
}

void Game::update_wiimote(){

        WPAD_SetVRes(0, 640, 480);
        WPAD_ScanPads();
        wpaddown = WPAD_ButtonsDown(0);
        wpadheld = WPAD_ButtonsHeld(0);


        WPAD_IR(WPAD_CHAN_0, &ir1);
}


bool Game::wiimote_pressed(ubyte button){
    if (wpaddown & button) return true;
    return false;
}
