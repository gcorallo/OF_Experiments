//
//  TapTempo.cpp
//  TapTempo
//
//  Created by Guido Corallo on 8/29/17.
//
//

#include "TapTempo.h"

TapTempo::TapTempo(){
    
    
}

void TapTempo::setup(){
    
    alpha = 0;
    alphaOk = 0;
    tempoOk = false;
    x = 0.0;
    bpm = 0;
    
}


void TapTempo::update(){
    
    
    if(isRecording && (ofGetElapsedTimeMillis()-lastTap) > 2000){
        //float diff =ofGetElapsedTimeMillis()-lastTap;
        //cout<<ofGetElapsedTimeMillis()<< "::"<<lastTap<<endl;
        isRecording=false;
        taps.clear();
        //cout<<"clear taps"<<endl;
        
    }
    
    
    if(taps.size()>3 && isRecording){ //arbitrary...
        float sum = 0.0;
        float offset = taps[0];
        for(int i=0; i<taps.size(); i++){
            if(i>0){
                sum+= taps[i]-taps[i-1];
            }
            
        }
        float avrg = sum/(taps.size()-1);
        
        x =  avrg;
        tempoOk = true;
        tempoTime = ofGetElapsedTimeMillis();
        alphaOk= 255;
      
        bpm = int(60000/avrg);
        
        cout<<"bpm"<<bpm;
        
        isRecording = false;
        taps.clear();
    }
    if(tempoOk){
        //cout<<"x:  "<<x<< "tempoTime"<<endl;
        
        if(ofGetElapsedTimeMillis()-tempoTime>x){
            
            //cout<<"bang at "<< ofGetFrameNum()<<endl;
            alphaOk = 255;
            
            tempoTime = ofGetElapsedTimeMillis();
        }
        
    }
    
    
    
    
    if(alpha>0){
        alpha +=(0-alpha)*.1;
    }
    if(alphaOk>0){
        alphaOk +=(0-alphaOk)*.1;
    }
    if(newTap){
        
        alpha = 255;
        newTap = false;
        
    }
    
    
    
}


void TapTempo::draw(){
    
    
    ofSetColor(255,0,0, alpha);
    ofDrawRectangle(50,50,50,50);
    
    
    
    ofSetColor(0,255,0, alphaOk);
    ofDrawRectangle(50,150,50,50);
    
    
    ofSetColor(255);
    ofDrawBitmapString("avrg delta: " +ofToString(x)+ " ms",200,50);
    
    ofDrawBitmapString("bpm: " +ofToString(bpm),200,100);
    
}


void TapTempo::addTap(){
    
    
    newTap = true;
    
    if(taps.size()>5){
        taps.erase(taps.begin());
    }
    taps.push_back(ofGetElapsedTimeMillis());
    lastTap = ofGetElapsedTimeMillis();
    isRecording = true;
    
}
