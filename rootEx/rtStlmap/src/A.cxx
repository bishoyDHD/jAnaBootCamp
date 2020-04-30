#include "A.h"
#include <iostream>

ClassImp(A);

A::A() : TObject()
{
  cout << "constructor" << endl;
  fValue = -1;
}

A::~A()
{
  cout << "destructor" << endl;
}
