// write a function get_double that reads from stdin until a valid number is fed.

#include<iostream>

double get_double(){
  double i;
  while(!(std::cin >> i)){
    std::cin.clear();
    std::cin.ignore();
  }//while
  return i;
}

int main(){

  double number;
  number=get_double();
  std::cout<<"Program terminates after detecting "<<number<<std::endl;
  return 0;

}//main
