#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    ambient.setup();
    
    camOffset = ofVec3f(0,0,0);
    cam.disableMouseInput();

    doDraw=false;
   
    cam.setDistance(651);
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
        camOffset+=(points[points.size()-1].pos-camOffset)*1.0;
        ambient.update(camOffset);
    }
    
    
    //if(doDraw){
        
        pos += mousePos;
        
        Point temp;
        //temp.pos = ofVec2f(ofGetMouseX(), -ofGetMouseY());
        temp.pos.set(pos);
        temp.life = 10.f;
        temp.age = .1f;
        points.push_back(temp);
        
        doDraw= false;
        lastMousePos.set(mousePos);
    //}
    
    
    //cout<< cam.getDistance()<<endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    
    ofBackground(0);
    
    
    cam.begin();
    
    
    
    ofTranslate(-camOffset.x, -camOffset.y,0);
    ambient.draw();
    
    ofSetColor(255);
    for(int i = 0; i<points.size();i++){
        if(i>0){
            ofDrawLine(points[i].pos, points[i-1].pos);
            
        }
        
        
    }
    
    
    cam.end();

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
    mousePos = ofVec2f(x-ofGetWindowWidth()/2,-(y-ofGetWindowHeight()/2))*.1;

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    doDraw= true;
    mousePos = ofVec2f(x-ofGetWindowWidth()/2,-(y-ofGetWindowHeight()/2))*.1;
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
