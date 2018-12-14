//
//  grid.h
//  start
//
//  Created by Ruben Nijmeijer on 29/11/2018.
//

#ifndef grid_H
#define grid_H

#include <vector>
#include "myentity.h"
#include "scenemanager.h"


struct Cell {
    MyEntity* entity;
    Point_t<int> position;
};

class Grid: public Entity {

public:
    Grid();
    virtual ~Grid();
    void update(float deltatime);
private:
    
    int gridwidth;
    int gridheight;
    int cellwidth;
    int cellheight;
    //int border;
};

#endif /* grid_hpp */
