#version 150

const float PI = 3.14159265359;
const float DEG_TO_RAD = PI / 180.0;
const float USE_KALEIDOSCOPE = 1.0;
const float NUM_SIDES = 6.0;

in vec2 texCoordVarying;
uniform sampler2DRect tex0;
//uniform sampler2DRect tex1;


uniform vec4 globalColor;
uniform float time;
uniform float scale;
uniform float nTimes;
uniform vec2 resolution;


out vec4 fragColor;
//in vec4 colorSend;
vec2 Kaleidoscope( vec2 uv, float n, float bias ) {
    float angle = PI / n;
    
    float r = length( uv );
    float a = atan( uv.y, uv.x ) / angle;
    
    a = mix( fract( a ), 1.0 - fract( a ), mod( floor( a ), 2.0 ) ) * angle;
    
    return vec2( cos( a ), sin( a ) ) * r;
}


void main(){
    
    
    vec2 st = texCoordVarying.st/vec2(600.0);
    
    vec4 c0;
    float ang = time;
    
    
    ang = 3.1416/nTimes ;//+ time*0.01;
    ang = time;
    
    vec2 coord = texCoordVarying;
    
    vec2 uv = ( gl_FragCoord.xy * 2.0 - resolution.xy ) /max( resolution.x, resolution.y );
    
    
    
    
    // --- Kaleidoscope ---
    uv = mix( uv, Kaleidoscope( uv, nTimes, time), 1.0 );
    
    /*
    float sin_factor = sin(ang);
    float cos_factor = cos(ang);
    
    
    
    coord = vec2( texCoordVarying.s - resolution.x/2.0, texCoordVarying.t - resolution.y/2.0) * mat2(cos_factor, sin_factor, -sin_factor, cos_factor);
    
    coord += resolution/2.0;
    */
    
    coord = uv*resolution.x;
    
    
    
    
    
    c0 = texture(tex0, coord);
    
    float compAng = 3.1416/6.0;
    
   
    
    
    
    
    fragColor = c0;
    
}
