# Relative path to the ALREADY-COMPILED rpi-rgb-led-matrix code:
RGB_LIB_PATH=../../rpi-rgb-led-matrix
RGB_INCDIR=$(RGB_LIB_PATH)/include
RGB_LIBDIR=$(RGB_LIB_PATH)/lib
RGB_LIBRARY_NAME=rgbmatrix
RGB_LIBRARY=$(RGB_LIBDIR)/lib$(RGB_LIBRARY_NAME).a

# Relative path to the Adafruit_PixelDust library source:
PIXELDUST_PATH=..

CXXFLAGS=-Wall -Ofast -fomit-frame-pointer -funroll-loops -s -I$(RGB_INCDIR) -I$(PIXELDUST_PATH)
LDFLAGS=-L$(RGB_LIBDIR) -l$(RGB_LIBRARY_NAME) -lrt -lm -lpthread
LIBS=Adafruit_PixelDust.o lis3dh.o Collision.o $(RGB_LIBRARY)
LIB=$(RGB_LIBRARY)
EXECS=Collision

all: $(EXECS)

# Compile PixelDust library into current directory
Adafruit_PixelDust.o: $(PIXELDUST_PATH)/Adafruit_PixelDust.cpp $(PIXELDUST_PATH)/Adafruit_PixelDust.h
	$(CXX) $(CXXFLAGS) -c $<
	
Collision.o: $(PIXELDUST_PATH)/raspberry_pi/Collision.cpp $(PIXELDUST_PATH)/raspberry_pi/Collision.hpp
	$(CXX) $(CXXFLAGS) -c $< $(LIB)
	
# Minimalist LIS3DH code
lis3dh.o: lis3dh.cpp lis3dh.h
	$(CXX) $(CXXFLAGS) -c $<

Collision: Collision_Text.cpp $(LIBS)
	$(CXX) $(CXXFLAGS) $< $(LDFLAGS) $(LIBS) -o $@
	strip $@


clean:
	rm -f $(EXECS) *.o
