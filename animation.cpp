//
//  animation.cpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/22/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//

#include <stdio.h>

/**
 * Continuously runs until the animation is called to stop
 */
void timer( int ){
    
    if( !IS_ROTATING ){
        return;
    } else {
        //rotate functions are called here
        glutPostRedisplay();
        glutTimerFunc(1000/60, timer, 0);
    }
}

/**
 * Stops the animation timeline for the object
 */
void stopAnimation( ) {
    IS_ROTATING = false;
    X_SPIN = 0;
    Y_SPIN = 0;
    Z_SPIN = 0;
}

/**
*  Initiate the call to the time iterated function
*/
void rotationSpin( ){
    IS_ROTATING = true;
    glutTimerFunc(0, timer, 0);
}
