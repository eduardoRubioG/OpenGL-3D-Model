//
//  drawHouse.cpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/22/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//

#ifndef HOUSE
#define HOUSE

#include <stdio.h>
#include "include.h"
#include "prototypes.h"

extern float X_SPIN, X_DELTA_SPIN;
extern float Y_SPIN, Y_DELTA_SPIN;
extern float Z_SPIN, Z_DELTA_SPIN;
extern int VIEW_MODE;
extern int CAMERA_MOD;
extern bool HOUSE_SIGN;

/**
 * Returns the house to its original position and stops animation
 */
void lightReset( ){
    X_DELTA_SPIN = 0;  X_SPIN = 0;
    Y_DELTA_SPIN = 0;  Y_SPIN = 0;
    Z_DELTA_SPIN = 0;  Z_SPIN = 0;
}

/**
 * Returns house to original position, stops animation, returns to projection mode and original camera 
 */
void hardReset( ){
    VIEW_MODE = 2; //Return view to projection mode
    CAMERA_MOD = 0;//Return camera to original position 
    X_DELTA_SPIN = 0;  X_SPIN = 0;
    Y_DELTA_SPIN = 0;  Y_SPIN = 0;
    Z_DELTA_SPIN = 0;  Z_SPIN = 0;
}

/**
 * Render the house with smooth surfaces
 */
void drawHouse( ){

    /* Begin rotational parameters */ 
    glPushMatrix();
    glLoadIdentity();
    glRotatef(X_SPIN, 1.0, 0.0, 0.0);
    glRotatef(Y_SPIN, 0.0, 1.0, 0.0);
    glRotatef(Z_SPIN, 0.0, 0.0, 1.0);
    
    /* Hello World Sign */
    if( HOUSE_SIGN ) houseSign();
    
    /* House floor */
    glBegin( GL_QUADS );
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-5,-5,0);
    glVertex3f(5,-5,0);
    glVertex3f(5,5,0);
    glVertex3f(-5,5,0);
    
    /* Side A */
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-5,-5,0);
    glVertex3f(5,-5,0);
    glVertex3f(5,-5,10);
    glVertex3f(-5,-5,10);
    
    /* Side B */
    glColor3f(0.0,0.0,1.0);
    glVertex3f(5,-5,0);
    glVertex3f(5,5,0);
    glVertex3f(5,5,10);
    glVertex3f(5,-5,10);
    
    /* Side C */
    glColor3f(1.0,1.0,0.0);
    glVertex3f(5,5,0);
    glVertex3f(-5,5,0);
    glVertex3f(-5,5,10);
    glVertex3f(5,5,10);
    
    /* Side D */
    glColor3f(1.0,0.0,1.0);
    glVertex3f(-5,5,0);
    glVertex3f(-5,-5,0);
    glVertex3f(-5,-5,10);
    glVertex3f(-5,5,10);

     /* Roof A */
    glColor3f(0.0,0.0,1.0);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-5,5,10);
    glVertex3f(-5,-5,10);
    glVertex3f(0,-5,15);
    glVertex3f(0,5,15);
    
    /* Roof B */
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(5,-5,10);
    glVertex3f(5,5,10);
    glVertex3f(0,5,15);
    glVertex3f(0,-5,15);
    glEnd();
    
    glColor3f(0.0, 0.0, 1.0);
    /* Side triangle A */
    glBegin(GL_TRIANGLES);
    glVertex3f(-5,-5,10);
    glVertex3f(5,-5,10);
    glVertex3f(0,-5,15);
    glEnd();
    
    /* Side triangle B */
    glBegin(GL_TRIANGLES);
    glVertex3f(-5,5,10);
    glVertex3f(5,5,10);
    glVertex3f(0,5,15);
    glEnd();
    
    /* Pop matrix */
    glPopMatrix();
    
}

/**
* Render the house as a wireframe 
*/
void drawHouseLines( ){
    
    glPushMatrix();
    glLoadIdentity();
    glRotatef(X_SPIN, 1.0, 0.0, 0.0);
    glRotatef(Y_SPIN, 0.0, 1.0, 0.0);
    glRotatef(Z_SPIN, 0.0, 0.0, 1.0);
    
    /* Hello world sign */ 
    if( HOUSE_SIGN) houseSign();
    
    glColor3f(1.0, 0.0, 1.0);
    
    /* Align the wireframe to the origin */
    glPushMatrix();
    glTranslatef(0.0, 0.0, 5.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glutWireCube(10.0);
    glBegin(GL_LINES);
    glVertex3d(5,-5,5);
    glVertex3d(5,0,10);
    
    glVertex3d(5,0,10);
    glVertex3d(5,5,5);
    
    glVertex3d(5,0,10);
    glVertex3d(-5,0,10);
    
    glVertex3d(-5,-5,5);
    glVertex3d(-5,0,10);
    
    glVertex3d(-5,0,10);
    glVertex3d(-5,5,5);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    
}

#endif
