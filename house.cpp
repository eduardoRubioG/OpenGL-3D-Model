//
//  drawHouse.cpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/22/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//

#include <stdio.h>

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
    
    /* Hello world sign */ 
    if( HOUSE_SIGN) houseSign();
    
    glColor3f(1.0, 0.0, 1.0);
    /* Side A */
    glBegin( GL_LINE_STRIP );
    glVertex3f(-5,-5,0);
    glVertex3f(5,-5,0);
    glVertex3f(5,-5,10);
    glVertex3f(-5,-5,10);
    glEnd();
    
    /* Side B */
    glBegin(GL_LINE_STRIP);
    glVertex3f(5,-5,0);
    glVertex3f(5,5,0);
    glVertex3f(5,5,10);
    glVertex3f(5,-5,10);
    glEnd();
    
    /* Side C */
    glBegin(GL_LINE_STRIP);
    glVertex3f(5,5,0);
    glVertex3f(-5,5,0);
    glVertex3f(-5,5,10);
    glVertex3f(5,5,10);
    glEnd();
    
    /* Side D */
    glBegin(GL_LINE_STRIP);
    glVertex3f(-5,5,0);
    glVertex3f(-5,-5,0);
    glVertex3f(-5,-5,10);
    glVertex3f(-5,5,10);
    glEnd();
    
    /* House floor */
    glBegin(GL_LINE_STRIP);
    glVertex3f(0,0,0);
    glVertex3f(10,0,0);
    glVertex3f(10,10,0);
    glVertex3f(0,10,0);
    glEnd();
    
    /* Roof A */
    glBegin(GL_LINE_STRIP);
    glVertex3f(-5,5,10);
    glVertex3f(-5,-5,10);
    glVertex3f(0,-5,15);
    glVertex3f(0,5,15);
    glEnd();
    
    /* Roof B */
    glBegin(GL_LINE_STRIP);
    glVertex3f(5,-5,10);
    glVertex3f(5,5,10);
    glVertex3f(0,5,15);
    glVertex3f(0,-5,15);
    glEnd();
    
    /* Side triangle A */
    glBegin(GL_LINE_STRIP);
    glVertex3f(-5,-5,10);
    glVertex3f(5,-5,10);
    glVertex3f(0,-5,15);
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    /* Side triangle B */
    glBegin(GL_LINE_STRIP);
    glVertex3f(-5,5,10);
    glVertex3f(5,5,10);
    glVertex3f(0,5,15);
    glEnd();
    
}
