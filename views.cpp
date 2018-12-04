//
//  views.cpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/26/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "include.h"


/**
 * Switch to projection mode
 */
void projectionView( ) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 45.0,        /* FOV */
                   1.0,         /* Aspect ratio */
                   1.0, 200.0); /* near, far */
    
    gluLookAt(45.0+CAMERA_MOD, 45.0+CAMERA_MOD, 20.0+(CAMERA_MOD*.5),  /* eye */
              0.0, 0.0, 0.0,      /* center */
              0.0, 0.0, 1.0);     /* up definition */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
/**
 * Switch to ortho mode
 */
void orthoView( ) {
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-45.0, 45.0, -45.0, //left, right, bottom
            45.0, 1.0, 200.0);//top, near, far
    gluLookAt(45.0,45.0,20.0,  /* eye */
              0.0, 0.0, 0.0,      /* center */
              0.0, 0.0, 1.0);     /* up definition */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
/**
 * Switch to a custom view
 */
void customView( ) {
    
    
    /* Retrieve parameters from user through console */
    float fov, ratio, near, far;
    std::cout << "Enter the desired field of vision: ";
    std::cin >> fov; std::cout << std::endl;
    std::cout << "Enter the desired aspect ratio: ";
    std::cin >> ratio; std::cout << std::endl;
    std::cout << "Enter the desired near value: ";
    std::cin >> near; std::cout << std::endl;
    std::cout << "Enter the desired far value: ";
    std::cin >> far; std::cout << std::endl;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( fov,        /* FOV */
                   ratio,      /* Aspect ratio */
                   near, far); /* near, far */
    
    gluLookAt(45.0+CAMERA_MOD, 45.0+CAMERA_MOD, 20.0+(CAMERA_MOD*.5),  /* eye */
              0.0, 0.0, 0.0,      /* center */
              0.0, 0.0, 1.0);     /* up definition */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/**
 * Handles the above three selections based off user menu iteraction
 */
void viewHandler( int selection ) {
    
    switch( selection ){
        case 1: orthoView(); break; //Ortho
        case 2: projectionView(); break; //Projection
        case 3: customView(); break; // Custom
        default: break; 
    }
}
