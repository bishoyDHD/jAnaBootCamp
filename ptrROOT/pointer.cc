#include <iostream>
#include "exPointer.hh"
#include "exTree.hh"
#include "conPointer.hh"

int main(){
  exPointer exp;
  exTree extr;
  //conPointer conptr;
  exp.testing();

  double evtNum = 0.0;
  //std::cout << " Please enter number of events:  ";
  //std::cin >> evtNum;
  //for(int n = 0; n < evtNum; n += 1){
    //extr.initialVar();
    extr.fillVar();
  //}
  exp.fillTree();
  exp.writeRoot();
  //exp.clear();
}
