#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ww = ofGetWindowWidth();
    hh = ofGetWindowHeight();
    
    
    
    fbo.allocate(ww, hh, GL_RGB);
    fbo2.allocate(ww, hh, GL_RGB);
    
    bkg.load("img3.jpeg");
    
    fbo.begin();
    
    
    ofClear(0);
    fbo.end();
    
    fbo2.begin();
    ofClear(0);
    fbo2.end();
    
    rotateSh.load("rotate.vert", "rotate.frag");
    
    gui.setup();
    gui.add(nPasses.setup("nPasses", 3.0, 0.0, 20.0));
    
    doDraw = false;
    doShader = true;
    
       
    delay = 1000;
    deltaT = ofGetElapsedTimeMillis();
    
    
    bc=ofRandom(100,200);
    gc=ofRandom(100,200);
    bc=ofRandom(100,200);
    rVel = 1.;
    gVel = 1.;
    bVel = 1.;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    if(ofGetElapsedTimeMillis()- deltaT>delay){
        if(nPasses<20){
            nPasses= nPasses+1;
            
        }
        else{
            nPasses=2;
        }
        deltaT = ofGetElapsedTimeMillis();
    
    }
    rc+=rVel;
    gc+=gVel;
    bc+=bVel;
    if(rc<0 || rc>255){
        rVel *=-1;
    }
    if(gc<0 || gc>255){
        gVel *=-1;
    }
    if(bc<0 || bc>255){
        bVel *=-1;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    float angRot;
    
    ofBackground(0);
    
    //int nTimes = 2;
    ofPushStyle();
    fbo.begin();
    
    if(clearFbo){
        ofSetColor(255);
        ofClear(0);
        //bkg.draw(0,0);
        clearFbo = false;
    }
    //ofClear(0);
    ofVec2f mpos = ofVec2f(mouseX, mouseY);
    
    ofVec2f res = ofVec2f(ww,hh);
    ofVec2f uv = ofVec2f( mpos * 2.0 - res) /MAX( res.x, res.y );
    
    dx = uv.x;
    dy = uv.y;
    
    
    
    
    if(doDraw){
        
        float angle = PI / nPasses;
        
        float r = uv.length();
        float a = atan2( uv.y, uv.x ) / angle;
        
        dAngle = a* 180/PI;
        
        if(int(a) % 2==0){
            if(mpos.y>hh/2){
                
                
                a = a-(long)a;
                
                
            }
            
            else {
                
                a =  (-a-long(-a));
                
                
                
            }
            
        }
        else{
            if(mpos.y>hh/2){
                
                a = 1-(a-long(a));
                
            }
            
            else{
                
                
                a = 1-  (-a-long(-a));
                
            }
            
        }
        
        a*= angle;
        
        
        ofVec2f nuevapos = ofVec2f(cos(a),sin(a))*r;
        
        
        
      
        doDraw = false;
        
        nuevapos *= res.x;
        
        ofSetColor(rc,gc,bc);
        ofDrawEllipse( nuevapos, 20, 20);
    
        
    }
    
    
    fbo.end();
    
    
    fbo2.begin();
    
    
    rotateSh.begin();
    rotateSh.setUniform1f("time", ofGetElapsedTimeMillis()*.0001);
    float v= ofMap(ofGetMouseX(), 0, ofGetWindowWidth(), 1.0, 20.0);
    v = 1;
    rotateSh.setUniform1f("scale", v);
    rotateSh.setUniform1f("nTimes", (float)nPasses);
    rotateSh.setUniform2f("resolution", (float)ww, (float)hh);
    
    
    ofSetColor(255);
    
    fbo.draw(0,0);
    if(doShader){
        rotateSh.end();
    }
    fbo2.end();
    
    
    
    ofSetColor(255);
    fbo2.draw(0,0);
    
    ofPopStyle();
    
    ofSetColor(255);
    
    
    gui.draw();
    
    
  
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        doShader = !doShader;
    }
    else if(key == 'c'){
        clearFbo = true;
        nPasses = 2;
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
