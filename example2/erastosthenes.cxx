#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void process_prime(bool *p,int max_n,int n);
int main(){
  int max_n=0;
  cout<<" Calculate primes up to what number? ";
  cin>>max_n;
  bool* p=new bool[max_n+1]; // allocate arry
  for(int i=2; i<=max_n; i++){
    p[i]=true;
  }
  for(int i=2; i<=max_n; i++){
    if(p[i]){
      process_prime(p, max_n, i);
    }
  }
  cout<<"\n";
  delete []p;
  cin.ignore(); // consume last carriage return
  cin.ignore(); // wait for the user to press ENTER
  return 0;
}
// Print prime number n passed to the function,
// => flag all the elements in the Boolean arry (p)
// that correspond to a multiple of n as false
// so, p[i]<=false if i is multiple of n
void process_prime(bool* p,int max_n,int n){
  cout<<" "<<n<<"\t";
  for(int i=n+n; i<=max_n; i+=n){
    p[i]=false;
  }
}
