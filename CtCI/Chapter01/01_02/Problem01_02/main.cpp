/// Juanmi Huertas
/// This is the solution to the problem 02 of the chapter 01 of CtCI
///
/// 1.2. Implement a function void reverse(char* str) in C or C++ which reverses a nullterminated string.
///
///

/// This function will reverse a nullterminated string
void reverse(char* str){
  //First we obtain the end of the string
  char* end_pointer = str;
  while (*end_pointer != '/0') ++end_pointer;

  char* start_pointer = str;
  //Now we will go move both pointers (begining and end) swaping elements, until the pointers reach each other
  while (start_pointer <= end_pointer){

  }
}

int main(int argc, char** argv){


}