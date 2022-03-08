/*!
 * Intro:
 * Decided to make a function that draws matricies into the screen and gice them collision
 * ONLY 5x5 MATRIX TESTED SO FAR
 * Dependencies:Adafruit PixelDust library
 * Author: Michael Cragun
 * BSD license, all text here must be included in any redistribution.
 */
#ifndef _COLLISION_MATRIX_H_
#define _COLLISION_MATRIX_H_


#ifdef ARDUINO
#include <Arduino.h>
#endif

class Collision_Matrix {
public:
  
  
  template<int H>
  void drawMTX(double a[][H], int L, int x, int o, int R, int G, int B);
  
  
  template<int H>
  void initMTX(double a[][H], int L, int x, int o);
  
};

#endif // _COLLISION_MATRIX_H_X_H_
  
