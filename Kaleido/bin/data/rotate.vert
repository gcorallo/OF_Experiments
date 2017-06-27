#version 150


// these are for the programmable pipeline system
uniform mat4 modelViewProjectionMatrix;
//uniform mat4 textureMatrix;

in vec4 position;
in vec2 texcoord;
//in vec4 normal;
//in vec4 Color;
//in float depth;

//out float value;
out vec2 texCoordVarying;
//out vec4 normalSend;
//out vec4 depthSend;
//out vec4 colorSend;


void main()
{
    
    
    //normalSend = vec4(vec3(normal.rgb*0.5+0.5),1.0);
    
    //depthSend = vec4(vec3((modelViewProjectionMatrix * position).z/400.0), 1.0);
    
    /*
     if(color.r ==1.0){
     value =1.0;
     }
     else{
     value = 0.25;
     }
     */
    
    //value = position.z;
    texCoordVarying = texcoord;
    gl_Position = modelViewProjectionMatrix * position;
    
}
