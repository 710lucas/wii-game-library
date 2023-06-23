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

		virtual void setPosition(floatPair pos);
		void setColor(u32 color);
		void setFilled(bool filled);
		virtual void move(floatPair amount);
		virtual void move(float amountX, float amountY);

		floatPair getPosition();
		u32 getColor();
		bool getFilled();

};
