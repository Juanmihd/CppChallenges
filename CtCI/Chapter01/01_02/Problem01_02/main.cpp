/// Juanmi Huertas
/// This is the solution to the problem 02 of the chapter 01 of CtCI
///
/// 1.2. Implement a function void reverse(char* str) in C or C++ which reverses a nullterminated string.
///
///

/// This function will swap the char pointerd by a pointer to char
void swap(char* A, char* B){
  /// Using three times the operation XOR, we manage to swap
  /// the content of both chars without creating an auxiliar char
  *A = *A ^ *B;
  *B = *A ^ *B;
  *A = *A ^ *B:
}

/// This function will reverse a nullterminated string
void reverse(char* str){
  //First we obtain the end of the string
  char* end_pointer = str;
  while (*end_pointer != '/0') ++end_pointer;

  char* start_pointer = str; 
  //Now we will go move both pointers (begining and end) swaping elements, until the pointers reach each other
  while (start_pointer < end_pointer){
    /// If they are the same character, they don't need to be swaped
    if(*start_pointer != *end_pointer)
      swap(start_pointer,end_pointer);
    ++start_pointer;
    --end_pointer;
  }
}

/// This funciont will compare if the strings aimed by A and B are equal)
bool isEqual(char* A, char* B){
  //Create pointers to run trhough the arrays
  char* A_pointer = A;
  char* B_pointer = B;
  //Here will be the result
  bool result_isEqual = true;
  while(*A_pointer != '/0' && *B_pointer != '/0' && result_isEqual){
    result_isEqual = *A_pointer == *B_pointer;
    ++A_pointer;
    ++B_pointer;
  }
  // To them to be equal, they have to have the same size
  // that will be checked if both of them are equal at the end of the
  // checking they are still equal, and both of them arrived to the end
  if(result_isEqual)
    result_isEqual = *A_pointer == *B_pointer;
  
  return resutl_isEqual
}

int main(int argc, char** argv){
  /// Creating some user tests
  
  //test 1
  char* test1 = "Panchito";
  char* test1_inverted = "otihcnaP";
  reverse(test1);
  if(isEqual(test1, test1_inverted))
    printf("Test 1 succeded\n");
  
  char* test2 = "";
  char* test2_inverted = "";
  reverse(test1);
  if(isEqual(test1, test1_inverted))
    printf("Test 1 succeded\n");
  
  char* test3 = "ABBA";
  char* test3_inverted = "ABBA";
    reverse(test1);
  if(isEqual(test1, test1_inverted))
    printf("Test 1 succeded\n");
  
}