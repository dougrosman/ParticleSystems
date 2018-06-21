#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Particle.h"

class ofApp : public ofBaseApp
{

public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    
    std::vector<Particle> particles;

    ofxPanel gui;
    
    std::size_t size;
};
