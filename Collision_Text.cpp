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
#include "Collision_Matrix.hpp"
//#include "Collision_Matrix.cpp"
#include "Adafruit_PixelDust.h"
#include "led-matrix-c.h"
#include "lis3dh.h"
#include <signal.h>
#include <iostream>
#include <iomanip>
using std::setw;
using namespace std;

#define N_GRAINS 800 ///< Number of sand grains on 64x64 matrix


Adafruit_LIS3DH lis3dh;
Collision_Matrix coll;
//Adafruit_PixelDust *sand = NULL;
volatile bool running = true;
int nGrains = N_GRAINS; // Runtime grain count (adapts to res)
struct RGBLedMatrix *matrix;





// Signal handler allows matrix to be properly deinitialized.
int sig[] = {SIGHUP,  SIGINT, SIGQUIT, SIGABRT,
             SIGKILL, SIGBUS, SIGSEGV, SIGTERM};
             
             

             
      
#define N_SIGNALS (int)(sizeof sig / sizeof sig[0])




void irqHandler(int dummy) {
  if (matrix) {
    led_matrix_delete(matrix);
    matrix = NULL;
  }
  for (int i = 0; i < N_SIGNALS; i++)
    signal(sig[i], NULL);
  running = false;
}


int main(int argc, char **argv) {
  struct RGBLedMatrixOptions options;
  struct LedCanvas *canvas;
  struct RGBLedMatrix *matrix;
  Adafruit_PixelDust *sand = NULL;
  int width, height, i, xx, yy, zz;
  dimension_t x, y;

  for (i = 0; i < N_SIGNALS; i++)
    signal(sig[i], irqHandler); // ASAP!

  // Initialize LED matrix defaults
  memset(&options, 0, sizeof(options));
  options.rows = 64;
  options.cols = 64;
  options.chain_length = 1;

  // Parse command line input.  --led-help lists options!
  matrix = led_matrix_create_from_options(&options, &argc, &argv);
  if (matrix == NULL)
    return 1;

  // Create offscreen canvas for double-buffered animation
  canvas = led_matrix_create_offscreen_canvas(matrix);
  led_canvas_get_size(canvas, &width, &height);
  //fprintf(stderr, "Size: %dx%d. Hardware gpio mapping: %s\n", width, height,
  

  if (width < 64)
    nGrains /= 2; // Adjust sand count


  if (lis3dh.begin()) {
    puts("LIS3DH init failed");
    return 2;
  }

  sand = new Adafruit_PixelDust(width, height, nGrains, 1, 64, true);
  if (!sand->begin()) {
    puts("PixelDust init failed");
    return 3;
  }


    //  for(i = 10; i < 50; i++){
    //  sand->setPixel(i, 16);
    // }
    //initBMP(A, 5, 20, 20);


  /*
  for (i = 0; i < height; i++) {
    w = (int)((1.0 - cos((double)i * M_PI * 2.0 / (double)(height - 1))) *
                  ((double)width / 4.0 - 1.0) +
              0.5);
    for (x = 0; x <= w; x++) {
      sand->setPixel(x, i);             // Left
      sand->setPixel(width - 1 - x, i); // Right
    }
  }
  */
  sand->randomize(); // Initialize random sand positions
  //coll.initMTX(A, 5, 20, 20);
  //initBMP(A, 5, 20, 20);
  while (running) {
    
    int kl = 111;
 
 
      if(kl == 111){
      yy += kl;
    }
    if(kl == -111){
      yy -=kl;
    }
      
      if(yy > 1200){
        kl = -111;
      }
      if(yy < -1200){
        kl = 111;
      }
   //         if(kl == 111){
   //   xx += kl;
   // }
   // if(kl == -111){
   //   xx -=kl;
    //}
      
     // if(xx > 1200){
     //   kl = -111;
      //}
      //if(xx < -1200){
     //  kl = 111;
     // }
 
  // printf("Decimals: %d %d", kl, yy);

    sand->iterate(0, yy, 0);

    // Canvas is cleared and both the hourglass and sand
    // grains are re-drawn every frame.  It's easier than
    // trying to erase-and-redraw when animation is
    // double-buffered.
    led_canvas_clear(canvas);
    /*
    for (i = 0; i < height; i++) { // Hourglass...
      w = (int)((1.0 - cos((double)i * M_PI * 2.0 / (double)(height - 1))) *
                    ((double)width / 4.0 - 1.0) +
                0.5);
      for (x = 0; x <= w; x++) {
        led_canvas_set_pixel(canvas, x, i, 32, 32, 96);             // Left
        led_canvas_set_pixel(canvas, width - 1 - x, i, 32, 32, 96); // Right
      }
    }
    */
     
    
    //for(i = 10; i < 50; i++){
    //  led_canvas_set_pixel(canvas, i, 16, 32, 32, 96);
    //}

    for (i = 0; i < nGrains; i++) { // Sand...
      sand->getPosition(i, &x, &y);
      led_canvas_set_pixel(canvas, x, y, 200, 200, 100);
    }
int a[5][5] = { {0, 0, 1, 0, 0},
                    {0, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {0, 1, 0, 1, 0},
                    {0, 1, 0, 1, 0} };  
//  int d[2][2] = {{0,1},
//                  {1, 0}};
    coll.drawMTX<5>(a, 5, 0, 0, 2, 2, 9);





    // Update matrix contents on next vertical sync
    // and provide a new canvas for the next frame.
    canvas = led_matrix_swap_on_vsync(matrix, canvas);
    kl = (kl + 1);
  }

  return 0;
}



#endif // !ARDUINO
