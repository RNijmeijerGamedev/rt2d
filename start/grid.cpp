//
//  grid.cpp
//  start
//
//  Created by Ruben Nijmeijer on 29/11/2018.
//

#include "grid.h"

Grid::Grid() : Entity(){
    // grid size
    gridwidth = 128;
    gridheight = 128;
    cellwidth = 64;
    cellheight = 64;
    // create cells
    this->addGrid("assets/default.tga", 8, 8, gridwidth, gridheight, cellwidth, cellheight);
}


Grid::~Grid()
{

}

void Grid::update(float deltatime){
    
    
}
