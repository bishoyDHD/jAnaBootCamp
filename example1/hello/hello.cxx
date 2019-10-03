#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include "hello.h"

ClassImp(hello);

hello::hello(){
  std::cout << " Hello you freaking world! \n";
}

hello::~hello(){
}
void hello::fillVar(int n){
  double min, max, div, range;
  min = 180.00;
  max = 300.0; 
  for(int i = 0; i < n; i++){
    range = max - min;
    div = RAND_MAX/range;
    px = (min + (int)(rand()/div));
    py = pow(px, 2.0);
    pz = px * py;
    //std::cout << " px, py, pz : [" << px << ", " << py << ", " << pz << "] \n";
  }
}
