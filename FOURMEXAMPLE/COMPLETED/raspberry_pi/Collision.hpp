#ifndef _COLLISION_H_
#define _COLLISION_H_

//#include <cstddef>
//#include <ostream>
//#include <iostream>

namespace Collision{

  
  
  // template<int H>
  // void drawMTX(int a[][H], int L, int x, int o, int R, int G, int B);
  
  

  void initTHING(long long int a, int L, int H, int x, int y);
  
  template<unsigned size>  void foox(int x[][size],  int a, int o, int R, int G, int B);
  
  template<unsigned size>  void fooy(int x[][size],  int a, int o, int R, int G, int B);
  
  void adatest();


}

#endif // _COLLISION_H_
  
