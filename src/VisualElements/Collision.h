#pragma once

class Collision{


    public:
        Collision(int type);
        Collision(int type, int distance);
        Collision();

        bool isVertical();
        bool isHorizontal();
        bool isDiagonal();
        bool isColiding();

        void setType(int type);
        void setDistance(int distance);

        int getDistance();


    private:
        int collisionType; //0-> vertical; 1-> horizontal; 2->diagonal; -1 -> no collision
        int distanceTillCollision;

};