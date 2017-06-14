//
//  AmbientSys.cpp
//  NewTrails_1
//
//  Created by Guido Corallo on 5/30/17.
//
//

#include "Ambient.hpp"

void Ambient::setup(){
    
    int initParts = 4000;
    limit = 2000;

    for(int i=0; i<initParts; i++){
        
        
        
        ofVec3f temp;
        temp = ofVec3f(ofRandom(-limit,limit),ofRandom(-limit,limit),ofRandom(-limit,limit));
        parts.push_back(temp);
        mesh.addVertex(temp);
        
    }
    
    
    
    
}


void Ambient::update(ofVec3f linearPos){
    mesh.clear();
    
    for(int i=0; i<parts.size(); i++){
        if(parts[i].x < linearPos.x-limit){
            parts[i].x =linearPos.x+limit;
        }
        if(parts[i].x > linearPos.x+limit){
            parts[i].x =linearPos.x-limit;
        }
        
        if(parts[i].y < linearPos.y-limit){
            parts[i].y =linearPos.y+limit;
        }
        if(parts[i].y < linearPos.y-limit){
            parts[i].y =linearPos.y+limit;
        }
        if(parts[i].y > linearPos.y+limit){
            parts[i].y =linearPos.y-limit;
        }
        
        if(parts[i].z < linearPos.z-limit){
            parts[i].z =linearPos.z+limit;
        }
        if(parts[i].z > linearPos.z+limit){
            parts[i].z =linearPos.z-limit;
        }
        
    }
    
    for(int i=0; i<parts.size(); i++){
        
        mesh.addVertex(parts[i]);
        
    }
    
    
    
    
}



void Ambient::draw(){
    
    /*
     for(int i=0; i<parts.size(); i++){
     
     parts[i].display();
     }
     */
    
    ofSetColor(255,200);
    glPointSize(2);
    mesh.drawVertices();
    
    
    
    
}
