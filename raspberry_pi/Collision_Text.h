/*!
 * Used with Adafruit products
 *
 * Written by Michael Cragun
 *
 * BSD license, all text here must be included in any redistribution.
 *
 */








#ifndef _COLLISION_TEXT_H_
#define _COLLISION_TEXT_H_

#ifdef ARDUINO
#include <Arduino.h>
#else
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#endif


class Collision_Text {
public:
  bool begin(void);
  void initBMP(struct LedCanvas *canvas, double a[][H], int L, int x, int o, int R, int G, int B);
  void drawBMP(double a[][H], int L, int x, int o);
    
    
};
#endif
