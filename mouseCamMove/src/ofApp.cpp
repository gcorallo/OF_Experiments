#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    ambient.setup();
    
    camOffset = ofVec3f(0,0,0);
   cam.disableMouseInput();

    doDraw=false;
   

}

//--------------------------------------------------------------
void ofApp::update(){
    cout<<points.size()<<endl;
    for(int i = points.size()-1; i>=0; i--){
        
        if(i==1){
            cout<<"life: "<<points[i].life<< "  age: "<<points[i].age<<endl;
        }
        if(points[i].life<=0){
            points.erase(points.begin()+i);
        }
        else{
            points[i].life -= points[i].age;
        }
        
    }
    
    
    if(points.size()>0){
    camOffset.set(points[points.size()-1].pos);
        ambient.update(camOffset);
    }
    
    
    if(doDraw){
        Point temp;
        temp.pos = ofVec2f(ofGetMouseX(), -ofGetMouseY());
        temp.life = 10.f;
        temp.age = .1f;
        points.push_back(temp);
        
        doDraw= false;
    }
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    doDraw= true;
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
