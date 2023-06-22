#include "Game.h"

void Game::init(){
	GRRLIB_Init();
	WPAD_Init();
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);
}

void Game::updateWiimote(){
	WPAD_SetVRes(0, 640, 480);
	WPAD_ScanPads();
	wpadDown = WPAD_ButtonsDown(0);
	wpadHeld = WPAD_ButtonsHeld(0);
	WPAD_IR(WPAD_CHAN_0, &ir1);
}

bool Game::wiimotePressed(ubyte button){
	return wpadDown & button;
}

bool Game::wiimotePressed(int button){
	return wpadDown & button;
}

bool Game::wiimoteHold(int button){
	return wpadHeld & button;
}

bool Game::wiimoteHold(ubyte button){
	return wpadHeld & button;
}

void Game::render(){
	GRRLIB_Render();
}
