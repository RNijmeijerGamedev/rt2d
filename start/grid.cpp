//
//  grid.cpp
//  start
//
//  Created by Ruben Nijmeijer on 29/11/2018.
//

#include "grid.h"

Grid::Grid() : Entity(){
    cells = std::vector<Cell*>();
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
    int s = cells.size();
    for (int i=0; i<s; i++) {
        //layers[0]->removeChild(cells[i]->entity);
        delete cells[i]->entity;
        delete cells[i];
        cells[i] = nullptr;
    }
    cells.clear();
}

void Grid::update(float deltatime){
    
}
