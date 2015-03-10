//
// Puzzle #1: crack the secret code.
//

#include <iostream>
#pragma warning(disable : 4996)

void encode_decode(char *dest, const char *message, const char *key) {
  const char *kp = key;
  while (*message) {
    if (*kp == 0) kp = key;
    *dest++ = *message++ ^ (*kp++ - '0');
  }
  *dest = 0;
}

void search_coded_word(char* key, const char* message){
  while (*message){
    if (*(message) >= '`' && *(message) <= 'o'
      && *(message + 1) >= '`' && *(message + 1) <= 'o'
      && *(message + 2) >= 'p' && *(message + 2) <= '~'
      && *(message + 3) >= '`' && *(message + 3) <= 'o'
      && *(message + 4) >= 'p' && *(message + 4) <= '~'
      && *(message + 5) >= 'p' && *(message + 5) <= '~'
      && *(message + 6) >= ' ' && *(message + 6) <= '/'){
      //I've found secret!!!  
      printf("%.6s \n", message);
      key[0] = (*message ^ ' ') + '0';
      key[1] = (*(message + 1) ^ 's') + '0';
      key[2] = (*(message + 2) ^ 'e') + '0';
      key[3] = (*(message + 3) ^ 'c') + '0';
      key[4] = (*(message + 4) ^ 'r') + '0';
      key[5] = (*(message + 5) ^ 'e') + '0';
      key[6] = (*(message + 6) ^ 't') + '0';
      key[7] = (*(message + 7) ^ ' ') + '0';
      key[8] = 0;
      for (int i = 0; i < 6; ++i)
        printf("%x %x\n", key[i], key[i] - '0');
      printf("\n%.6s\n", key);
    }
    ++message;
  }
}

//"                             This is a secret message. You can crack it by brute-force methods.",
const char example_message[] = "Ujjw%ot(h!qfgwcs(ddqpebc)(Pnw#gdh'k{`ah$lr'jp!`qqqc*nfsaf$hcs`feq-";
int example_key = 314159;

// this message also contains the word "secret".
// You can crack the code by trying all the numbers, but a smart cryptologist will get there
// much faster.
const char actual_message[] = "Wimr%dguvbfa!deqi%`njud`lu%wia!rfpb%pdgs`},&Dp!pilz\"ov#`$spk`ovk!gnal.&lw!mr%lcu|#uk!c`lb%wia!nl{(";

// Modify the code below to crack the actual message. How fast can you do it in terms of clock cycles?
// Run in Release mode for better results. Look at the disassembly to get clues about how to optimise it.

// There are two winners. The first finds the solution by any means. The second is the person
// who finds the solution in the fewest cycles in a way that will crack all such codes.

// A naive solution would be something like, loop over all integers, decode the string, search for "secret".
// filter out all the strings that look wrong.

// A smart solution will use the Ascii table to narrow the search down massively!

int main() {
  long long start = __rdtsc();

  const char * test[] = { "1", "2", "3", "4", "5" };
  char tmp[256];

  char key[9];
  search_coded_word(key, actual_message);
  encode_decode(tmp, actual_message, key);
  //search_coded_word(key, actual_message);

  long long end = __rdtsc();

  std::cout << tmp << "\n";
  std::cout << end - start << " clocks\n";



}
