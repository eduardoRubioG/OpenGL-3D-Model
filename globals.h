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
extern const int WINDOW_POSITION_X;
extern const int WINDOW_POSITION_Y;
extern const int WINDOW_MAX_X;
extern const int WINDOW_MAX_Y;

extern const float WORLD_COORDINATES_MIN_X;
extern const float WORLD_COORDINATES_MAX_X;
extern const float WORLD_COORDINATES_MIN_Y;
extern const float WORLD_COORDINATES_MAX_Y;

extern float X_DELTA_SPIN0;
extern float Y_DELTA_SPIN0;
extern float Z_DELTA_SPIN0;
extern float X_SPIN;
extern float Y_SPIN;
extern float Z_SPIN;

extern int CAMERA_MOD; //Will be used to zoom in and out of the scene 

/* For menu use */
extern bool IS_WIREFRAME;
extern bool AXES_DRAWN;
extern bool HOUSE_SIGN; 
extern int  VIEW_MODE; 


#endif
