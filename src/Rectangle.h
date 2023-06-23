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
		Rectangle(float x, float y, float width, float height, u32 color, bool filled);
		void changePosition(float x, float y);
		void setSize(sizeStruct newSize);
		void setSize(float width, float height);
		void increaseSize(sizeStruct amount);
		void increaseSize(float newWidth, float newHeight);
		void draw();

		sizeStruct getSize();
		
	
};
