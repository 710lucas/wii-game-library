#include "Rectangle.h"

Rectangle::Rectangle(){;}

Rectangle::Rectangle(position pos, sizeStruct size, u32 color, bool filled) : VisualElement(pos, color, filled){

	this->size = size;

}

Rectangle::Rectangle(float x, float y, float height, float width, u32 color, bool filled){

	position p;
	p.x = x;
	p.y = y;
	setPosition(p);

	size.w = width;
	size.h = height;

	setColor(color);
	setFilled(filled);

}

void Rectangle::changePosition(float x, float y){
	position p;
	p.x = x;
	p.y = y;
	setPosition(p);
}


void Rectangle::setSize(float height, float width){
	size.h = height;
	size.w = width;
}

void Rectangle::setSize(sizeStruct newSize){
	setSize(newSize.h, newSize.w);
}

void Rectangle::increaseSize(float height, float width){
	size.h += height;
	size.w += width;
}

void Rectangle::increaseSize(sizeStruct amount){
	increaseSize(amount.h, amount.w);
}

void Rectangle::draw(){
	GRRLIB_Rectangle(getPosition().x, getPosition().y, size.w, size.h, getColor(), getFilled());
}

sizeStruct Rectangle::getSize(){return size;}

