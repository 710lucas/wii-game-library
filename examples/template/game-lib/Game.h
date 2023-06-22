#pragma once

#include <grrlib.h>
#include <wiiuse/wpad.h>

class Game{

	public:
		void init();
		void updateWiimote();
		bool wiimotePressed(ubyte button);
		bool wiimotePressed(int button);
		bool wiimoteHold(int button);
		bool wiimoteHold(ubyte button);
		void render();
	private:
		ir_t ir1;
		u32 wpadDown, wpadHeld;

};
