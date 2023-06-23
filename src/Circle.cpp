#include "Circle.h"

Circle::Circle(floatPair pos, f32 radius, u32 color, bool filled) : VisualElement(pos, color, filled){
	this->radius = radius;
}

Circle::Circle(float x, float y, f32 radius, u32 color, bool filled){
	floatPair p;
	p.x = x;
	p.y = y;

	setPosition(p);
	setRadius(radius);
	setColor(color);
	setFilled(filled);

}

void Circle::setRadius(f32 newRadius){
	this->radius = newRadius;
}
void Circle::draw(){
	GRRLIB_Circle(getPosition().x, getPosition().y, getRadius(), getColor(), getFilled());
}

f32 Circle::getRadius(){
	return radius;
}

