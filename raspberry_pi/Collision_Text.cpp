/*!
 * @file demo2-hourglass.cpp
 *
 * Slightly more complex example for Adafruit_PixelDust on Raspberry Pi.
 * Has obstacles for particles to move around.
 * REQUIRES rpi-rgb-led-matrix LIBRARY!
 * I2C MUST BE ENABLED using raspi-config!
 *
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


            
 double A[5][5] = { {0, 0, 1, 0, 0},
                    {0, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {0, 1, 0, 1, 0},
                    {0, 1, 0, 1, 0} };
                    
template<int H> 
void drawBMP(struct LedCanvas *canvas, double a[][H], int L, int x, int o, int R, int G, int B){
         for ( int j = 0; j < L; j++, o++) {
           for (int l = 0; l < H; l++){
            if((a[j][l]) == 1){
                led_canvas_set_pixel(canvas, x + l, o, R, G, B);
            }
           }  
      }
 }

template<int H>
 void initBMP(double a[][H], int L, int x, int o){
        for ( int j = 0; j < L; j++, o++) {
           for (int l = 0; l < H; l++){
            if((a[j][l]) == 1){
              sand->setPixel(x+l, o);
            }
           }  
      }
 }

#endif // !ARDUINO
