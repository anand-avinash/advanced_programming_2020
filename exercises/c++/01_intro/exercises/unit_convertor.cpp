// Write a code that reads a number with its proper unit of measure, and prints back that number according to the SI units

#include<iostream>

void unit_conversion(double& var){
  std::cout<<var*10.0<<"\t mm"<<std::endl;
  std::cout<<var<<"\t cm"<<std::endl;
  std::cout<<var/100.0<<"\t m"<<std::endl;
}//unit_conversion

int main(){

  double var;
  std::string unit;

  std::cout<<"Enter the input as: [NUMBER] [UNIT]\nUNIT can be inch/foot/yard"<<std::endl;

  std::cin >> var;
  std::cin >> unit;

  std::cout<<"That's equivalent to:"<<std::endl;

  if(unit=="inch"||unit=="in"){
    var*=2.54; // converted to cm
    unit_conversion(var);
  } else if(unit=="foot"||unit=="ft"){
    var*=30.48; // converted to cm
    unit_conversion(var);
  } else if(unit=="yard"||unit=="yd"){
    var*=91.44; // converted to cm
    unit_conversion(var);
  } else{
    std::cout<<"Please provide a valid input"<<std::endl;
  }//if
  
}//main
