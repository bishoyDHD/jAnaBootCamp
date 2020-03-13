// Not an original code:
// https://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects
// works well for user defined containers
#include <vector>
#include <iostream>
#include <algorithm>

struct MyStruct{
  int key;
  std::string stringValue;
  
  MyStruct(int k, const std::string& s) : key(k), stringValue(s) {}
  bool operator < (const MyStruct& str) const{
    return (key < str.key);
  }
};

struct less_than_key{
  inline bool operator() (const MyStruct& struct1, const MyStruct& struct2){
    return (struct1.key < struct2.key);
  }
};
// Driveer
int main(){
  std::vector < MyStruct > vec;

  vec.push_back(MyStruct(4, "test"));
  vec.push_back(MyStruct(3, "a"));
  vec.push_back(MyStruct(2, "is"));
  vec.push_back(MyStruct(1, "this"));

  // using the bool < operator
  std::sort(vec.begin(), vec.end());
  // using a second struct type to sort
  //std::sort(vec.begin(), vec.end(), less_than_key());
  for(unsigned int i=0; i<vec.size(); i++){
    std::cout<<"vec["<<i<<"] = "<<vec[i].key<<":"<<vec[i].stringValue<<std::endl;
  }
}
