#include "Rectangle.h"

Rectangle::Rectangle(){;}

Rectangle::Rectangle(floatPair pos, sizeStruct size, u32 color, bool filled) : VisualElement(pos, color, filled){

	this->size = size;

}

Rectangle::Rectangle(float x, float y, float width, float height, u32 color, bool filled){

	floatPair p;
	p.x = x;
	p.y = y;
	setPosition(p);

	size.w = width;
	size.h = height;

	setColor(color);
	setFilled(filled);

}

void Rectangle::changePosition(float x, float y){
	floatPair p;
	p.x = x;
	p.y = y;
	setPosition(p);
}


void Rectangle::setSize(float width, float height){
	size.h = height;
	size.w = width;
}

void Rectangle::setSize(sizeStruct newSize){
	setSize(newSize.w, newSize.h);
}

void Rectangle::increaseSize(float width, float height){
	size.h += height;
	size.w += width;
}

void Rectangle::increaseSize(sizeStruct amount){
	increaseSize(amount.h, amount.w);
}

void Rectangle::draw(){
	GRRLIB_Rectangle(getPosition().x, getPosition().y, size.w, size.h, getColor(), getFilled());
}

bool Rectangle::isColidingWith(Rectangle rectangle){

	floatPair pos = this->getPosition();
	sizeStruct size = this->getSize();
	floatPair pos2 = rectangle.getPosition();
	sizeStruct size2 = rectangle.getSize();

	return ((pos.x+size.w >= pos2.x and pos.x <= pos2.x+size2.w) &&
	(pos.y+size.h>=pos2.y and pos.y<=pos2.y+size2.h));

}

sizeStruct Rectangle::getSize(){return size;}

