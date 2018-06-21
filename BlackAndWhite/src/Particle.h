#pragma once

#include "ofMain.h"
//#include "ofxGui.h"

class Particle
{

public:
   
    void update();
    
    // physics
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    
    // determines the rate of velocity degradation
    float drag = .99;
    
    
    float age;
    float maxAge;
    float radius = 1;
    
    ofColor color;
    
    
};
