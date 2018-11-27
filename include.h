//
//  include.hpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/22/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//

#ifndef include_hpp
#define include_hpp

//Linux Headers
#ifdef LINUX
#include <GL/glut.h>
#endif

//Mac Headers
#ifdef OSX
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif

#include <stdio.h>
#include "globals.h"
#include "animation.cpp"
#include "views.cpp"
#include "text.cpp"
#include "house.cpp"
#include "input.cpp"
#include "menu.cpp"
#include "axes.cpp"
#include "init.cpp"





#endif /* include_hpp */
