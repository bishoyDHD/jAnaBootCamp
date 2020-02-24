// This is not an original code but was modified to suite my needs
// from information that I was able to find online
#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main(){
  int n,r;
  cout<<" Enter a value for \"n\" ";
  cin>>n;
  cout<<" Now enter a value for \"r\" ";
  cin>>r;
  vector<bool> v(n);
  vector<double> vect,pvec;
  double sum, cval; // sum and current value
  for(int i=0; i<10; i++){
    vect.push_back(1.1+1.001*i);
  }
  std::fill(v.begin(), v.begin()+r, true);
  do{
    sum=0,cval=0;
    pvec.clear();
    for(int i=0; i<n; i++){
      if(v[i]){
        cout<< i <<": "<<vect[i]<< ": ";
	cval=vect[i];
	sum+=cval;
	pvec.push_back(i);
      }
    }
    cout<<" sum & pvec[0], pvec[1]: "<<sum<<" & "<<pvec[0]<<", "<<pvec[1]<<"\n";
  }while(std::prev_permutation(v.begin(), v.end()));
  return 0;
}
