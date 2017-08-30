//
//  TapTempo.h
//  TapTempo
//
//  Created by Guido Corallo on 8/29/17.
//
//

#pragma once
#include "ofMain.h"

class TapTempo{

public:
	
	TapTempo();
    
    void setup();
    void update();
    void draw();
    
    vector <float> taps;
    
    void addTap();
    
    bool isRecording;
    bool newTap;
    bool tempoOk;
    
    int maxTaps;
    float alpha;
    float alphaOk;
    
    float lastTap;
    
    float tempoTime;
    
    float x;
    int bpm;
    
protected:

};

