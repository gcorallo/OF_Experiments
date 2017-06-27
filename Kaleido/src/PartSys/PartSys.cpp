//
//  PartSys.cpp
//  Kaleido_2b
//
//  Created by Guido Corallo on 5/26/17.
//
//

#include <PartSys.h>

void PartSys::setup(){
    
    
    skin = 2; //lines;
    baseR = 200;
    baseG = 200;
    baseB = 200;
}


void PartSys::update(){
    int changeCount = 0;
    for(int i=0; i<parts.size(); i++){
        
        parts[i].update();
        /*
         if(parts[i].change){
         changeCount++;
         }
         */
        
    }
    //cout<<"ChangeCount:_ "<<changeCount<<endl;
    
    ang+=1;
    
    for(int i=parts.size()-2; i>0; i--){
        // cout<<i<<" life: "<<parts[i].life;
        if(parts[i].life<=0){
            parts.erase(parts.begin()+i);
        }
        
    }
    //cout<<"size"<<parts.size()<<endl;
    
}


void PartSys::draw(){
    
    
    
    if(skin==0){ //lines;
        
        float maxAlfa = 150;//100;
        for(int i=0; i<parts.size(); i++){
            
            
            vector <VertexPoint> verts;
            float minDist =150;//100;
            
            for(int j=i; j<parts.size(); j++){
                
                float d = parts[i].pos.distance(parts[j].pos);
                
                if(d<minDist && ABS(i-j)<10){
                    
                    float alfa = ofMap (d, 0, minDist, maxAlfa, 0);
                    ofSetColor(parts[i].rc,parts[i].gc, parts[i].bc , alfa);
                    ofDrawLine(parts[i].pos, parts[j].pos);
                    
                    if(verts.size()<8){
                        VertexPoint temp;
                        temp.pos.set(parts[j].pos);
                        temp.d = d;
                        temp.rc = parts[j].rc;
                        temp.gc = parts[j].gc;
                        temp.bc = parts[j].bc;
                        verts.push_back(temp);
                    }
                    
                }
                
                
            }
            
            
            
            if(verts.size()>2 && verts.size()<9){
                float alphasum = 0.0;
                float rsum = 0;
                float gsum = 0;
                float bsum = 0;
                for(int k=0;k<verts.size(); k++){
                    
                    alphasum += verts[k].d;
                    rsum += verts[k].rc;
                    gsum += verts[k].gc;
                    bsum += verts[k].bc;
                    
                }
                alphasum /= verts.size();
                rsum /= verts.size();
                gsum /= verts.size();
                bsum /= verts.size();
                
                
                float alfa = ofMap (alphasum, 0, minDist, maxAlfa*.5, 0);
                
                
                ofSetColor(rsum, gsum, bsum,alfa);
                ofBeginShape();
                
                for(int k=0;k<verts.size(); k++){
                    
                    ofVertex(verts[k].pos);
                    
                }
                
                ofEndShape();
            }
            
            //parts[i].draw();
            
        }
    }
    
    else if(skin == 1 || skin == 2 || skin == 3){ // circles;
        
        
        for(int i=0; i<parts.size(); i++){
            
            
            parts[i].draw();
        }
        
        
        
        
    }
       
    
    //ofPopMatrix();
    
}

void PartSys::addPart(ofVec3f pos){
    
    Part temp;
    temp.pos = ofVec3f(pos.x, pos.y, 0.0);
    
    
    float dd = 50;
    if(skin==0){
        temp.destPos.set(pos);
        
        if(ofRandom(1)<.75){
            temp.rc = baseR + ofRandom(-dd,dd);
            temp.gc = baseG + ofRandom(-dd,dd);
            temp.bc = baseB + ofRandom(-dd,dd);
        }
        else{
            float base = 200;
            temp.rc = base + ofRandom(-dd,dd);
            temp.gc = base + ofRandom(-dd,dd);
            temp.bc = base + ofRandom(-dd,dd);
        }
    }
    else if(skin==1){
        ofVec3f newPos = ofVec3f(pos.x+ofRandom(10), pos.y, 0);
        temp.destPos.set(newPos);
        temp.angX = 360;
        temp.destAngX = 0;
        if(ofRandom(1)<.75){
            temp.rc = baseR + ofRandom(-dd,dd);
            temp.gc = baseG + ofRandom(-dd,dd);
            temp.bc = baseB + ofRandom(-dd,dd);
        }
        else{
            float base = 200;
            temp.rc = base + ofRandom(-dd,dd);
            temp.gc = base + ofRandom(-dd,dd);
            temp.bc = base + ofRandom(-dd,dd);
        }
        temp.s = 20;
        temp.destS = ofRandom(40,100);
        temp.yOff = 0;
        temp.destYoff = ofRandom(200, 300);
    
    }
    else if(skin == 2){
        ofVec3f newPos = ofVec3f(pos.x+ofRandom(30), pos.y+ofRandom(30), 0);
        temp.destPos.set(newPos);
        if(ofRandom(1)<.85){
            temp.rc = baseR + ofRandom(-dd,dd);
            temp.gc = baseG + ofRandom(-dd,dd);
            temp.bc = baseB + ofRandom(-dd,dd);
        }
        else{
            float base = 230;
            dd = 20;
            temp.rc = base + ofRandom(-dd,dd);
            temp.gc = base + ofRandom(-dd,dd);
            temp.bc = base + ofRandom(-dd,dd);
        }
        temp.s = 10;
        temp.destS = ofRandom(40,180);
        
    }
    else if(skin == 3){
        ofVec3f newPos = ofVec3f(pos.x+ofRandom(30), pos.y+ofRandom(30), 0);
        temp.destPos.set(newPos);
        if(ofRandom(1)<.85){
            temp.rc = baseR + ofRandom(-dd,dd);
            temp.gc = baseG + ofRandom(-dd,dd);
            temp.bc = baseB + ofRandom(-dd,dd);
        }
        else{
            float base = 230;
            dd = 20;
            temp.rc = base + ofRandom(-dd,dd);
            temp.gc = base + ofRandom(-dd,dd);
            temp.bc = base + ofRandom(-dd,dd);
        }
        temp.s = 0;
        temp.destS = ofRandom(10,100);
        temp.yOff = 0;
        temp.destYoff = ofRandom(200, 300);
        
    }

    
    temp.life = 10.0f;
    temp.age = .01f;
    temp.skin = skin;
    
    temp.change = true;
    parts.push_back(temp);
    
    
    //cout<<"skin in add part: "<<skin<<endl;
    
}

