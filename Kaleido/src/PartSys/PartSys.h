//
//  PartSys.h
//  Kaleido_2b
//
//  Created by Guido Corallo on 5/26/17.
//
//

#ifndef PartSys_h
#define PartSys_h

#include "Part.h"

class PartSys{

public:
    
    PartSys(){
    
    }
    
    vector <Part> parts;
    
    void setup();
    void update();
    void draw();
    void addPart(ofVec3f pos);

    float ang;
    
    int skin;
    
    float baseR, baseG, baseB;
    

};


#endif /* PartSys_h */
