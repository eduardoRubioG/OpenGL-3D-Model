//
//  axes.cpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/22/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//

#ifndef AXES
#define AXES

#include <stdio.h>
#include "include.h"
#include "prototypes.h"

void drawAxes(int length)
{
    
    /* This provides a coordinate axis about the origin. */
    
    /* Draw Y-Axis */
    glPointSize(1.0);
    glBegin(GL_LINES);
    glVertex3i(0,length,0);
    glVertex3i(0,-length,0);
    glEnd();
    
    /* Draw X-Axis */
    glBegin(GL_LINES);
    glVertex3i(length,0,0);
    glVertex3i(-length,0,0);
    glEnd();
    
    /* Draw Z-Axis */ 
    glBegin(GL_LINES);
    glVertex3i(0,0,length);
    glVertex3i(0,0,-length);
    glEnd();
    
    /* Label axes */
    axesLabels();
}

#endif
