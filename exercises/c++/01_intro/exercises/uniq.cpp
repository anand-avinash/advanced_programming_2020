#include<iostream>
#include<string>
#include<iomanip>

int main(){
  std::string prev_line {"\0"}, cur_line;
  int count {1};

  // You can toggle the comment between the `for` and `while` loop
  // They both are equivalent in the context of this program
  // so the program will behave the same with any of them without any complain

  //for(; std::getline(std::cin, cur_line);){
  while(std::getline(std::cin, cur_line)){
    if(cur_line.empty()) cur_line="\n"; // We want to detect empty lines in order to match the functionality with `uniq` command
    // To be able to work with empty lines, I am assigning the empty lines the value `\n`
    if(cur_line!=prev_line){
      if(prev_line!="\0"){ // To avoid printing artificially intialized variable
        if(prev_line=="\n"){
          std::cout<<std::setw(7)<<count<<std::endl;
        } else {
          std::cout<<std::setw(7)<<count<<" "<<prev_line<<std::endl;
        }//if
      }//if
      prev_line=cur_line;
      count=1;
      continue;
    }//if
    count++;    
  }//for_or_while

  std::cout<<std::setw(7)<<count<<" "<<prev_line<<std::endl;
  return 0;
}//main
