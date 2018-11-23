//
//  input.cpp
//  crazyHouse
//
//  Created by Eduardo Rubio on 11/22/18.
//  Copyright © 2018 Eduardo Rubio. All rights reserved.
//

#include <stdio.h>

/**
 * Defines mouse interaction
 */
void mouse( int button, int state, int x, int y ){
    
}

/**
 * Defines keyboard interaction for non-ASCII keys
 */
void specialKeyboard( int key, int x, int y ){
    
}

/**
 * Defines keyboard interaction for ASCII keys
 */
void keyboard( unsigned char key, int x, int y ){

    if( key == 'q' || key == 'Q' ) exit(0);
    if( key == 'z' || key == 'Z' ) Z_SPIN+=10; 
    if( key == 'x' || key == 'Z' ) X_SPIN+=10;
    if( key == 'y' || key == 'Z' ) Y_SPIN+=10;
    if( key == 'r' ) rotationSpin();
}
