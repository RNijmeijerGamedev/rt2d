//
//  scenemanager.hpp
//  basic3D
//
//  Created by Ruben Nijmeijer on 13/12/2018.
//

#ifndef scenemanager_h
#define scenemanager_h

#include <vector>
#include <rt2d/scene.h>
#include <rt2d/text.h>
#include "myentity.h"

struct Player
{
    int mouseclicks = 0;
};

class SceneManager: public Scene
{
public:
    SceneManager();
    virtual ~SceneManager();
    
    // must be explicitly called from subclass
    virtual void update(float deltaTime);
    void addPlayer(Player* p) { player = p; };
    
    static int activescene;
    
protected:
    unsigned int top_layer;
    std::vector<MyEntity*> layers;
    std::vector<Text*> text;
    Player* player;
    void moveCamera(float deltaTime);
    
private:
    MyEntity* logo;
    Timer fpstimer;
};

#endif /* scenemanager_h */
