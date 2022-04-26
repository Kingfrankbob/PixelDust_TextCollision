#ifndef _COLLISION_MATRIX_H_
#define _COLLISION_MATRIX_H_


#ifdef ARDUINO
#include <Arduino.h>
#endif
#include "Collision_Matrix.h"
#include "Adafruit_PixelDust.h"
#include "led-matrix-c.h"
#include <signal.h>
#include <iostream>
#include <iomanip>
using std::setw;
using namespace std;

class Collision_Matrix {
public:
  
  template<int H>
void drawMTX(double a[][H], int L, int x, int o, int R, int G, int B);


template<int H>
 void initMTX(double a[][H], int L, int x, int o);

#endif // _COLLISION_MATRIX_H_
  
