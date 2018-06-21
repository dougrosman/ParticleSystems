#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    
    size = 1000;
    for(int i = 0; i < size; i++)
    {
        Particle p;
        
        p.position = {ofGetWidth()/2, ofGetHeight()/2, 0};
        p.velocity = {ofRandom(-10, 10), ofRandom(-10, -6), 0};
        p.acceleration.y = 0.1;
        p.acceleration.x = ofRandom(-.1, .1);
        
        p.radius = ofRandom(1, 4);
        p.color = ofColor(255, ofRandom(100, 255));
        particles.push_back(p);
    }
}

void ofApp::update()
{
    for(auto& p : particles)
    {
        p.update();
        
        if(p.position.y + p.radius > ofGetHeight())
        {
            p.position = {ofGetWidth()/2, ofGetHeight()/2, 0};
            p.velocity = {ofRandom(-10, 10), ofRandom(-30, -2), 0};
            p.acceleration.x = ofRandom(-.1, .1);
            p.age = 0;
        }
        
    }
    
    
    
}

void ofApp::draw()
{
    for(auto& p : particles)
    {
        ofSetColor(p.color, p.age/2);
        
        ofPushMatrix();
        //ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofDrawCircle(p.position.x, p.position.y, p.radius);
        ofPopMatrix();
        
        ofDrawBitmapString(ofToString(ofGetFrameRate()), 5, 10);
    }
}

void ofApp::keyPressed(int key)
{
    
}
