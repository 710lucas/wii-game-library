#pragma once
#include "Rectangle.h"
#include <grrlib.h>

class Circle : public VisualElement{

	public:
		Circle(floatPair pos, f32 radius, u32 color, bool filled);
		Circle(float x, float y, f32 radius, u32 color, bool filled);

		void setRadius(f32 newRadius);
		void draw();
		
		f32 getRadius();

	private:
		f32 radius;


};
