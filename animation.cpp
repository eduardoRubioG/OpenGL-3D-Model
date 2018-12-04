//
//  animation.cpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/22/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//

#include <stdio.h>
#include "include.h"

extern float X_SPIN, X_DELTA_SPIN;
extern float Y_SPIN, Y_DELTA_SPIN;
extern float Z_SPIN, Z_DELTA_SPIN;
extern const int WINDOW_MAX_X;
extern const int WINDOW_MAX_Y;

/**
 * Continuously runs until the animation is called to stop
 */
void animate( ){
    
    /* Modify the x-spin */
    X_SPIN +=  X_DELTA_SPIN;
    if( X_SPIN > 360.0 ) X_SPIN -= 360.0;
    
    /* Modify the y-spin */
    Y_SPIN +=  Y_DELTA_SPIN;
    if( Y_SPIN > 360.0 ) Y_SPIN -= 360.0;
    
    /* Modify the z-spin */
    Z_SPIN +=  Z_DELTA_SPIN;
    if( Z_SPIN > 360.0 ) Z_SPIN -= 360.0;
    
    glutPostRedisplay(); 
}

/**
 * Stops the animation timeline for the object
 */
void stopAnimation( ) {
    X_DELTA_SPIN = 0;
    Y_DELTA_SPIN = 0;
    Z_DELTA_SPIN = 0;
}

/**
 * Registers where the user is clicking on the screen
 */
void mouseAnimate( int x, int y, const float mod ){
   
    /* Accomodate for y values being inverted due to OpenGL framework */
    y = WINDOW_MAX_Y - y;
    
    /* Z-Region 1*/
    if( x > y && y < WINDOW_MAX_Y * .5
       && x < WINDOW_MAX_X*.5 )
        Z_DELTA_SPIN += mod;
   
    /* Z-Region 2 */
    if( x*(-1)+WINDOW_MAX_X > y
       &&  y < WINDOW_MAX_Y * .5
       && x > WINDOW_MAX_X*.5 )
        Z_DELTA_SPIN += mod;
  
    /* Y-Region */
    if( x < y && y > WINDOW_MAX_Y *.5
       && x < WINDOW_MAX_X * .5)
        Y_DELTA_SPIN += mod;
  
    
    /* X-Region */
    if( x*(-1)+WINDOW_MAX_X < y
       && y > WINDOW_MAX_Y*.5
       && x > WINDOW_MAX_X*.5)
        X_DELTA_SPIN += mod;
    
    /* Finish function */
    animate();
    //glutIdleFunc(animate);
}



