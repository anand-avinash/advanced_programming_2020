// write a function get_int that reads from stdin until a valid number is fed

#include<iostream>

int get_int(){
  int i;
  while(!(std::cin >> i)){
    std::cin.clear();
    std::cin.ignore();
  }//while
  return i;
}

int main(){

  int integer;
  integer=get_int();
  std::cout<<"Program terminates after detecting "<<integer<<std::endl;
  return 0;

}//main
