/// Juanmi Huertas
/// This is the solution one to the problem 1.1 of Cracking the Coding Interview
///
///
/// 1.1 Implement an algorithm to determine if a string has all unique characters. 
/// What if you cannot use additional data structures ?
///

#ifndef _SOLUTION0101_CtCI0101_H_
#define _SOLUTION0101_CtCI0101_H_

#include <bitset>

//------------------------------ SOLUTION 1 ------------------------------
// This solution will be with an auxiliar data structure

bool unique_character_data(char* string, int size_string){
  //Initialize a structure with as many characters as it may be, initialize to 1 (possible to be)
  std::bitset<256> characters;
  characters.set();
  //Go through all the values, checking if the character has already appeared
  // if it hasn't appeared yet, turn it to 0
  bool repeated_character = false;
  for (int i = 0; !repeated_character && i != size_string; ++i){
    if (characters[string[i]] == 0) //If the character has already been found, return false
      repeated_character = true;
    else //If not, select as character found!
      characters[string[i]].flip();
  }
  //return if the characters have been repeated or if they where unique
  return !repeated_character;
}


//------------------------------ SOLUTION 2 ------------------------------
// This solution will be without an auxiliar data structure
// but I am assuming that I can modify the char array

bool unique_character(char* string_to_check, int size_string){
  //Order the string
  //We create a function to compare the elements and we use std::qsort to apply this function to order the array
  auto compare = [](const void* A, const void* B) -> int {return (*(char*)A < *(char*)B)?-1:1; };
  std::qsort(string_to_check, 6, sizeof(char), compare); ///Problem with this line. Work on this.
  //Check if there are to consecutive characters
  bool repeated_character = false;

  return !repeated_character;
}

#endif
