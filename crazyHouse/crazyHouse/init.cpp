//
//  init.cpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/22/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//

#include <stdio.h>

void myglutInit( int argc, char** argv ){
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_MAX_X, WINDOW_MAX_Y);
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);
    glutCreateWindow("The Crazy House");
}

void myInit(void){
    glClearColor(0.1, 0.1, 0.1, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(WORLD_COORDINATES_MIN_X, WORLD_COORDINATES_MAX_X,
               WORLD_COORDINATES_MIN_Y, WORLD_COORDINATES_MAX_Y);
    glMatrixMode(GL_MODELVIEW);
}

void display( ){
    
    /* Start the pipeline */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    
    /* Define the camera */
    
    glMatrixMode(GL_MODELVIEW);
    gluPerspective( 100.0,        /* FOV */
                   1.0,         /* Aspect ratio */
                   0.1, 200.0); /* near, far */
    
    gluLookAt(100.0, 100.0, 30.0,  /* eye */
              0.0, 0.0, 0.0,      /* center */
              0.0, 0.0, 1.0);     /* up definition */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /* Draw the house + axis */

    drawAxes(100);
    glutSwapBuffers();

}
