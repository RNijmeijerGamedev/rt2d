//
//  unit.cpp
//  start
//
//  Created by Ruben Nijmeijer on 26/01/2019.
//

#include "unit.h"

Unit::Unit() : Entity() {
    
    
    
    //sprite renderer
    this->addSprite("assets/boid.tga");
}

Unit::~Unit() {
    

}

void Unit::update(float deltatime) {
    //if (this->input()->getMouseDown( 0 )) {
        //this->color = RED;
    }


void IsSelected(){
    //std::cout << "selected";
}

void MoveToLocation(){
    
}
