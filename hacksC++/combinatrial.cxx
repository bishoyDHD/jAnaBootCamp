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
  cout<<"\n Now enter a value for \"r\" ";
  cin>>r;
  cout<<"\n";
  vector<bool> v(n);
  std::fill(v.begin(), v.begin()+r, true);
  do{
    for(int i=0; i<n; i++){
      if(v[i]){
        cout<< i <<" ";
      }
    }
    cout<<"\n";
  }while(std::prev_permutation(v.begin(), v.end()));
  return 0;
}
