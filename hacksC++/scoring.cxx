// simple C++ program for scoring using a std::vector and a known value
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // enables usage of std::max, std::min
#include <random>
#include <map>
const double Mpi0=.134;

struct newv{
  double nx, ny, nz;
};
class mycont{
public:
  mycont();
  double px, py,pz;
  double x,y,z;
};
mycont::mycont(){}
class checker:public mycont{
public:
  checker();
  ~checker();
  void setVal(const std::vector<double> &, double);
  double getVal();
private:
  std::vector<mycont*> lookie;
  mycont *mc;
  double ya;
};
checker::checker(){
  mc=new mycont();
}
checker::~checker(){}
void checker::setVal(const std::vector<double> &vect, double m){
  for(int i=0; i<vect.size(); i++){
    mc->px=vect[i];
    mc->x=.04*vect[i];
    lookie.push_back(mc);
  }
  ya=m;
}
double checker::getVal(){
  return ya;
}
// scoring function: takes std::vector and known value
int score(std::vector<double> const & vec, double val){
  auto const it=std::lower_bound(vec.begin(),vec.end(), val);
  if(it==vec.end()){
    return -1;
  }
  return *it;
}
double csiscoring(std::vector<double> invMass,std::map<double,double> Mass){
  double masspi0,Mee;
  auto it=std::min_element(invMass.begin(),invMass.end());
  masspi0=*it;
  Mee=Mass[masspi0];
  return Mee;
}
void vectMerge(std::vector<double>& vect1,std::vector<double>& vect2){
  vect1.insert(
       vect1.end(),
       std::make_move_iterator(vect2.begin()),
       std::make_move_iterator(vect2.end())
       );
};
int main(){
  const int nrolls=1000; // number of experiments
  std::default_random_engine gen;
  std::normal_distribution<double> distribution(5.0,2.0);
  int p[10]={};
  //checker*ck=new checker();
  std::vector<double> vec;
  std::vector<double> vect2,vect3;
  newv nv;
  std::vector<newv> nvec;
  for(int i=0; i<nrolls; i++){
    double num=distribution(gen);
    if((num>0.0)&&(num<10.))++p[int(num)];
    nv.nx=num;   nv.ny=p[i];
    nvec.push_back(nv);
  }
  std::cout<<" ... checking some values before reseting\n";
  std::cout<<" ... nvec[0].nx= "<<nvec[0].nx<<"\t size= "<<nvec.size()<<std::endl;
  nvec.clear();
  //vec.push_back(2.01);
  //vec.push_back(4.12);
  vec.push_back(1.12);
  vec.push_back(-.12);
  vec.push_back(0.12);
  vec.push_back(5.12);
  //fill vect2
  vect2.push_back(-.42);
  vect2.push_back(3.12);
  vect2.push_back(7.12);
  // merge vec with values of vect2 appended
  vectMerge(vec,vect2);
  for(int i=0; i<vec.size(); i++){
    nv.nx=vec[i];
    nvec.push_back(nv);
  }
  for(int i=0; i<2; i++){
    int m=i+1;
    for(int n=m; n<3;n++){ 
      int s=n+1;
      for(int a=s; a<4; a++){ 
        //std::cout<<" we have: "<<i<<" + "<<n<<" + "<<a<<"\n";
	vect3.push_back(.1*(i+n+a));
      }
    }
  }
  std::cout<<" size of vect3 has changed from: "<<vect3.size();
  // merge vec with values of vect2 appended
  vectMerge(vect3,vect2);
  std::cout<<" to "<<vect3.size()<<std::endl;
  for(unsigned int i=0; i<vec.size(); i++){
    std::cout<<" ["<<i<<"] Vector values are: "<<vec[i]<<"\t"<<vect3[i]<<std::endl;
  }
  //ck->setVal(vec,44);
  std::cout<<" ... checking some values after reseting\n";
  std::cout<<" ... nvec[0].nx= "<<nvec[0].nx<<"\t size= "<<nvec.size()<<std::endl;
  std::vector<double>::iterator min=std::min_element(vec.begin(),vec.end());
  std::cout<<"min element for vector is" <<*min<<" at index "<<std::distance(vec.begin(),min)<<std::endl;
  
  return 0;
}
