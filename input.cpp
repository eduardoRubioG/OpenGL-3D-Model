//
//  input.cpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/22/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//

#ifndef INPUT
#define INPUT

#include <stdio.h>
#include "include.h"
#include "prototypes.h"

extern float X_DELTA_SPIN;
extern float Y_DELTA_SPIN;
extern float Z_DELTA_SPIN;
extern float CAMERA_MOD;
/** 
 *  Defines mouse interaction 
 **/
void mouse( int button, int state, int x, int y ){
    if( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ) mouseAnimate(x, y, 0.5);
    if( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN ) mouseAnimate(x, y, -0.5);
}

/**
 * Defines keyboard interaction for non-ASCII keys
 */
void specialKeyboard( int key, int x, int y ){
    if( key == GLUT_KEY_UP   || key == GLUT_KEY_PAGE_UP ) CAMERA_MOD++;
    if( key == GLUT_KEY_DOWN || key == GLUT_KEY_PAGE_DOWN) CAMERA_MOD--;
    glutPostRedisplay();
}

/**
 * Defines keyboard interaction for ASCII keys
 */
void keyboard( unsigned char key, int x, int y ){

    if( key == 'q' || key == 'Q' ) exit(0);
    if( key == 'x' || key == 'X' ) {X_DELTA_SPIN += 0.5; animate;}
    if( key == 'y' || key == 'Y' ) {Y_DELTA_SPIN += 0.5; animate;}
    if( key == 'z' || key == 'Z' ) {Z_DELTA_SPIN += 0.5; animate;}
    if( key == 's' || key == 'S' ) {glutIdleFunc(NULL); stopAnimation();}
    if( key == 'r' )  lightReset();   //original position and house size
    if( key == 'R' )  hardReset();    //Original position, house size, camera pos, and view mode
    glutPostRedisplay(); 
}

#endif
