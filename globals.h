//
//  globals.hpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/22/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//

#ifndef globals_h
#define globals_h

/* Window specfications */
extern int WINDOW_POSITION_X;
extern int WINDOW_POSITION_Y;
extern int WINDOW_MAX_X;
extern int WINDOW_MAX_Y;

extern float WORLD_COORDINATES_MIN_X;
extern float WORLD_COORDINATES_MAX_X;
extern float WORLD_COORDINATES_MIN_Y;
extern float WORLD_COORDINATES_MAX_Y;

extern float X_DELTA_SPIN;
extern float Y_DELTA_SPIN;
extern float Z_DELTA_SPIN;
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
