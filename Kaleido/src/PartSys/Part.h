//
//  Part.h
//  Kaleido_2b
//
//  Created by Guido Corallo on 5/26/17.
//
//

#ifndef Part_h
#define Part_h

#include "ofMain.h"

class Part{


public:
    
    Part(){
    }
    
    ofVec3f pos;
    ofVec3f destPos;
    
    float changeProb;
    bool change;
    
    void setup();
    void update();
    void draw();


    float rc;
    float gc;
    float bc;
    
    float life;
    float age;
    
    int skin;

    float s;
    float destS;
    
    float angX;
    float destAngX;
    
    float yOff;
    float destYoff;
    
};

class VertexPoint{

public:
    
    VertexPoint(){
    
    }
    
    ofVec3f pos;
    float d;
    float rc;
    float gc;
    float bc;
    
    
    
    
    
    
};


#endif /* Part_h */
