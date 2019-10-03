#ifndef hello_h
#define hello_h 1

#include <TTree.h>
#include "TRandom.h"
#include <TObject.h>

class hello : public TObject {
public:
  hello();
  ~hello();
  void fillVar(int);
  Double_t px, py, pz;
  ClassDef(hello, 2);
};
#endif
