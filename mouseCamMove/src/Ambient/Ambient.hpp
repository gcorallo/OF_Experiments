//
//  AmbientSys.hpp
//  NewTrails_1
//
//  Created by Guido Corallo on 5/30/17.
//
//

#ifndef Ambient_hpp
#define Ambient_hpp

#include <ofMain.h>

class Ambient{
    
    
public:
    
    Ambient(){
    }
    ~Ambient(){
    
    }
    
    void setup();
    void update(ofVec3f linearPos);
    void draw();
    
    
    vector <ofVec3f> parts;
    
    float limit;
    
    ofMesh mesh;
    
};




#endif /* AmbientSys_hpp */
