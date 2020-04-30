#include "A.h"
#include "TTree.h"
#include "TBranch.h"
#include "TFile.h"
#include <iostream>

using namespace std;

void read(const Char_t* fname)
{
  A *event = new A;
  vector< map<UInt_t, Float_t> > Vec;
  map<UInt_t, Float_t> Map;

  TFile file(fname);
  TTree *tree = dynamic_cast<TTree*>( file.Get("tree") );
  tree->Print();
  tree->SetBranchAddress("event",  &event);
  

  for (Int_t i=0; i<tree->GetEntries(); i++) {
    tree->GetEntry(i);
    cout << "event: " << i << '\t';
    cout << "fValue: " << event->GetValue() << '\t';
    cout << "fPair: " << event->GetPair().second << '\t';
    cout << "fMap: " << event->GetMap()[i] << endl;
    Vec = event->GetVector();
    //    cout << "  vector.size(): " << Vec.size() << endl;
    for (UInt_t j=0; j<Vec.size(); j++) {
      Map = Vec.at(j);
      cout << " Map[" << j << "]: " << Map[j] << endl;
    }
  }
}


int main()
{
  vector < map<UInt_t, Float_t> > Vec;
  map<UInt_t, Float_t> Map;

  TFile *file = new TFile("testmap.root", "recreate");
  TTree *tree = new TTree("tree", "tree title");

  A *event = new A;
  TTree::SetBranchStyle(1);
  TBranch *branch = tree->Branch("event", &event, 16000, 1);
  branch->SetAutoDelete(kFALSE);

  for (int i=0; i<10; i++) {
    event->SetValue(i+1);
    event->SetPair(i, i+1);
    event->SetMap(i, i+1);

    Vec.clear();
    Map.clear();
    for (UInt_t j=0; j<(UInt_t)i+1; j++) {
      Map[j] = (Float_t)(i+j);
      Vec.push_back(Map);
    }
    event->SetVector(Vec);
    tree->Fill();
  }

  file->Write();
  file->Close();
  delete file;
  delete event;

  read("testmap.root");

  return 0;
}

