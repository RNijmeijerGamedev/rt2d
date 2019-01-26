//
//  unit.cpp
//  start
//
//  Created by Ruben Nijmeijer on 26/01/2019.
//

#include "unit.h"

Unit::Unit() : Entity() {
    
    
    
    //sprite
    this->addSprite("assets/boid.tga");
}

Unit::~Unit() {
    

}

void Unit::update(float deltatime) {
    
}
