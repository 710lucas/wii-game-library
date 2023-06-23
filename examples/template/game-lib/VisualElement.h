#pragma once

#include "misc.h"
#include <grrlib.h>


class VisualElement{

	private:
		floatPair pos;
		u32 color;
		bool filled;


	public:
		VisualElement();
		VisualElement(floatPair pos, u32 color, bool filled);

		void setPosition(floatPair pos);
		void setColor(u32 color);
		void setFilled(bool filled);
		void move(floatPair amount);
		void move(float amountX, float amountY);

		floatPair getPosition();
		u32 getColor();
		bool getFilled();

};
