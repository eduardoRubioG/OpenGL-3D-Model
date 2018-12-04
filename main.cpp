//
//  main.cpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/22/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//

#ifndef MAIN
#define MAIN

#include <iostream>
#include "include.h"
#include "prototypes.h"

int main(int argc,  char** argv ) {
    myglutInit(argc, argv);
    myInit();
    glutMouseFunc(mouse);
    glutSpecialFunc(specialKeyboard);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(animate);
    createMenu(); 
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;

}

#endif

