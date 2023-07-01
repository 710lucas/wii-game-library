#include "Collision.h"

Collision::Collision(int type){
    this->collisionType = type;
}

Collision::Collision(int type, int distance) : Collision(type){
    this->distanceTillCollision = distance;
}

Collision::Collision(){;}

bool Collision::isVertical(){
    return collisionType == 0;
}

bool Collision::isHorizontal(){
    return collisionType == 1;
}

bool Collision::isDiagonal(){
    return collisionType == 2;
}


bool Collision::isColiding(){
    return collisionType != -1;
}

void Collision::setType(int type){
    this->collisionType = type;
}
void Collision::setDistance(int distance){
    this->distanceTillCollision = distance;
}

int Collision::getDistance(){
    return distanceTillCollision;
}
