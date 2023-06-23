#pragma once

#include "misc.h"
#include <grrlib.h>
#include "VisualElement.h"

class Rectangle : public VisualElement{
	private:
		sizeStruct size;


	public:
		Rectangle();
		Rectangle(floatPair pos, sizeStruct	size, u32 color, bool filled);
		Rectangle(float x, float y, float heigh, float width, u32 color, bool filled);
		void changePosition(float x, float y);
		void setSize(sizeStruct newSize);
		void setSize(float height, float width);
		void increaseSize(sizeStruct amount);
		void increaseSize(float newHeight, float newWidth);
		void draw();

		sizeStruct getSize();
		
	
};
