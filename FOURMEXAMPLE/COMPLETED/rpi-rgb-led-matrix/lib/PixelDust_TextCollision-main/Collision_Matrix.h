#ifndef _COLLISION_MATRIX_H_
#define _COLLISION_MATRIX_H_


#ifdef ARDUINO
#include <Arduino.h>
#else

class Collision_Matrix {
public:
  
  
  template<int H>
  void Collision_Matrix::drawMTX(double a[][H], int L, int x, int o, int R, int G, int B);
  
  
  template<int H>
  void Collision_Matrix::initMTX(double a[][H], int L, int x, int o);
  

#endif // _COLLISION_MATRIX_H_
  
