/*!
 * Intro:
 * Decided to make a function that draws matricies into the screen and gice them collision
 * ONLY 5x5 MATRIX TESTED SO FAR
 * Dependencies:Adafruit PixelDust library
 * Author: Michael Cragun
 * BSD license, all text here must be included in any redistribution.
 */
#include "Collision.hpp"
#include "Adafruit_PixelDust.h"
#include "led-matrix-c.h"
#include <signal.h>
#include <iostream>
#include <iomanip>
//using std::setw;
using namespace std;
struct LedCanvas *canvas;
//struct RGBLedMatrix *matrix;
Adafruit_PixelDust *sand = NULL;


namespace Collision{


void initMTX(int a[], int L, int Y, int x, int y){
          for (int j = 0; j < L; j++, y++) {
           for (int l = 0; l < Y; l++){
            if((a[j]) == 1){
              cout << x << endl;
              sand->setPixel(x + l, y); 
            }
           }  
      }
 }
 
 template<size_t size> int fooy(int x[][size], int a, int o, int R, int G, int B){
   for(int U = 0; U < 5; U++, o++){
     for(size_t i = 0; i < size; i++){
       if(x[U][i] == 1){
          //cout << x[U][i] << ", " << endl;
         //led_canvas_set_pixel(canvas, a + i, o, R, G, B);
         return(a + i);
       }
 }
 
   }
 
}

 template<size_t size> int foox(int x[][size], int a, int o, int R, int G, int B){
   for(int U = 0; U < 5; U++, o++){
     for(size_t i = 0; i < size; i++){
       if(x[U][i] == 1){
  //        cout << x[U][i] << ", " << endl;
  //       led_canvas_set_pixel(canvas, a + i, o, R, G, B);
            return(o);
       }
 }
 
   }
 
}


template int fooy<5>(int x[][5], int a, int o, int R, int G, int B);
template int foox<5>(int x[][5], int a, int o, int R, int G, int B);


void adatest(){
  cout<<"SUP"<<endl;
}

}
