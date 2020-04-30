#ifndef A_h
#define A_h

#ifndef ROOT_TObject
#include "TObject.h"
#endif

#include <map>
#include <vector>

using namespace std;

class A : public TObject
{

private:
  map<UInt_t, Float_t> fMap; // map
  pair<unsigned int, double> fPair; // pair
  vector < map<UInt_t, Float_t> > fVecMap; // vector of maps
  Int_t fValue; // value
public:
  A();
  virtual ~A();

  void SetValue(Int_t value) { fValue = value; }
  Int_t GetValue() const {return fValue;}

  void SetPair(UInt_t i, double val) { fPair.first = i; fPair.second = val; }
  pair<UInt_t, double> GetPair() const { return fPair; }

  void SetMap(UInt_t i, Float_t val) { fMap[i] = val; }
  map<UInt_t, Float_t> GetMap() const { return fMap; }

  void SetVector(vector< map<UInt_t, Float_t> > vec) {fVecMap = vec;}
  vector < map<UInt_t, Float_t> > GetVector() const { return fVecMap; }

  ClassDef(A, 1);  // class A
};

#endif
