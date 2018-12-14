//
//  scenemanager.cpp
//  basic3D
//
//  Created by Ruben Nijmeijer on 13/12/2018.
//

#include "scenemanager.h"

int SceneManager::activescene = 0;

SceneManager::SceneManager() : Scene()
{
    fpstimer.start();
    
    player = nullptr;
    top_layer = 7; // 8 layers (0-7)
    
    for (unsigned int i = 0; i <= top_layer; i++) {
        MyEntity* layer = new MyEntity();
        layers.push_back(layer);
        this->addChild(layer);
    }
    
    for (unsigned int i = 0; i < 16; i++) {
        Text* line = new Text();
        line->scale = Point2(0.5f, 0.5f);
        
        text.push_back(line);
        layers[top_layer]->addChild(line);
    }
    
    // Create a logo entity on the top layer
    logo = new MyEntity();
    logo->position = Point2(SWIDTH/2, SHEIGHT - 50);
    logo->addLine("assets/rt2d.line");
    layers[top_layer]->addChild(logo);
    
    text[1]->message("");
    text[2]->message("<[/]> previous/next scene");
    text[3]->message("<ESC> quit demo");
}


SceneManager::~SceneManager()
{
    layers[top_layer]->removeChild(logo);
    
    int ls = layers.size();
    for (int i=0; i<ls; i++) {
        this->removeChild(layers[i]);
        delete layers[i];
        layers[i] = nullptr;
    }
    layers.clear();
    
    int ts = text.size();
    for (int i=0; i<ts; i++) {
        this->removeChild(text[i]);
        delete text[i];
        text[i] = nullptr;
    }
    text.clear();
    
    delete logo;
}

// must be explicitly called from subclass
void SceneManager::update(float deltaTime)
{
    // ###############################################################
    // Escape key stops the Scene
    // ###############################################################
    if (input()->getKeyUp(KeyCode::Escape)) {
        this->stop();
    }
}

void SceneManager::moveCamera(float deltaTime)
{
    // ###############################################################
    // Move Camera (Arrow up, down, left, right)
    // ###############################################################
    float speed = 600.0f; // 600 units / second
    
    // Right and Down vector
    Point2 right = Point2(1, 0);
    Point2 up = Point2(0, 1);
    // Direction
    Vector2 direction = Vector2(0,0);
    
    if (input()->getKey(KeyCode::Up)) {
        direction -= up;
    }
    if (input()->getKey(KeyCode::Down)) {
        direction += up;
    }
    if (input()->getKey(KeyCode::Right)) {
        direction += right;
    }
    if (input()->getKey(KeyCode::Left)) {
        direction -= right;
    }
    direction.normalize();
    direction *= deltaTime * speed;
    camera()->position += direction;
}
