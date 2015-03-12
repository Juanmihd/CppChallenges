/// Juanmi Huertas
/// This is a solution to the problem 1.1 of Cracking the Coding Interview
///
///1.1 Implement an algorithm to determine if a string has all unique characters. 
/// What if you cannot use additional data structures ?
///
/// I will offer two different solutions, one with an aditional data structure
/// and other one without the data structure. 
///
/// The solution is selected when the application is run

#include <utility>
#include <iostream>
#include <cassert>
#include "solution0101.h"

int main(int argc, char** argv){
  //We will try the different solutions, to see which one is more efficient

  char* string_to_check;
  string_to_check = new char[10];
  string_to_check = "Manoli\0";
  int size_string_to_check = 6;
  //Solution 1 with aditional data structure
  long long start1 = __rdtsc();
  if (unique_character_data(string_to_check, size_string_to_check))
    printf("No repeated characters!\n");
  else
    printf("Some repeated character!\n");
  long long end1 = __rdtsc();
  //Solution 2 without aditional data structure
  /*
  long long start2 = __rdtsc();
  if (unique_character(string_to_check, size_string_to_check))
    printf("No repeated characters!\n");
  else
    printf("Some repeated character!\n");
  long long end2 = __rdtsc();
  */
  //Printing out times of the solutions
  printf("Solution 1 finished in %lld cycles and solution 2 finished in %lld cycles.", end1-start1, end1-start1);

  system("pause");
}