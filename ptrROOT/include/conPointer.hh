#ifndef conPointer_h
#define conPointer_h 1

#include <TTree.h>
#include "exTree.hh"

class conPointer {
public:
  conPointer();
  ~conPointer();
  static conPointer* getInstance();

public:
  void initRoot(TTree*);
  void clear();
  static conPointer* fmanager;

private:
  exTree* fexTree;
};
#endif
