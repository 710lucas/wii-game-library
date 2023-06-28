#ifndef GAME_H
#define GAME_H

#include <grrlib.h>
#include <wiiuse/wpad.h>

namespace Game{

		void init();
		void updateWiimote();
		bool wiimotePressed(ubyte button);
		bool wiimotePressed(int button);
		bool wiimoteHold(int button);
		bool wiimoteHold(ubyte button);
		void render();


};

#endif