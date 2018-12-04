
#ifndef PROTOTYPES
#define PROTOTYPES

// FUNCTIONN PROTOTYPES //
//
void myglutInit( int, char**  );
void myInit(void);
void mouse( int, int, int, int );
void specialKeyboard( int, int, int );
void keyboard( unsigned char, int, int );
void animate( );
void createMenu( );
void display( );
void houseSign( );
void lightReset( );
void hardReset( );
void stopAnimation( );
void mouseAnimate( int, int, const float );
void axesLabels( );
void viewHandler( int );
void viewModeText();
void drawHouse();
void drawHouseLines();
void drawAxes(int);

#endif
