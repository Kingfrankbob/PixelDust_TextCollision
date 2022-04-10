/*!
 * Intro:
 * Decided to make a function that draws matricies into the screen and gice them collision
 * ONLY 5x5 MATRIX TESTED SO FAR
 * Dependencies:Adafruit PixelDust library
 * Author: Michael Cragun
 * BSD license, all text here must be included in any redistribution.
 */
#include "Collision_Matrix.hpp"
#include "Adafruit_PixelDust.h"
#include "led-matrix-c.h"
#include <signal.h>
#include <iostream>
#include <iomanip>
//using std::setw;
using namespace std;
struct LedCanvas *canvas;
struct RGBLedMatrix *matrix;
Adafruit_PixelDust *sand = NULL;


namespace Collision_Matrix{
/*
void Collision_Matrix::drawMTX(int a[], int L, int H, int x, int o, int R, int G, int B){
         for ( int j = 0; j < L; j++, o++) {
           for (int l = 0; l < H; l++){
            if((a) == 1){
                led_canvas_set_pixel(canvas, x + l, o, R, G, B);
            }
           }  
      }
 }
*/

 void initMTX(long long int a, int L, int H, int x, int y){
          int tst[];
          int rd[][];
          for (int i = (L*H); i >=0; i--){
            tst[i] = a % 10;
            a /= 10;
          }
        int g;
        for(int r = 0; r = H; r++){
          for(int p = 0; p = L; p++){
              rd[r][p] = tst[g];
              g++;
          }
        }
        for ( int j = 0; j < L; j++, o++) {
           for (int l = 0; l < H; l++){
              if(rd[j][h] == 1){
               sand->setPixel(x+l, o);
              }
           }  
      }
 }

}
 



