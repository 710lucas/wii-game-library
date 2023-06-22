#include "Circle.h"

Circle::Circle(position pos, f32 radius, u32 color, bool filled) : VisualElement(pos, color, filled){
	this.radius = radius;
}

Circle::Circle(float x, float y, f32 radius, u32 color, bool filled){
	position p;
	p.x = x;
	p.y = y;
	Circle(p,radius, color, filled);
}

void Circle::setRadius(f32 newRadius){
	this.radius = newRadius;
}

f32 Circle::getRadius(){
	return radius;
}

