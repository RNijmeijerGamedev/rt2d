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

    int counter = 0;
    for (int x=0; x<gridwidth; x++) {
        for (int y=0; y<gridheight ; y++) {
            this->spritebatch()[counter]->frame(rand()%16);
            counter++;
        }
    }
}


Grid::~Grid()
{

}

void Grid::update(float deltatime){
    

    
    std::vector<Sprite*> spritebatch = this->spritebatch();
    int counter = 0;
    for (int x=0; x<gridwidth; x++) {
        for (int y=0; y<gridheight ; y++) {
            Point2 pos = spritebatch[counter]->spriteposition;
            
            int halfwidth = cellwidth/2;
            int halfheight = cellheight/2;
            int left = pos.x - halfwidth;
            int right = pos.x + halfwidth;
            int top = pos.y - halfheight;
            int bottom = pos.y + halfheight;
            
            int mousex = input()->getMouseX() + cam->position.x - SWIDTH/2;
            int mousey = input()->getMouseY() + cam->position.y - SHEIGHT/2;
            
            if ( mousex > left && mousex < right && mousey > top && mousey < bottom ) {
                spritebatch[counter]->color.a = 192;
                if (input()->getMouseDown( 0 )) {
                    spritebatch[counter]->frame(rand()%16);
                }
            } else {
                spritebatch[counter]->color.a = 255;
            }
            counter++;
        }
    }
     
}
