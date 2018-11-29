//
//  grid.cpp
//  start
//
//  Created by Ruben Nijmeijer on 29/11/2018.
//

#include "grid.h"

Grid::Grid() : Entity() {
    // grid size
    gridwidth = 24;
    gridheight = 16;
    cellwidth = 64;
    cellheight = 64;
    // create cells
    for (int x=0; x<gridwidth; x++) {
        for (int y=0; y<gridheight; y++) {
            Cell* cell = new Cell();
            cell->position.x = x;
            cell->position.y = y;
            
            cell->entity = new MyEntity();
            cell->entity->addSprite(AUTOGENWHITE);
            cell->entity->sprite()->size.x = cellwidth;
            cell->entity->sprite()->size.y = cellheight;
            cell->entity->sprite()->color = GRAY;
            
            cell->entity->position.x = x*(cellwidth+border);
            cell->entity->position.y = y*(cellheight+border);
            
            cells.push_back(cell);
            grid->addChild(cell->entity);
            //layers[0]->addChild(grid);

        }
    }
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
    
    //delete grid;
}
