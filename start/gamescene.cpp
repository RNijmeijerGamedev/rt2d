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
    grid->setCamera(camera());
    MyEntity *e = new MyEntity();
    this->addChild(e);
    unit = new Unit();
    unit->position = Vector2(1,1);
    
    this->addChild(unit);
    //selectionStarted = false;
    //biggestX = 0;
    //biggestY = 0;
    //smallestX = 0;
    //smallestY = 0;
	
    //layers[0]->addChild(grid);
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
    
    /*if (input()->getMouseDown( 0 ) && !selectionStarted) {
        mouseX = input()->getMouseX();
        mouseY = input()->getMouseY();
        location1 = Vector2(mouseX, mouseY);
        selectionStarted = true;
        std::cout<< location1 << std::endl;
        std::cout<< selectionStarted << std::endl;
    } else if(input()->getMouseUp( 0 ) && selectionStarted){
        mouseX = input()->getMouseX();
        mouseY = input()->getMouseY();
        location2 = Vector2(mouseX, mouseY);
        selectionStarted = false;
        std::cout<< location2 << std::endl;
        std::cout<< selectionStarted << std::endl;
    }
    
    compareXY(location1, location2);
    measureSelection();
}
void GameScene::compareXY(Vector2 a, Vector2 b){
    if(a.x > b.x){
        biggestX = a.x;
        smallestX = b.x;
    }
    if(a.y > b.y){
        biggestY = a.y;
        smallestY = b.y;
    }
    if(a.x < b.x){
        smallestX = a.x;
        biggestX = b.x;
    }
    if(a.y < b.y){
        smallestY = a.y;
        biggestY = b.y;
    }
    
    
}

void GameScene::measureSelection(){
    if(unit->position.x < smallestX && unit->position.x > biggestX &&
       unit->position.y < smallestX && unit->position.y > biggestY){
        std::cout << "its in bois" << std::endl ;
    }*/
}
