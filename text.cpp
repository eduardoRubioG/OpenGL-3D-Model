//
//  text.cpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/26/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "include.h"

extern const int WINDOW_MAX_X, WINDOW_MAX_Y;
extern const int WINDOW_POSITION_X, WINDOW_POSITION_Y;
extern float WORLD_COORDINATES_MIN_X, WORLD_COORDINATES_MAX_X;
extern float WORLD_COORDINATES_MIN_Y, WORLD_COORDINATES_MAX_Y;
extern bool IS_WIREFRAME, AXES_DRAWN, HOUSE_SIGN;
extern int VIEW_MODE;


/**
 *  Produce 2D text
 */
void drawString(float x, float y, void *font, const char* string ){
    glColor3f(1.0, 1.0, 1.0);
    const char* c;
    glRasterPos2i( x, y );
    for(c=(char*)string; *c!='\0'; c++)
        glutBitmapCharacter(font, *c);
}

/**
 * Produce 3D text
 */
void drawString(float x, float y, float z, void *font,  char* string)
{
    char *p;
    
    glLineWidth(2.0);
    
    /* Position the 3D text */
    glPushMatrix();
    glTranslatef(2.53, -3.5, 12.5);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(45.0, 1.0, 0.0, 0.0);
    glScalef(.01, .01, .01);

    /* End positioning */
    for (p = (char*)string; *p!='\0'; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
        
    glPopMatrix();
}

/**
 * Draws the Hello World sign on the roof of the house
 */
void houseSign( ){
    if( !IS_WIREFRAME )
        glColor3f(0.0,0.0,0.0);
    else
        glColor3f(1.0, 1.0, 1.0);
    
    drawString(1, 1, 1, GLUT_BITMAP_HELVETICA_18, "Hello World!");
}

/**
 * Text display view mode on screen
 */
void viewModeText( ) {
    
    /* Define char array as the view */
    std::string view;
    if( VIEW_MODE == 1) view = "Orthographic View";
    if( VIEW_MODE == 2) view = "Projection View";
    if( VIEW_MODE == 3) view = "Custom View";
    int stringLength = view.length();
    char charString[ stringLength + 1 ];
    strcpy(charString, view.c_str());
    
    /* Set up OpenGL for 2d text in a 3d space */
    glDisable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, WINDOW_MAX_X, 0.0, WINDOW_MAX_Y);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    /* Call to draw text */
    drawString(WINDOW_MAX_X*.77, WINDOW_MAX_Y*.95,
               GLUT_BITMAP_HELVETICA_18, charString);
    
    /* Revert changes made */
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);
}

/**
 * Label the axes
 */
void axesLabels( ){
    
    /* Define char arrays as the axes labels */
    std::string label_string;
    char label[ 7 ];
    
    /* Set up OpenGL for 2d text in a 3d space */
    glDisable(GL_TEXTURE_2D); //added this
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, WINDOW_MAX_X, 0.0, WINDOW_MAX_Y);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    /* Label x-axis */
    label_string = "X-Axis";
    strcpy(label, label_string.c_str());
    drawString(WINDOW_MAX_X*.1, 275, GLUT_BITMAP_HELVETICA_18, label);
    
    /* Label y-axis */
    label_string = "Y-Axis";
    strcpy(label, label_string.c_str());
    drawString(WINDOW_MAX_X*.9, 260,
               GLUT_BITMAP_HELVETICA_18, label);
    
    /* Label z-axis */
    label_string = "Z-Axis";
    strcpy(label, label_string.c_str());
    drawString(WINDOW_MAX_X *.41, WINDOW_MAX_Y*.9,
               GLUT_BITMAP_HELVETICA_18, label);
    
    /* Revert changes made */
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);
    
}
