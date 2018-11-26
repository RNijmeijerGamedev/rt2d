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
#include <rt2d/text.h>
#include "myentity.h"
#include <vector>
#include <rt2d/timer.h>

struct Cell {
    MyEntity* entity;
    Point_t<int> position;
};

struct Player
{
    int mouseclicks = 0;
};

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();

	virtual ~MyScene();

	virtual void update(float deltaTime);
    void addPlayer(Player* p) { player = p; };

protected:
    unsigned int top_layer;
    std::vector<MyEntity*> layers;
    std::vector<Text*> text;
    Player* player;
    void moveCamera(float deltaTime);

private:
    MyEntity* grid;
    std::vector<Cell*> cells;
    
    int gridwidth;
    int gridheight;
    int cellwidth;
    int cellheight;
    int border;
    Timer fpstimer;
};

#endif /* SCENE00_H */
