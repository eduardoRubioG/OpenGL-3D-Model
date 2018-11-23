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
#include "axes.cpp"
#include "house.cpp"
#include "animation.cpp"
#include "init.cpp"
#include "input.cpp"


#endif /* include_hpp */
