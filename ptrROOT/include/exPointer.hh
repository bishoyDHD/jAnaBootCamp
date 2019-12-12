#ifndef exPointer_h
#define exPointer_h 1

#include <string>

#include <TROOT.h>
#include <TTree.h>
#include <TFile.h>

class TFile;
class TTree;

class exPointer {
public:
  exPointer(); //constructor
  ~exPointer(); //destructor

  void testing();
  void writeRoot();
  void fillTree();
  void clear();
  TFile* hfile;
  TTree* tree;
private:
  std::string name;
};
#endif
