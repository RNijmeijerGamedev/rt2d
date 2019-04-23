//
//  unit.cpp
//  start
//
//  Created by Ruben Nijmeijer on 26/01/2019.
//

#include "unit.h"

Unit::Unit() : Entity() {
    
    
    selected = false;
    moving = false;
    destination = Vector2();
    //sprite renderer
    this->addSprite("assets/boid.tga");
}

Unit::~Unit() {
    

}

void Unit::update(float deltatime) {
    if (moving == true) {
        
        Vector2 dir = (destination - position);
        dir.normalize();
        position +=(dir * 10) *deltatime;
    }
}


void Unit::IsSelected(){
    std::cout << "selected" << std::endl;
    selected = true;
    sprite()->color = GREEN;
}

void Unit::IsUnSelected(){
    std::cout << "unselected" << std::endl;
    selected = false;
    sprite()->color = RED;
}

void Unit::MoveToLocation(Vector2 destination){
 
}
