// Template class to check if an array has a value greater than k
// we then count the number of elements
#include <iostream>
#include <array>

// Template CLASS to return the count of elements 
// from the array which are greater than k 
template <typename T,std::size_t N>
class greaterThan{
private:
  int l,r;
  int leftGreater;
  int size;
public:
  greaterThan(std::array<T,N> arr, int n,T k);
  T countGreater();
};
template<typename T,std::size_t N>
greaterThan<T,N>::greaterThan(std::array<T,N> arr, int n,T k) { 
  size=n;
  l = 0; 
  r = n - 1; 
  
  // Stores the index of the left most element 
  // from the array which is greater than k 
  leftGreater = n; 
  
  // Finds number of elements greater than k 
  while (l <= r) { 
    int m = l + (r - l) / 2; 
    
    // If mid element is greater than 
    // k update leftGreater and r 
    if (arr[m] > k) { 
      leftGreater = m; 
      r = m - 1; 
    } 
    // If mid element is less than 
    // or equal to k update l 
    else
      l = m + 1; 
    std::cout<<"checking how this works: "<<l<<" : "<<m<<" : "<<leftGreater<<std::endl;
  } 
  
  // Return the count of elements greater than k 
  //countGreater();
} 
template<typename T,std::size_t N>
T greaterThan<T,N>::countGreater(){
  return (size - leftGreater); 
}

int main() { 
  std::array<int,9> arr={3, 3, 4, 7, 7, 7, 11, 13, 13};
  //int n = sizeof(arr) / sizeof(arr[0]); 
  
  const int n=arr.size();
  int k = 7;
  greaterThan<int,n> gT(arr, n, k); 
  std::cout <<gT.countGreater()<<std::endl; 
  
  return 0; 
} 

