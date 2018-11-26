/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"

MyScene::MyScene() : Scene() {
    // grid settings
    //text[0]->message("TEST TEST HELLO WORLD");
    gridwidth = 24;
    gridheight = 16;
    cellwidth = 64;
    cellheight = 64;
    border = 1;
    
    // create grid
    grid = new MyEntity();
    int xgridpos = (SWIDTH/2) - (gridwidth*(cellwidth+border) / 2);
    int ygridpos = (SHEIGHT/2) - (gridheight*(cellheight+border) /2);
    grid->position = Point2(xgridpos, ygridpos);
    // create cells
    for (int x=0; x<gridheight; x++) {
        for (int y=0; y<gridheight; y++) {
            Cell* cell = new Cell();
            cell->position.x = x;
            cell->position.y = y;
            
            cell->entity = new MyEntity();
            cell->entity->addSprite(AUTOGENWHITE);
            cell->entity->sprite()->size.x = cellwidth;
            cell->entity->sprite()->size.y = cellheight;
            cell->entity->sprite()->color = GRAY;
            
            // initial position
            cell->entity->position.x = x*(cellwidth+border);
            cell->entity->position.y = y*(cellheight+border);
            
            cells.push_back(cell);
            grid->addChild(cell->entity);
            //layers[0]->addChild(grid);
        }
    }
}


MyScene::~MyScene() {
    
    int s = cells.size();
    for (int i=0; i<s; i++) {
        //layers[0]->removeChild(cells[i]->entity);
        delete cells[i]->entity;
        delete cells[i];
        cells[i] = NULL;
    }
    cells.clear();
    
    delete grid;
}

void MyScene::update(float deltaTime) {

}

