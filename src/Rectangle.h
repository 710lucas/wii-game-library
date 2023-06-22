#pragma once

#include "misc.h"

class Rectangle : public VisualElement{
	private:
		sizeStruct size;


	public:
		void Rectangle();
		void Rectangle(position pos, sizeStruct	size, u32 color, bool filled);
		void Rectangle(float x, float y, float heigh, float width, u32 color, bool filled);
		void changePosition(float x, float y);
		void setSize(sizeStruct newSize);
		void setSize(float height, float width);
		void increaseSize(sizeStruct amount);
		void increaseSize(float newHeight, float newWidth);

		sizeStruct getSize();
		
	
}
