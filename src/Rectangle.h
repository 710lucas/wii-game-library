#pragma once

#include "misc.h"

class Rectangle{
	private:
		position pos;
		sizeStruct size;
		u32 color;
		bool filled;


	public:
		void Rectangle();
		void Rectangle(position pos, sizeStruct	size, u32 color, bool filled);
		void Rectangle(float x, float y, float heigh, float width, u32 color, bool filled);
		void move(float x, float y);
		void move(position amount);
		void changePosition(float x, float y);
		void changePosition(position newPosition);
		void changeColor(u32 color);
		void setFilled(bool filled);
		void setSize(sizeStruct newSize);
		void setSize(float height, float width);
		void increaseSize(sizeStruct amount);
		void increaseSize(float newHeight, float newWidth);

		position getPosition();
		sizeStruct getSize();
		u32 getColor();
		bool getFilled();
		
	
}
