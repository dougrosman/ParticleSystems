#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    
    size = 20;
    for(int i = 0; i < size; i++)
    {
        Particle p;
        
        p.position = {ofGetWidth()/2, ofGetHeight()/2, 0};
        p.velocity = {ofRandom(-10, 10), ofRandom(-10, -6), 0};
        p.acceleration.y = 0.1;
        p.acceleration.x = ofRandom(-.1, .1);
        
        p.radius = ofRandom(2, 5);
        p.color = ofColor(255, ofRandom(50, 220));
        particles.push_back(p);
    }
}

void ofApp::update()
{
    float t = ofGetElapsedTimef();
    for(auto& p : particles)
    {
        float r = ofRandom(0.1, 1);
        p.update();
        p.acceleration.x = ofMap(sin(r*t), -1, 1, -.06, .06);
        p.acceleration.y = ofMap(cos(r*t), -1, 1, .01, .04);
        
        
        
        if(p.position.y + p.radius > ofGetHeight())
        {
            p.position = {ofRandom(ofGetWidth()/4, 3*ofGetWidth()/4), -p.radius, 0};
            p.velocity = {ofRandom(-16, 16), ofRandom(-20, -2), 0};
            p.acceleration.x = ofRandom(-.1, .1);
            p.age = 0;
        }
        
    }
    
    
    
}

void ofApp::draw()
{
    for(int i = 0; i < particles.size(); i++)
    {
        ofSetColor(particles[i].color);
        
        ofPushMatrix();
        //ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofDrawCircle(particles[i].position.x, particles[i].position.y, particles[i].radius);
        
        float t = ofGetElapsedTimef();
        //ofSetColor(255, ofMap(sin(t), -1, 1, 10, 60));
        ofSetLineWidth(2);
        if(i+1 >= particles.size())
        {
            ofDrawLine(particles[i].position, particles[0].position);
        }
        else{
            ofDrawLine(particles[i].position, particles[i+1].position);
        }
        ofPopMatrix();
        
        //ofDrawBitmapString(ofToString(ofGetFrameRate()), 5, 10);
    }
}

void ofApp::keyPressed(int key)
{
    
}
