// Write a simple version of the Unix program uniq -c, which, when fed with a text, outputs the same text with consecutive identical lines collapsed into one prepended with the number of repetitions.

#include<iostream>
#include<string>
#include<iomanip>

void print_line(int& count, std::string& str){
  if(str=="\n"){
    std::cout<<std::setw(7)<<count<<std::endl;
  } else {
    std::cout<<std::setw(7)<<count<<" "<<str<<std::endl;
  }//if
}//print_line

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
        print_line(count, prev_line);
      }//if
      prev_line=cur_line;
      count=1;
      continue;
    }//if
    count++;    
  }//for_or_while

  print_line(count, prev_line);
  return 0;
}//main
