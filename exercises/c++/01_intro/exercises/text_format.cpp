// Write a simple text formatter that breaks the lines longer than a given number of characters. This formatter does not break words and leaves unmodified the lines shorter than the given threshold.

#include<iostream>
#include<string>

void preserve_newline(int& char_count){
  // This function detects and preserves the blank lines
  // present in the input text

  int trigger {0};  
  while(std::cin.get()=='\n'){
    trigger=1;
    std::cout<<"\n";
  }//while

  if(trigger==1){
    std::cin.unget();
    trigger=0;
    char_count=0;
  }//if
  
}//preserve_newline

int main(){

  int char_limit {50}, char_count {0}, temp_count;
  std::string str;

  preserve_newline(char_count);
  while(std::cin>>str){
    
    temp_count=char_count+str.length();
    if(temp_count>char_limit){ // `>` takes care of the count of space i.e. to be added later
      std::cout<<"\n";
      char_count=0;
    } else {
      char_count=temp_count+1;  // +1 is to add the count of added space
      // Note that I am adding +1 in the count after checking if it is under the
      // char_limit. So adding a space later doesn't contradicts the logic
    }//if

    std::cout<<str<<" ";
    preserve_newline(char_count);
  }//while

  return 0;

}//main
