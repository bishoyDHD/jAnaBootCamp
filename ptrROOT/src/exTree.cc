#include <vector>
#include "exTree.hh"

//ROOT modules
#ifndef __CINT__
#include <iostream>
#endif
#include <TROOT.h>
#include <TFile.h>

exTree::exTree(){
  dx = 0.; dy = 0.; dz = 0.;
}

exTree::~exTree(){

}

void exTree::initialVar(){/*
  px.clear();
  px.clear();
  px.clear();*/
}

void exTree::fillVar(){
/*  px = new vecDouble();
  py = new vecDouble();
  pz = new vecDouble();
*/
  //fill tree variables
  for(int i = 0; i < 1000; i+=1){
    //gRandom->Rannor(dx, dy);
    dx = 100; dy = 2*dx;
    dz = dx*dx + dy*dy;
    std::cout << "\n checking the validity of the following: ";
    std::cout << "\n dx [ " << dx << " ] ";
    std::cout << "\n dy [ " << dy << " ] ";
    std::cout << "\n dz [ " << dz << " ]\n";
    px.push_back(dx);
    py.push_back(dy);
    pz.push_back(dz);
  }
}

void exTree::initTree(TTree* t){
  t->Branch("px", &px); //, "dx/D");
  t->Branch("py", &py); //, "dy/D");
  t->Branch("pz", &pz); //, "dz/D");
}

void exTree::clear(){/*
  delete px;
  delete py;
  delete pz;*/
}

















