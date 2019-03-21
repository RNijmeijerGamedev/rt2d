/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include <input.h>
#include "myentity.h"
#include "grid.h"
#include "scenemanager.h"
#include "selection.h"
#include "vectorx.h"
#include "collision.h"

/// @brief The MyScene class is the Scene implementation.
class GameScene : public SceneManager
{
public:
	/// @brief Constructor
	GameScene();
	/// @brief Destructor
	virtual ~GameScene();
    
    
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
    void compareXY(Vector2 a, Vector2 b);
    void measureSelection();
    
private:
    Grid* grid = nullptr;
    Unit* unit = nullptr;
    Selection* selection = nullptr;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
    int mouseX;
    int mouseY;
    Vector2 location1;
    Vector2 location2;
    bool selectionStarted;
    int biggestX;
    int biggestY;
    int smallestX;
    int smallestY;
    
    
};

#endif /* SCENE00_H */
