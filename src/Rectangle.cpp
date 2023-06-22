#include "rectangle.h"

Rectangle::Rectangle(){

	this.pos = position;
	this.size = sizeStruct;
	this.color = 0x00000000;
	this.filled = true;

}

Rectangle::Rectangle(position pos, sizeStruct size, u32 color, bool filled){

	this.pos = pos;
	this.size = size;
	this.color = color;
	this.filled = filled;

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

void Rectangle::changePosition(position newPosition){
	changePosition(newPosition.x, newPosition.y);
}

void changeColor(u32 color){
	this.color = color;
}

void setFilled(bool filled){
	this.filled = filled;
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

position getPosition(){return position;}
sizeStruct getSize(){return size;}
u32 getColor(){return color;}
bool getFilled(){return filled;}

