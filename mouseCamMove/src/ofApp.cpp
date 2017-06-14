#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ww = 1024;
    hh = 768;
    
    ambient.setup();
    
    camOffset = ofVec3f(0,0,0);
    
    doDraw=false;
    
    
   
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = points.size()-1; i>=0; i--){
        if(points[i].life<=0){
            points.erase(points.begin()+i);
        }
        else{
            points[i].life -= points[i].age;
        }
        
    }
    
    
    if(points.size()>0){
        camOffset+=(points[points.size()-1].pos-camOffset)*.01;
        ambient.update(camOffset);
    }
    
    
    
    if(doDraw){
        
        
        //spring with damp=.8, k=-0.05
        vel = .8*(vel-.05*(pos-mousePos));
        pos+=vel;
        
        doDraw= false;
    }
    
    else{
        
        
        pos += vel;
        vel*=.95;
    }
    Point temp;
    temp.pos.set(pos);
    temp.life = 10.f;
    temp.age = .1f;
    points.push_back(temp);

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    

    ofBackground(0);
    
    
    ofTranslate(ww/2, hh/2);
    ofPushMatrix();
    
    
    ofTranslate(-pos.x, -pos.y,0);
    ambient.draw();
    ofPopMatrix();
    
    
    ofSetColor(255);
    for(int i = 0; i<points.size();i++){
        if(i>0){
            ofDrawLine(points[i].pos, points[i-1].pos);
            
        }
        
        
        
    }
    ofSetColor(255,0,0);
    ofDrawCircle(pos, 10);
    

    //
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'a'){
        cam.enableMouseInput();
    }
    else if(key == 's'){
        cam.disableMouseInput();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    doDraw= true;
    mousePos = ofVec2f(x-ww/2,y-hh/2);
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
