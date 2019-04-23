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
    unit->position = Vector2(25,25);
    unit->sprite()->color = RED;
    
    grid->addChild(unit);
    selectionStarted = false;
    destinationSet = false;
    // Smallest = Begin
    // Biggest = end
    biggestX = 0;
    biggestY = 0;
    smallestX = 0;
    smallestY = 0;
	
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
   
    if(input()->getMouseDown( 0 ) && !selectionStarted) {
        mousex = input()->getMouseX() + camera()->position.x - SWIDTH/2;
        mousey = input()->getMouseY() + camera()->position.y - SHEIGHT/2;
        //mousex = input()->getMouseX();
        //mousey = input()->getMouseY();
        std::cout << "Mouse X:" << std::endl;
        std::cout << mousex << std::endl;
        std::cout << "Mouse Y:" << std::endl;
        std::cout << mousey << std::endl;
        location1 = Vector2(mousex, mousey);
        selectionStarted = true;
        std::cout<< location1 << std::endl;
        std::cout<< selectionStarted << std::endl;
        if (selectionStarted == true ){
            unit->IsUnSelected();
        }
    } else if(input()->getMouseUp( 0 ) && selectionStarted){
        mousex = input()->getMouseX() + camera()->position.x - SWIDTH/2;
        mousey = input()->getMouseY() + camera()->position.y - SHEIGHT/2;
        //mousex = input()->getMouseX();
        //mousey = input()->getMouseY();
        location2 = Vector2(mousex, mousey);
        selectionStarted = false;
        std::cout<< location2 << std::endl;
        std::cout<< selectionStarted << std::endl;
        compareXY(location1, location2, unit->position);
        measureSelection();
    }
    
    if(unit->selected == true){
        if (input()->getMouseDown(1)){
            destinationx = input()->getMouseX() + camera()->position.x - SWIDTH/2;
            destinationy = input()->getMouseY() + camera()->position.y - SHEIGHT/2;
            unit->destination = Vector2(destinationx, destinationy);
            std::cout<< destination << std::endl;
            unit->moving = true;
        }
    }
    
}

// Je checkt tussen twee muis posities
void GameScene::compareXY(Vector2 a, Vector2 b, Vector2 unitpos){
    if(a.x > b.x){
        //unitpos;
        biggestX = a.x;
        std::cout << a.x << std::endl;
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
    if(unit->position.x > smallestX && unit->position.x < biggestX &&
       unit->position.y > smallestX && unit->position.y < biggestY){
        unit->IsSelected();
        std::cout << unit->position << std::endl;
        std::cout << biggestX << "  " << biggestY << std::endl;
        std::cout << smallestX << "  "<<smallestY << std::endl;
        //std::cout << unit->IsSelected() << std::endl;
        
    }
}
