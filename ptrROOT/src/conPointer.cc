#include <iostream>
#include <string>
#include <vector>

#include "conPointer.hh"

conPointer* conPointer::fmanager = NULL;

conPointer* conPointer::getInstance(){
  if(fmanager == NULL)
    fmanager = new conPointer();
  return fmanager;
}

conPointer::conPointer(){
  fexTree = new exTree();
}

conPointer::~conPointer(){

}

void conPointer::initRoot(TTree* t){
  fexTree->initTree(t);
}

void conPointer::clear(){
  fexTree->clear();
}
