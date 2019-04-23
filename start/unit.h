//
//  unit.hpp
//  start
//
//  Created by Ruben Nijmeijer on 26/01/2019.
//

#ifndef unit_h
#define unit_h

#include "myentity.h"
#include <stdio.h>
#include <vector>
#include "scenemanager.h"
#include <rt2d/scene.h>
#include <input.h>
#include "grid.h"
//#include "gamescene.h"

class Unit: public Entity {
    
public:
    Unit();
    virtual ~Unit();
    void update(float deltatime);
    void MoveToLocation(Vector2);
    void IsSelected();
    void IsUnSelected();
    bool selected;
    bool moving;
    Vector2 destination;
    
    
private:
};
#endif /* unit_h */
