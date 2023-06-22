#pragma once

#include "misc.h"
#include <grrlib.h>


class VisualElement{

	private:
		position pos;
		u32 color;
		bool filled;


	public:
		VisualElement();
		VisualElement(position pos, u32 color, bool filled);

		void setPosition(position pos);
		void setColor(u32 color);
		void setFilled(bool filled);
		void move(position amount);
		void move(float amountX, float amountY);

		position getPosition();
		u32 getColor();
		bool getFilled();

};
