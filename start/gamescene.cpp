/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include "gamescene.h"
#include "scenemanager.h"


GameScene::GameScene() : SceneManager()
{
    
    /// this doesnt work yet
    //// but now it does
    grid = new Grid();
    this->addChild(grid);
    
    MyEntity *e = new MyEntity();
    this->addChild(e);
	
    // start the timer.
    //
	t.start();

}


GameScene::~GameScene()
{

}

void GameScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
        
	}
    SceneManager::update(deltaTime);
    SceneManager::moveCamera(deltaTime);
    

}
