//
//  menu.cpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/24/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//

#include <stdio.h>

/**
 * Handles all the user selections within the menu
 */
void menuEventHandler( int selection ){

    /* Switch between 3 view options */
    if( selection == 1 || selection == 2 || selection == 3 ) VIEW_MODE = selection; 
    
    /* Toggle house render options  */
    if( !IS_WIREFRAME && selection == 4 ) IS_WIREFRAME = true;
    if(  IS_WIREFRAME && selection == 5 ) IS_WIREFRAME = false;
    
    /* Toggle axes renderings */
    if(  !AXES_DRAWN && selection == 6) AXES_DRAWN = true;
    if(  AXES_DRAWN && selection == 7 ) AXES_DRAWN = false;
    
   /* Toggle Hello World Sign */
    if( !HOUSE_SIGN && selection == 8 ) HOUSE_SIGN = true;
    if( HOUSE_SIGN && selection == 9 ) HOUSE_SIGN = false;
    /* Reset House */ 
    if( selection == 10 ) hardReset();
    
    glutPostRedisplay();
}

/**
 * Create the menu frame
 */
void createMenu( ){
    
    /* Create the sub-menu for the perspective options */
    int perspective_menu = glutCreateMenu(menuEventHandler);
    
    glutAddMenuEntry("Orthographic", 1);
    glutAddMenuEntry("Projection", 2);
    glutAddMenuEntry("Custom", 3);
    
    
    /* Create the sub-menu for the house rendering */
    int house_render_menu = glutCreateMenu(menuEventHandler);
    
    glutAddMenuEntry("Wireframe", 4);
    glutAddMenuEntry("Full Render", 5);
    
    /* Sub-Menu for toggling the axes */
    int axes_menu = glutCreateMenu(menuEventHandler);
    
    glutAddMenuEntry("Toggle On", 6);
    glutAddMenuEntry("Toggle Off", 7);
    
    /* Sub-Menu for toggling 'Hello World' sign */
    int sign_toggle_menu = glutCreateMenu(menuEventHandler);
    
    glutAddMenuEntry("Toggle 'Hello World' On", 8);
    glutAddMenuEntry("Toggle 'Hello World' Off", 9);
    
    /* Create the main menu */
    int main_menu = glutCreateMenu(menuEventHandler);
    
    glutAddMenuEntry("Return House", 10);
    glutAddSubMenu("View", perspective_menu);
    glutAddSubMenu("Render Options", house_render_menu);
    glutAddSubMenu("Axes Toggle", axes_menu);
    glutAddSubMenu("Hello World Toggle", sign_toggle_menu);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    //glutAttachMenu(GLUT_MIDDLE_BUTTON);
}




