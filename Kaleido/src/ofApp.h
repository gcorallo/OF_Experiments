#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofShader rotateSh;
    
    ofFbo fbo;
    ofFbo fbo2;
    
    int ww, hh;
    
    float dx, dy;
    float dAngle;
    
    bool doDraw;
    bool doShader;
    
    
    
    ofxPanel gui;
    
    ofxIntSlider nPasses;
    
    bool clearFbo;
    
    
    bool demoMode;
    
    float deltaT;
    float delay;
    
    
    float rc;
    float gc;
    float bc;
    float rVel;
    float gVel;
    float bVel;
    
    
};

