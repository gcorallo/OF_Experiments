#pragma once

#include "ofMain.h"
#include "Ambient.hpp"

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
		
    
    ofVec3f camOffset;
    
    ofEasyCam cam;
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f mousePos;
    ofVec2f lastMousePos;
    
    Ambient ambient;
    
    struct Point{
        ofVec3f pos;
        float life;
        float age;
    };
    
    vector <Point> points;
    
    bool doDraw;
    
    int ww;
    int hh;
    
};
