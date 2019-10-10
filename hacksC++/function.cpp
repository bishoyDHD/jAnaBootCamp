#include <iostream>
#include <vector>
#include <string>
#include <map>
// Example of different used of a class
// will have some function in the class that pass
// different vector arguments
// Will be passing vectors by reference and see how the 
// situations differ
class func{
public:
  func(); // default constructor
  ~func(); // destructor --> called at end of program

  // Add some fuctions onto which different values will be passed
  // pass by value function
  void function1(std::vector<double> vect);
  // pass by reference function
  void function2(std::vector<double> &vect);
  // pass by reference with restricted modification
  void function3(const std::vector<double> &vect);
private:
  std::vector<double> vect1,vect2,vect3;
};
func::func(){
}
func::~func(){
}
// various class functions
void func::function1(std::vector<double> vect){
  vect.push_back(45.88);
}
void func::function2(std::vector<double> &vect){
  vect.push_back(55.88);
}
void func::function3(const std::vector<double> &vect){
  //vect.push_back(45.88); // uncomment and compile to see what happens
  for(unsigned int i=0; i<vect.size(); i++){
    std::cout<<vect[i]<<"\n";
  }
}
// merge function to create a single composite vector
void vectMerge(std::vector<double>& vect1,std::vector<double>& vect2){
  vect1.insert(
       vect1.end(),
       std::make_move_iterator(vect2.begin()),
       std::make_move_iterator(vect2.end())
       );
};
// global function for filling vectors
// utilized switch-statement
void glfunc(int n,std::vector<double> &vec){
  func fn3; // create class object
  std::vector<double> vect;
  // use the switch statement only for even n
  switch(n){
    case 2:
      vect.push_back(2.0);
      vect.push_back(2.2);
      vectMerge(vect,vec);
      fn3.function3(vect);
      break;
    case 8:
      vect.push_back(4.0);
      vect.push_back(4.4);
      vectMerge(vect,vec);
      fn3.function3(vect);
      break;
  }// end of switch statement
}
// default main function
int main(){
  std::vector<double> vect;
  func fn;
  // always a good idea to clear a std::vector
  // i.e emptying the std::vector
  vect.clear();
  vect.push_back(12.44);
  vect.push_back(2.4);
  vect.push_back(11.34);
  vect.push_back(22.45);
  vect.push_back(13.75);
  vect.push_back(72.11);
  // manipulate various functions from the class
  fn.function2(vect);
  for(unsigned int i=0; i<vect.size(); i++){
    std::cout<<" ... "<<vect[i]<<"\n";
  }
  /*
  // check case with switch statement
  for(unsigned int i=0; i<vect.size(); i++){
    glfunc(i,vect);
    std::cout<<" ... "<<vect[i]<<"\n";
  }
  */
  return 0;
}
