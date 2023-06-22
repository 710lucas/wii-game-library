#include "rectangle.h"

Rectangle::Rectangle(){;}

Rectangle::Rectangle(position pos, sizeStruct size, u32 color, bool filled) : VisualElement(pos, color, filled){

	this.size = size;

}

Rectangle::Rectangle(float x, float y, float height, float width, u32 color, bool filled){

	this.pos.x = x;
	this.pos.y = y;
	this.size.w = width;
	this.size.h = height;
	this.color = color;
	this.filled = filled;

}


void Rectangle::move(float x, float y){
	position.x+=x;
	position.y+=y;
}

void Rectangle::move(position amount){
	move(amount.x, amount.y);
}

void Rectangle::changePosition(float x, float y){
	position.x = x;
	position.y = y;
}


void setSize(float height, float width){
	this.size.h = height;
	this.size.w = width;
}

void setSize(sizeStruct newSize){
	setSize(newSize.h, newSize.w);
}

void increaseSize(float height, float width){
	size.h += height;
	size.w += width;
}

void increaseSize(sizeStruct amount){
	increaseSize(amount.h, amount.w);
}

sizeStruct getSize(){return size;}

