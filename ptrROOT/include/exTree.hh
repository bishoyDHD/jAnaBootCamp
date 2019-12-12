#ifndef exTree_h
#define exTree_h 1

#include <TTree.h>
#include "TRandom.h"

class exTree {
public:
  exTree();
  ~exTree();

  void initialVar();
  void fillVar();
  void initTree(TTree*);
  void clear();

private:
  double dx, dy, dz;
  TRandom* gRandom;
  typedef  std::vector < double > vecDouble;
/*
  vecDouble* px;
  vecDouble* py;
  vecDouble* pz;*/

  std::vector < double > px;
  std::vector < double > py;
  std::vector < double > pz;
};
#endif
