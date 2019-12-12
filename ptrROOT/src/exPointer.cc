#include <iostream>
#include "exPointer.hh"
#include "conPointer.hh"

exPointer::exPointer(){
  name = "test.root";
}

exPointer::~exPointer(){
  //delete tree;
  //delete hfile;
}

void exPointer::testing(){
  hfile = new TFile(name.c_str(), "RECREATE");
  tree = new TTree("Toytree", "Testing");
  tree->SetAutoSave();
  conPointer* fptr = conPointer::getInstance();
  fptr->initRoot(tree);
  std::cout << " ****** THIS IS A TEST ****** \n";
}

void exPointer::writeRoot(){
  hfile->Write();
  hfile->Close();
}

void exPointer::fillTree(){
  tree->Fill();
}

void exPointer::clear(){
  conPointer::getInstance()->clear();
}
