//
//  collision.hpp
//  basic3D
//
//  Created by Ruben Nijmeijer on 21/03/2019.
//

#ifndef collision_h
#define collision_h

#include <algorithm>
#include <rt2d/pointx.h>

struct Rectangle {
    float x;
    float y;
    float width;
    float height;
    Rectangle(float x_, float y_, float w, float h) {
        this->x = x_;
        this->y = y_;
        this->width = w;
        this->height = h;
    }
};

class Collider {
    public:
        static bool point2rectangle(const Point2& point, const Rectangle& rect) {
            bool colx = point.x > rect.x && point.x < rect.x + rect.width;
            bool coly = point.y > rect.y && point.y < rect.y + rect.height;
            return colx && coly;
        };
    
    private:
        Collider() {};
    
};


#endif /* collision_h */
