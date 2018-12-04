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

