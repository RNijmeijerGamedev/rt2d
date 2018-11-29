//
//  grid.hpp
//  start
//
//  Created by Ruben Nijmeijer on 29/11/2018.
//

#ifndef grid_H
#define grid_H

#include <vector>
#include <vector>
#include "myentity.h"
#include "gamescene.h"

struct Cell {
    MyEntity* entity;
    Point_t<int> position;
};

class Grid: public Entity {

public:
    Grid();
    virtual ~Grid();
private:
    MyEntity* grid;
    std::vector<Cell*> cells;
    
    int gridwidth;
    int gridheight;
    int cellwidth;
    int cellheight;
    int border;
};

#endif /* grid_hpp */
