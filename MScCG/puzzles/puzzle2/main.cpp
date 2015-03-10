////////////////////////////////////////////////////////////////////////////////
//
// (C) Andy Thomason 2015
//
// Puzzle #2: Bulls and Cows
//

//
// In the game Bulls and Cows, you must guess a four digit number.
//
// On every guess, the other player marks you with a "bull" for each
// number that is correct in the correct place and a "cow" for each number
// that is correct but in the wrong place.
//
// For example, if the hidden number is 1234 then:
//
// 1234 scores 4 bulls - a win.
// 5678 scores nothing
// 1243 scores 2 bulls and two cows.
// 8123 scores 3 cows
//
// if the number is 2222
// 1234 scores 1 bull
//
// if the number is 1234
// 8822 scores 1 cow

#include <utility>
#include <iostream>
#include <cassert>
#include <bitset>

//
// this is an example scoring function with several bits missing.
//
std::pair<int, int> score(int guess, int answer) {
  // here is an expression that gets the digits of the answer.
  // it is missing the upper two digits, can you complete it?
  int ad[] = { answer / 1000 % 10, answer / 100 % 10, answer / 10 % 10, answer % 10 };
  int gd[] = { guess / 1000 % 10, guess / 100 % 10, guess / 10 % 10, guess % 10 };

  int bulls = 0, cows = 0;
  for (int i = 0; i != 4; ++i) {
    if (gd[i] == ad[i]) {
      ++bulls;
      ad[i] = -1;
      gd[i] = -2;
    }
  }

  for (int i = 0; i != 4; ++i) {
    bool found = false;
    if (gd[i] != -2)
      for (int j = 0; j != 4 && !found; ++j){
        if (i!=j)
          if (gd[i] == ad[j]) {
            ++cows;
            found = true;
            ad[j] = -1;
            gd[i] = -2;
          }
      }
  }
  return std::make_pair(bulls, cows);
}

// here is an example game with one move to make.
// can you tell what is the answer just from these scores?
static const int game[][3] = {
  {1234, 1, 1},
  {5678, 0, 1},
  {9012, 0, 2},
  {5566, 0, 0},
  {7788, 1, 0},
  {1180, 1, 1},
  {2281, 1, 1},
  {1849, 1, 0},
};



int main() {
  // test the scoring function
  // this will fail... you must fix it by fixing the scoring function.
  long long start = __rdtsc();
  (score(1234, 1234) == std::make_pair(4, 0));
  (score(5678, 1234) == std::make_pair(0, 0));
  (score(1243, 1234) == std::make_pair(2, 2));
  (score(8123, 1234) == std::make_pair(0, 3));
  (score(1234, 2222) == std::make_pair(1, 0));
  (score(8822, 1234) == std::make_pair(0, 1));
  long long end = __rdtsc();
  printf("total clocks: %lld\n", end - start);

  start = __rdtsc();
  // write a loop here that completes the example game
  //Let's try all the numbers!
  bool found = false;
  int testing = 0;
  for (testing = 0; testing != 10000 && !found; ++testing){
    //Now let's test this number with what we now from the game!
    bool error = false;
    for (int i = 0; i != 8 && !error; ++i){
      error = score(game[i][0], testing) != std::make_pair(game[i][1], game[i][2]);
    }
    found = !error;
  }
  --testing;
  printf("I found this number: %i\n", testing);
  end = __rdtsc();
  printf("total clocks: %lld\n", end - start);

  std::bitset<9> test[4]; //9 digits for the 4 positions
  for (int iset = 0; iset != 4; ++iset)
    test[iset].set(); // Setting all bits to 1 (every number is possible)

  //Let's filter the set by the information we now!!
  int answer = -1;
  for (int i = 0; i != 8; ++i){
    //Get the digits fot the current guess (later on this should be random from the set of solutions!)
    int gd[] = { game[i][0] / 1000 % 10, game[i][0] / 100 % 10, game[i][0] / 10 % 10, game[i][0] % 10 };
    //We know that none of the digits are there!
    int sum_bulls_cows = game[i][1] + game[i][2];
    //Check the sum of the bulls and cows!
    if (sum_bulls_cows == 4){
      if (game[i][2] == 0){ //if cows are 0, bulls are 4
        //RIGHT ANSWER!!
        answer = gd[0] * 1000 + gd[1] * 100 + gd[2] * 10 + gd[3];
      }
      else{
        //Create a mask with 1 on those numbers
        std::bitset<9> mask;
        mask.set();
        mask = ~mask;
        for (int j = 0; j != 4; ++j)
          mask.set(gd[j], 1);
        //Apply that mask to each one of the for numbers so we keep only those in the mask!
        for (int iset = 0; iset != 4; ++i){
          test[iset] &= mask;
        }
        if (game[i][1] == 0){ //If bulls are 0, cows are 4!
          for (int iset = 0; iset != 4; ++i){
            test[iset].set(gd[iset], 0);
          }
        }
      }
    }
    if (game[i][1] == 0 && game[i][2] == 0){ //If both are zero, none number is there!
      //Create a mask with 1 on those numbers
      std::bitset<9> mask;
      mask.set();
      for (int j = 0; j != 4; ++j)
        mask.set(gd[j], 0);
      //Apply that mask to each one of the for numbers so we keep only those in the mask!
      for (int iset = 0; iset < 4; ++iset){
        test[iset] &= mask;
      }
    }
    else if (game[i][1] == 0){ //if the bulls are zero, none number is in it's place!
      for (int j = 0; j != 4; ++j){
          test[j].set(gd[j], 0);
      }
    }
  }

  //After filter, obtain numbers from that set!
  //FINISH THIS!!!!!
  
}
