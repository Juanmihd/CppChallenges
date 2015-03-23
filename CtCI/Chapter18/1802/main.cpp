// Solving problem 18.2
//
// 18.2 Write a method to shuffle a deck of cards. It must be a perfect shuffle -- in other words, each of the 52!
// permutations of the deck has to be equally likely. Assume that you are given a random number generator
// which is perfect.
//

class card{
  int number;
  int suit;
  public:
  card() : number(-1), suit (-1){}
  card(int n_number, int n_suit) : number(n_number), suit(n_suit){}
}

int random_between(int min, int max){
}

void swap_card(card A, card B){
}

void shuffle(array<cards>& deck){
  unsigned int size_deck = deck.size();
  for(unsigned int i=1; i<size_deck; ++i){
    unsigned int swap_pos = random_between(0,i);
    if(i!=swap_pos)
      swap_card(deck[i],deck[swap_pos]);
  }
}