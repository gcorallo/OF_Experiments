//
//  AmbientSys.cpp
//  NewTrails_1
//
//  Created by Guido Corallo on 5/30/17.
//
//

#include "Ambient.hpp"

void Ambient::setup(){
    
    int initParts = 2000;
    for(int i=0; i<initParts; i++){
        
        
        
        ofVec3f temp;
        temp = ofVec3f(ofRandom(-800,800),ofRandom(-800,800),ofRandom(-800,800));
        parts.push_back(temp);
        mesh.addVertex(temp);
        
    }
    
    
    
    
}


void Ambient::update(ofVec3f linearPos){
    mesh.clear();
    
    for(int i=0; i<parts.size(); i++){
        if(parts[i].x < linearPos.x-800){
            parts[i].x =linearPos.x+800;
        }
        if(parts[i].x > linearPos.x+800){
            parts[i].x =linearPos.x-800;
        }
        
        if(parts[i].y < linearPos.y-800){
            parts[i].y =linearPos.y+800;
        }
        if(parts[i].y < linearPos.y-800){
            parts[i].y =linearPos.y+800;
        }
        if(parts[i].y > linearPos.y+800){
            parts[i].y =linearPos.y-800;
        }
        
        if(parts[i].z < linearPos.z-800){
            parts[i].z =linearPos.z+800;
        }
        if(parts[i].z > linearPos.z+800){
            parts[i].z =linearPos.z-800;
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
