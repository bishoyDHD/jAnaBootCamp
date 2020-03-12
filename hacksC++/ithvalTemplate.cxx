// Template Class that returns the value of
// the ith index in order of greatest stored value
#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
using namespace std; 
template<typename T>
class nthval{
public:
  std::size_t getnthVal(const std::vector<T> &vec,std::size_t k);
};
template<typename T>
std::size_t nthval<T>::getnthVal(const std::vector<T> &vec,std::size_t k){
  std::vector<std::size_t> indexes(vec.size());
  std::iota(indexes.begin(), indexes.end(), 0);
  std::nth_element(indexes.begin(), indexes.begin() + k, indexes.end(),
      [&](int lhs, int rhs){
          return vec[lhs] > vec[rhs];
      }   
  );  
  return indexes[k];
} 
int main(){
  nthval<double> nth;
  std::vector<double> vect;
  vect.push_back(99);
  vect.push_back(12.32);
  vect.push_back(101.55);
  vect.push_back(22);
  vect.push_back(88.88);
  
  for (std::size_t i = 0; i != vect.size(); ++i) {
    const auto index = nth.getnthVal(vect, i);
    std::cout << i << "th greater is at index " << index
        << " with value " << vect[index] << std::endl;
  }
}
