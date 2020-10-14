# Exercises - Session 01

## Understanding Compiler Messages

- Do not put the `main()` function
  <details>
  <summary>Expand</summary>

  ```Cpp
  $ cat test.cpp
  #include<iostream>

    int var1 {43};
    double var2 {43.53};

    std::cout << "Hello, World!" << std::endl;
    std::cout << "var1=" << var1 << ", var2=" << var2 << std::endl;
    return 0;

  $ g++ test.cpp
  test.cpp:6:8: error: ‘cout’ in namespace ‘std’ does not name a type
      6 |   std::cout << "Hello, World!" << std::endl;
        |        ^~~~
  In file included from test.cpp:1:
  /usr/include/c++/10/iostream:61:18: note: ‘std::cout’ declared here
     61 |   extern ostream cout;  /// Linked to standard output
        |                  ^~~~
  test.cpp:7:8: error: ‘cout’ in namespace ‘std’ does not name a type
      7 |   std::cout << "var1=" << var1 << ", var2=" << var2 << std::endl;
        |        ^~~~
  In file included from test.cpp:1:
  /usr/include/c++/10/iostream:61:18: note: ‘std::cout’ declared here
     61 |   extern ostream cout;  /// Linked to standard output
        |                  ^~~~
  test.cpp:8:3: error: expected unqualified-id before ‘return’
      8 |   return 0;
        |   ^~~~~~

  $ clang test.cpp
  test.cpp:6:8: error: no type named 'cout' in namespace 'std'
    std::cout << "Hello, World!" << std::endl;
    ~~~~~^
  test.cpp:6:13: error: expected unqualified-id
    std::cout << "Hello, World!" << std::endl;
              ^
  test.cpp:7:8: error: no type named 'cout' in namespace 'std'
    std::cout << "var1=" << var1 << ", var2=" << var2 << std::endl;
    ~~~~~^
  test.cpp:7:13: error: expected unqualified-id
    std::cout << "var1=" << var1 << ", var2=" << var2 << std::endl;
              ^
  test.cpp:8:3: error: expected unqualified-id
    return 0;
    ^
  5 errors generated.

  ```

  </details>

- Typos in the function name (`Cout` instead of `cout`)
  <details>
  <summary>Expand</summary>
  
  ```Cpp
  $ cat test.cpp
  #include<iostream>

  int main(){
    int var1 {43};
    double var2 {43.53};

    std::Cout << "Hello, World!" << std::endl;
    std::cout << "var1=" << var1 << ", var2=" << var2 << std::endl;
    return 0;
  }
  
  $ g++ test.cpp
  test.cpp: In function ‘int main()’:
  test.cpp:7:8: error: ‘Cout’ is not a member of ‘std’; did you mean ‘cout’?
      7 |   std::Cout << "Hello, World!" << std::endl;
        |        ^~~~
        |        cout
  
  $ clang++ test.cpp
  test.cpp:7:8: error: no member named 'Cout' in namespace 'std'; did you mean  'cout'?
    std::Cout << "Hello, World!" << std::endl;
    ~~~~~^~~~
         cout
  /usr/bin/../lib/gcc/x86_64-redhat-linux/10/../../../../include/c++/10/  iostream:61:18: note: 'cout' declared here
    extern ostream cout;          /// Linked to standard output
                   ^
  1 error generated.

  ```
  
  </details>

- Typos in variable name
  <details>
  <summary>Expand</summary>
  
  ```Cpp
  $ cat test.cpp
  #include<iostream>

  int main(){
    int var1 {43};
    double var2 {43.53};

    std::cout << "Hello, World!" << std::endl;
    std::cout << "var1=" << var1 << ", var2=" << val2 << std::endl;
    return 0;
  }
  
  $ g++ test.cpp
  test.cpp: In function ‘int main()’:
  test.cpp:8:48: error: ‘val2’ was not declared in this scope; did you mean ‘var2’?
      8 |   std::cout << "var1=" << var1 << ", var2=" << val2 << std::endl;
        |                                                ^~~~
        |                                                var2
  
  $ clang++ test.cpp
  test.cpp:8:48: error: use of undeclared identifier 'val2'; did you mean 'var2'?
    std::cout << "var1=" << var1 << ", var2=" << val2 << std::endl;
                                                 ^~~~
                                                 var2
  test.cpp:5:10: note: 'var2' declared here
    double var2 {43.53};
           ^
  1 error generated.

  ```
  
  </details>

- Forgot to put `;`
  <details>
  <summary>Expand</summary>
  
  ```Cpp
  $ cat test.cpp
  #include<iostream>

  int main(){
    int var1 {43};
    double var2 {43.53};

    std::cout << "Hello, World!" << std::endl;
    std::cout << "var1=" << var1 << ", var2=" << var2 << std::endl
    return 0;
  }
  
  $ g++ test.cpp
  test.cpp: In function ‘int main()’:
  test.cpp:8:65: error: expected ‘;’ before ‘return’
      8 |   std::cout << "var1=" << var1 << ", var2=" << var2 << std::endl
        |                                                                 ^
        |                                                                 ;
      9 |   return 0;
        |   ~~~~~~
  
  $ clang++ test.cpp
  test.cpp:8:65: error: expected ';' after expression
    std::cout << "var1=" << var1 << ", var2=" << var2 << std::endl
                                                                  ^
                                                                  ;
  1 error generated.

  ```
  
  </details>

- Forgot to put `#include<iostream>`
  <details>
  <summary>Expand</summary>
  
  ```Cpp
  $ cat test.cpp
  int main(){
    int var1 {43};
    double var2 {43.53};

    std::cout << "Hello, World!" << std::endl;
    std::cout << "var1=" << var1 << ", var2=" << var2 << std::endl;
    return 0;
  }

  $ g++ test.cpp
  test.cpp: In function ‘int main()’:
  test.cpp:5:8: error: ‘cout’ is not a member of ‘std’
      5 |   std::cout << "Hello, World!" << std::endl;
        |        ^~~~
  test.cpp:1:1: note: ‘std::cout’ is defined in header ‘<iostream>’; did you forget   to ‘#include <iostream>’?
    +++ |+#include <iostream>
      1 | int main(){
  test.cpp:5:40: error: ‘endl’ is not a member of ‘std’
      5 |   std::cout << "Hello, World!" << std::endl;
        |                                        ^~~~
  test.cpp:1:1: note: ‘std::endl’ is defined in header ‘<ostream>’; did you forget  to ‘#include <ostream>’?
    +++ |+#include <ostream>
      1 | int main(){
  test.cpp:6:8: error: ‘cout’ is not a member of ‘std’
      6 |   std::cout << "var1=" << var1 << ", var2=" << var2 << std::endl;
        |        ^~~~
  test.cpp:6:8: note: ‘std::cout’ is defined in header ‘<iostream>’; did you forget   to ‘#include <iostream>’?
  test.cpp:6:61: error: ‘endl’ is not a member of ‘std’
      6 |   std::cout << "var1=" << var1 << ", var2=" << var2 << std::endl;
        |                                                             ^~~~
  test.cpp:6:61: note: ‘std::endl’ is defined in header ‘<ostream>’; did you forget   to ‘#include <ostream>’?
  
  $ clang++ test.cpp
  test.cpp:5:3: error: use of undeclared identifier 'std'
    std::cout << "Hello, World!" << std::endl;
    ^
  test.cpp:5:35: error: use of undeclared identifier 'std'
    std::cout << "Hello, World!" << std::endl;
                                    ^
  test.cpp:6:3: error: use of undeclared identifier 'std'
    std::cout << "var1=" << var1 << ", var2=" << var2 << std::endl;
    ^
  test.cpp:6:56: error: use of undeclared identifier 'std'
    std::cout << "var1=" << var1 << ", var2=" << var2 << std::endl;
                                                         ^
  4 errors generated.

  ```
  
  </details>

- Declare a variable with illegal name
  <details>
  <summary>Expand</summary>
  
  ```Cpp
  $ cat test.cpp
  #include<iostream>

  int main(){
    int var1 {43};
    double char {43.53};

    std::cout << "Hello, World!" << std::endl;
    std::cout << "var1=" << var1 << ", var2=" << char << std::endl;
    return 0;
  }
  
  $ g++ test.cpp
  test.cpp: In function ‘int main()’:
  test.cpp:5:3: error: expected primary-expression before ‘double’
      5 |   double char {43.53};
        |   ^~~~~~
  test.cpp:8:48: error: expected primary-expression before ‘char’
      8 |   std::cout << "var1=" << var1 << ", var2=" << char << std::endl;
        |                                                ^~~~
  
  $ clang++ test.cpp
  test.cpp:5:10: error: cannot combine with previous 'double' declaration specifier
    double char {43.53};
           ^
  test.cpp:5:15: error: expected unqualified-id
    double char {43.53};
                ^
  test.cpp:8:53: error: expected '(' for function-style cast or type construction
    std::cout << "var1=" << var1 << ", var2=" << char << std::endl;
                                                 ~~~~ ^
  3 errors generated.

  ```
  
  </details>

## `C++` equivalent of `uniq -c` command

- Relevant code is written in `uniq.c`. This code can be compiled by running `make` and can be executed with `./uniq` or `./uniq < repeated_lines.txt`.
- The program is written in a way that it matches with the output formatting of `uniq -c`. It also captures the empty lines and keep their counts as `uniq -c` does. See the following example:
  <details>
  <summary>Expand</summary>
  
  ```shell
  $ ./a.out < repeated_lines.txt
        3
        1 And I forget just why I taste
        1 Oh yeah, I guess it makes me smile
        1 I found it hard, it's hard to find
        1 Oh well, whatever, never mind
        2
        3 Hello, hello, hello, how low
        1 Hello, hello, hello
        1
        1 With the lights out, it's less dangerous
        1 Here we are now, entertain us
        1 I feel stupid and contagious
        1 Here we are now, entertain us
        1 A mulatto, an albino, a mosquito, my libido
        2 A denial, a denial, a denial, a denial
        2

  $ uniq -c repeated_lines.txt
        3
        1 And I forget just why I taste
        1 Oh yeah, I guess it makes me smile
        1 I found it hard, it's hard to find
        1 Oh well, whatever, never mind
        2
        3 Hello, hello, hello, how low
        1 Hello, hello, hello
        1
        1 With the lights out, it's less dangerous
        1 Here we are now, entertain us
        1 I feel stupid and contagious
        1 Here we are now, entertain us
        1 A mulatto, an albino, a mosquito, my libido
        2 A denial, a denial, a denial, a denial
        2
  ```
  
  </details>

- For the code I wrote,
  
  ```Cpp
  std::string line;
  for(; std::getline(std::cin,line);)
  ```

  is same as

  ```Cpp
  std::string line;
  while(std::getline(std::cin,line))
  ```

  In both cases, the loop starts with evaluating the condition, then executing the body, and then it repeats.

## Getters

`while(!(std::cin >> i))` repeatedly takes input from `stdin` until it encounters an object of type same as that of `i`. See `getters_int.cpp` and `getters_double.cpp`.

## Units of measure

The program accepts lengths in units inch, foot and yard, and converts them to mm, cm and m. See `unit_convertor.cpp`.
