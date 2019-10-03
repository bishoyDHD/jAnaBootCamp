#include <iostream>
#include "TROOT.h"
#include "TFile.h"
#include "TNetFile.h"
#include "TRandom.h"
#include "TTree.h"
#include "TBranch.h"
#include "hello.h"

int main(){
  hello* ptr = new hello();
  TFile* hfile = new TFile("test.root", "RECREATE");
  TTree* tree  = new TTree("Sim", "From uniformRand");
  tree->SetAutoSave();
  tree->Branch("testBranch","hello",(TObject**)&ptr,128000,0);

  for(int i = 0; i < 2000; i++){
    ptr->fillVar(i);
    tree->Fill();
  }
  hfile->Write();
  hfile->Close();
  return 0;
}
