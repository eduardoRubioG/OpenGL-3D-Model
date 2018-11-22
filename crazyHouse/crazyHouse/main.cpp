//
//  main.cpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/22/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//

#include <iostream>
#include "include.h"


int main(int argc,  char** argv ) {
    myglutInit(argc, argv);
    myInit();
    glutMouseFunc(mouse);
    glutSpecialFunc(specialKeyboard);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;

}
