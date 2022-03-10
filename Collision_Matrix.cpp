/*!
 * Intro:
 * Decided to make a function that draws matricies into the screen and gice them collision
 * ONLY 5x5 MATRIX TESTED SO FAR
 * Dependencies:Adafruit PixelDust library
 * Author: Michael Cragun
 * BSD license, all text here must be included in any redistribution.
 */
#include "Collision_Matrix.h"
#include "Adafruit_PixelDust.h"
#include "led-matrix-c.h"
#include <signal.h>
#include <iostream>
#include <iomanip>
using std::setw;
using namespace std;
struct LedCanvas *canvas;
struct RGBLedMatrix *matrix;
  
template<int H> 
void Collision_Matrix::drawMTX(double a[][H], int L, int x, int o, int R, int G, int B){
         for ( int j = 0; j < L; j++, o++) {
           for (int l = 0; l < H; l++){
            if((a[j][l]) == 1){
                led_canvas_set_pixel(canvas, x + l, o, R, G, B);
            }
           }  
      }
 }
template<int H>
 void Collision_Matrix::initMTX(double a[][H], int L, int x, int o){
        for ( int j = 0; j < L; j++, o++) {
           for (int l = 0; l < H; l++){
            if((a[j][l]) == 1){
              sand->setPixel(x+l, o);
            }
           }  
      }
 }

