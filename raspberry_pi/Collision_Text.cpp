/*
LIBRARY CREATED BY Michael Cragun
FOR USE ON ADAFRUIT LED MATRIXES
CREATES BITMAPS AND THE COLLISION FOR THE SAND
*/

#ifndef ARDUINO // Arduino IDE sometimes aggressively builds subfolders
//VS CODE SYNC?
#include "Adafruit_PixelDust.h"
#include "led-matrix-c.h"
#include "lis3dh.h"
#include <signal.h>
#include <iostream>
#include <iomanip>
using std::setw;
using namespace std;

//#define N_GRAINS 800 ///< Number of sand grains on 64x64 matrix

struct RGBLedMatrix *matrix;
Adafruit_PixelDust *sand = NULL;


template<int H> 
void Collision::drawBMP(struct LedCanvas *canvas, double a[][H], int L, int x, int o, int R, int G, int B){
         for ( int j = 0; j < L; j++, o++) {
           for (int l = 0; l < H; l++){
            if((a[j][l]) == 1){
                led_canvas_set_pixel(canvas, x + l, o, R, G, B);
            }
           }  
      }
 }

template<int H>
 void Collision::initBMP(double a[][H], int L, int x, int o){
        for ( int j = 0; j < L; j++, o++) {
           for (int l = 0; l < H; l++){
            if((a[j][l]) == 1){
              sand->setPixel(x+l, o);
            }
           }  
      }
 }

#endif // !ARDUINO
