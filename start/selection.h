//
//  selected.hpp
//  start
//
//  Created by Ruben Nijmeijer on 27/01/2019.
//

#ifndef selection_h
#define selection_h


#include "unit.h"
#include <stdio.h>

class Selection: public Entity{
    
    
public:
    Selection();
    virtual ~Selection();
    void update(float deltatime);
    
private:
    
};



#endif /* selected_hpp */
