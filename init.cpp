//
//  init.cpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/22/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//
#ifndef INIT
#define INIT

#include <stdio.h>
#include "include.h"
#include "prototypes.h"


void initGlobals(){

/* Window specfications */
const int WINDOW_POSITION_X = 100;
const int WINDOW_POSITION_Y = 100;
const int WINDOW_MAX_X = 800;
const int WINDOW_MAX_Y = 800;

const float WORLD_COORDINATES_MIN_X = 0.0;
const float WORLD_COORDINATES_MAX_X = 800.0;
const float WORLD_COORDINATES_MIN_Y = 0.0;
const float WORLD_COORDINATES_MAX_Y = 800;

float X_DELTA_SPIN = 0;
float Y_DELTA_SPIN = 0;
float Z_DELTA_SPIN = 0;
float X_SPIN = 0;
float Y_SPIN = 0;
float Z_SPIN = 0;

int CAMERA_MOD = 0; //Will be used to zoom in and out of the scene 

/* For menu use */
bool IS_WIREFRAME = false;
bool AXES_DRAWN = true;
bool HOUSE_SIGN = false; 
int VIEW_MODE = 2; // 1 = ortho, 2 = projection, 3 = custom -- Projection by default 

}

#endif
void myglutInit( int argc, char** argv ){
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(WINDOW_MAX_X, WINDOW_MAX_Y);
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);
    glutCreateWindow("The Crazy House");
}

void myInit(void){
    glClearColor(0.1, 0.1, 0.1, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    initGlobals();
    
    glViewport(0, 0, WINDOW_MAX_X, WINDOW_MAX_Y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(WORLD_COORDINATES_MIN_X, WORLD_COORDINATES_MAX_X,
               WORLD_COORDINATES_MIN_Y, WORLD_COORDINATES_MAX_Y);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}

void display( ){
    
    /* Start the pipeline */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    
    /* Define the camera and view */
    viewHandler( VIEW_MODE ); 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /* Display View Mode Text */
    viewModeText();
    
    /* Draw the axes (includes labels) */
    if( AXES_DRAWN ) drawAxes(100);
    
    /* Draw the house */
    if( !IS_WIREFRAME)   drawHouse( );
    else                drawHouseLines();
    
    glutSwapBuffers();

}

#endif

