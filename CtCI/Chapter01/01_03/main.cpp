/// This is my attemp to solve problem 3 from chapter 1 in Cracking the Coding Interview
//
// 1.3 Given two strings, write a method to decide if one is a permutation of the other 
// Understanding permutation as: (a,b,c)  =>  (b, c, a)   !

#include <iostream>

bool IsPermutation(const string& A, const string& B){
  //The sizes has to be equal
  if(A.size() != B.size()) return false;
  unsigned int size = A.size();
  
  //Run through all the elements of B
  bool permutaiton = false;
  for(int pos_B =  0; !permutation && pos_B < size; ++pos_B){
    permutation = true;
    for(int pos_A = 0; permutation && pos_A < size; ++pos_A){
      permutation = (A.data()[pos_A] == B.data()[(pos_B+pos_A)%size]);
    }
  }
  return permutation;
}

int main(int argc, char** argv){
  //test 1
  string test1_A = "Manolo";
  string test1_B = "loMano";
  if(isPermutation(test1_A, test1_B))
    printf("Test 1 correct! Detecting permutated strings!\n");
  else
    printf("Test 1 ERROR! Detecting permutated strings!\n");
  
  //test 2
  string test2_A = "Manolo";
  string test2_B = "Manolo";
  if(isPermutation(test2_A, test2_B))
    printf("Test 2 correct! Detecting equal strings!\n");
  else
    printf("Test 2 ERROR! Detecting equal strings!\n");
  
  //test 3
  string test3_A = "Manolo";
  string test3_B = "laMano";
  if(!isPermutation(test3_A, test3_B))
    printf("Test 3 correct! Detecting last symbol bad strings!\n");
  else
    printf("Test 3 ERROR! Detecting last symbol bad  strings!\n");
  
  //test 4
  string test4_A = "Manolo";
  string test4_A = "Manol";
  if(!isPermutation(test4_A, test4_A))
    printf("Test 4 correct! Detecting different sizes strings!\n");
  else
    printf("Test 4 ERROR! Detecting different sizes  strings!\n");
}