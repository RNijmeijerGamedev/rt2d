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

class Unit: public Entity {
    
public:
    Unit();
    virtual ~Unit();
    void update(float deltatime);
private:
    
};
#endif /* unit_h */
