#include "Game.h"

namespace Game{

	void init(){
		GRRLIB_Init();
		WPAD_Init();
		WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);
	}

	void updateWiimote(){
		WPAD_SetVRes(0, 640, 480);
		WPAD_ScanPads();
		wpadDown = WPAD_ButtonsDown(0);
		wpadHeld = WPAD_ButtonsHeld(0);
		WPAD_IR(WPAD_CHAN_0, &ir1);
	}

	bool wiimotePressed(ubyte button){
		return wpadDown & button;
	}

	bool wiimotePressed(int button){
		return wpadDown & button;
	}

	bool wiimoteHold(int button){
		return wpadHeld & button;
	}

	bool wiimoteHold(ubyte button){
		return wpadHeld & button;
	}

	void render(){
		GRRLIB_Render();
	}

}