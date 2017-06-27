//
//  Part.cpp
//  Kaleido_2b
//
//  Created by Guido Corallo on 5/26/17.
//
//

#include <Part.h>

void Part::setup(){
    
    
}


void Part::update(){
    
    
    
    changeProb = .002;//.001;
    if(ofRandom(1)<changeProb){
        
        float d = 50;
        destPos = pos + ofVec3f(ofRandom(-d,d),ofRandom(-d,d),ofRandom(-d,d));
        change = true;
    }
    
    
    if(change){
        if(pos.distance(destPos)>1){
            
            pos += (destPos-pos)*.05;
            
        }else{
            
            pos.set(destPos);
            change = false;
            //cout<< "setting to change false"<<endl;
        }
        
    }
    
    if(ABS(s-destS)>1){
        s+=(destS-s)*.1;
    }
    
    if(skin == 1){
        if(ABS(angX-destAngX)>1){
            angX+=(destAngX-angX)*.05;
        }
    }
    
    
    if(skin==3){
        angX+=1*s/60.0;
    }
    
    if(ABS(yOff-destYoff)>1){
        yOff+=(destYoff-yOff)*.01;
    }
    
    life -=age;
    
}

void Part::draw(){
    if(skin==1){
        /*
         ofPushMatrix();
         ofTranslate(pos);
         ofSetColor(rc, gc, bc,200);
         ofPushMatrix();
         
         ofRotateY(angX);
         
         ofDrawRectangle(0,0,s, s*.25);
         ofSetColor(0);
         ofDrawRectangle(s*.75, 0.,s*.15, s*.15);
         ofPopMatrix();
         ofPopMatrix();
         */
        
        ofPushMatrix();
        ofTranslate(pos);
        ofSetColor(rc, gc, bc,160);
        ofPushMatrix();
        
        ofRotateY(angX);
        ofSetCircleResolution(3);
        ofDrawCircle(0, 0, s);
        
        ofSetColor(0);
        ofDrawCircle(0, 0, s*.75);
        
        ofSetColor(rc,gc, bc,220);
        ofDrawCircle(yOff,0, s*.25);
        ofSetColor(rc,gc, bc,255);
        
        ofDrawCircle(yOff*1.5,0, s*.15);
        
        ofPopMatrix();
        ofPopMatrix();
        
    }
    else if(skin==2){
        ofPushMatrix();
        ofTranslate(pos.x, pos.y, 0);
        
        ofSetColor(rc, gc, bc,200);
        ofSetCircleResolution(6);
        ofDrawEllipse(0,0, s,s);
        
        ofSetColor(0);
        ofDrawEllipse(0,0, s-s*.1,s-s*.1);
        
        ofSetColor(0,100);
        
        ofSetCircleResolution(3);
        
        ofDrawEllipse(0,-20, 20,20);
        ofDrawEllipse(0,-20, 20,20);
        
        ofSetColor(255,100);
        ofDrawEllipse(0,-40, 20,20);
        ofDrawEllipse(0,40, 20,20);
        ofPopMatrix();
    }
    else if(skin==3){
        /*
         //circulos simples
         ofPushMatrix();
         ofTranslate(pos.x, pos.y, 0);
         
         ofSetColor(rc, gc, bc,200);
         
         ofSetCircleResolution(30);
         
         ofSetColor(0);
         ofDrawCircle(0,0, s*1.2);
         
         ofSetColor(rc, gc, bc,200);
         ofDrawCircle(0,0, s);
         ofPopMatrix();
         */
        
        ofPushMatrix();
        ofTranslate(pos.x, pos.y, 0);
        
        
        ofSetColor(rc, gc, bc,200);
        ofSetCircleResolution(25);
        ofSetColor(0,220);
        ofDrawCircle(0,0, s*1.2);
        
        ofPushMatrix();
        ofRotateZ(angX);
        ofDrawCircle(2*s,0, s*1.2);
        ofPopMatrix();
        
        ofSetColor(rc, gc, bc,200);
        ofDrawCircle(0,0, s);
        
        ofSetColor(rc, gc, bc,220);
        ofDrawCircle(0,0, s*.75);
        
        ofPushMatrix();
        ofRotateZ(angX);
        ofDrawCircle(2*s,0, s);
        ofDrawCircle(2*s,0, s*.75);

        
        
        ofSetColor(rc,gc,bc,200);
        ofDrawCircle(2.5*s+yOff,0, s*.25);
        ofDrawCircle(3.5*s+yOff,0, s*.15);
        
        /*
        ofSetColor(255);
        ofDrawCircle(2.5*s+yOff,0, s*.3);
        ofDrawCircle(3.5*syOff,0, s*.2);
        */
        
        
        ofPopMatrix();
        
        
        ofPopMatrix();
        
        
    }
    
}


