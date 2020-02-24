#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
using namespace std; 
struct MyOwnClass { int score; };
typedef vector<double> ve;
extern ve myvec;
ve myvec;
std::size_t get_index_of_nth_greatest(ve, std::size_t k){
  std::vector<std::size_t> indexes(myvec.size());
  std::iota(indexes.begin(), indexes.end(), 0);
 
  std::nth_element(indexes.begin(), indexes.begin() + k, indexes.end(),
      [&](int lhs, int rhs)
      {
          return myvec[lhs] > myvec[rhs];
      }
  );
  return indexes[k];
}
 
class nval{
public:
  std::size_t getnthVal(const std::vector<double> &vec,std::size_t k);
};
std::size_t nval::getnthVal(const std::vector<double> &vec,std::size_t k){
  std::vector<std::size_t> indexes(vec.size());
  std::iota(indexes.begin(), indexes.end(), 0);
  std::nth_element(indexes.begin(), indexes.begin() + k, indexes.end(),
      [&](int lhs, int rhs)
      {
          return vec[lhs] > vec[rhs];
      }   
  );  
  return indexes[k];
} 
int main()
{
    myvec = {{2}, {4.2}, {101.5}, {20.1}, {1}, {3}};
    nval nth;
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
