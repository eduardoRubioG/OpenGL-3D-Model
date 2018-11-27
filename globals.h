//
//  globals.hpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/22/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//

#ifndef globals_h
#define globals_h

#include <stdio.h>

/* Window specfications */
const int WINDOW_POSITION_X = 100;
const int WINDOW_POSITION_Y = 100;
const int WINDOW_MAX_X = 800;
const int WINDOW_MAX_Y = 800;

const float WORLD_COORDINATES_MIN_X = 0.0;
const float WORLD_COORDINATES_MAX_X = 800.0;
const float WORLD_COORDINATES_MIN_Y = 0.0;
const float WORLD_COORDINATES_MAX_Y = 800;

float X_DELTA_SPIN = 0;
float Y_DELTA_SPIN = 0;
float Z_DELTA_SPIN = 0;
float X_SPIN = 0;
float Y_SPIN = 0;
float Z_SPIN = 0;

int CAMERA_MOD = 0; //Will be used to zoom in and out of the scene 

/* For menu use */
bool IS_WIREFRAME = false;
bool AXES_DRAWN = true;
int VIEW_MODE = 2; // 1 = ortho, 2 = projection, 3 = custom -- Projection by default 


#endif
