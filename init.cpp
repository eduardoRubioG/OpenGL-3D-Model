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

// Specify actual storage space for global variables here

/* Do constant definitions here.  Window specfications */
/* Window specfications */
int WINDOW_POSITION_X;
int WINDOW_POSITION_Y;
int WINDOW_MAX_X;
int WINDOW_MAX_Y;

float WORLD_COORDINATES_MIN_X;
float WORLD_COORDINATES_MAX_X;
float WORLD_COORDINATES_MIN_Y;
float WORLD_COORDINATES_MAX_Y;

/* Set these in an actual code element */
float X_DELTA_SPIN;
float Y_DELTA_SPIN;
float Z_DELTA_SPIN;
float X_SPIN;
float Y_SPIN;
float Z_SPIN;

int CAMERA_MOD = 0; //Will be used to zoom in and out of the scene 

/* For menu use */
bool IS_WIREFRAME;
bool AXES_DRAWN;
bool HOUSE_SIGN; 
int VIEW_MODE; // 1 = ortho, 2 = projection, 3 = custom -- Projection by default 


void initGlobals(){

    WINDOW_POSITION_X = 100;
    WINDOW_POSITION_Y = 100;
    WINDOW_MAX_X = 800;
    WINDOW_MAX_Y = 800;

    WORLD_COORDINATES_MIN_X = 0.0;
    WORLD_COORDINATES_MAX_X = 800.0;
    WORLD_COORDINATES_MIN_Y = 0.0;
    WORLD_COORDINATES_MAX_Y = 800;



    X_DELTA_SPIN = 0;
    Y_DELTA_SPIN = 0;
    Z_DELTA_SPIN = 0;
    X_SPIN = 0;
    Y_SPIN = 0;
    Z_SPIN = 0;

    CAMERA_MOD = 0; //Will be used to zoom in and out of the scene 

    /* For menu use */
    IS_WIREFRAME = false;
    AXES_DRAWN = true;
    HOUSE_SIGN = false; 
    VIEW_MODE = 2; // 1 = ortho, 2 = projection, 3 = custom -- Projection by default 

}

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

