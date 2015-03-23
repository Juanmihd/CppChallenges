// This is a solution to the problem 02 of the chapter 17 of the book CtCI
//
// Design an algorithm to figure out if someone has won a game of tic-tac-toe

// Let's consider that the tic-tac-toe problem is an NxN board where the player has to make N symbols on line
// I'm assuming that only two players can play (although it would be easy to expand to more players).
// I'm assuming that this function will be called once that player A has played, therefore, I only need to check
// if a given player has won

// I'm assuming that size_N is the size of the board and of the winning line
// I'm assuming that we know how many pieces the player has played (turn_N)

bool has_won(int n_player, const int** board, int size_N){
  //We check in the has table for size size_N if the winner is the same as the player we are checking)
  if (HashWinnerBoard[size_N].contains(board)){
    return (n_player == HashWinnerBoard[size_N][board]);
  }else{
    //If we haven't encountered that board, obtain it!
    //Check diagonal
    bool player_won = true;
    if(board[0][0] == n_player){
      for(unsigned int i = 1; player_won && i < size_N; ++i){
        player_won = board[i][i] == n_player;
      }
    }
    //Check diagonal inverse
    if(!player_won && board[0][size_N-1] == n_player){
      player_won = true;
      for(unsigned int i = 1; player_won && i < size_N; ++i){
        player_won = board[i][size_N-1-i] == n_player;
      }
    }
    //Check verticals
    for(unsigned int row = 0; !player_won && row < size_N; ++row){
      player_won = true;
      if(board[row][0] == n_player){
        for(unsigned int column = 0; player_won && column < size_N; ++column){
          player_won = board[row][column] == n_player;
        }
      }
    }
    //Check horizontals (this could be embebbed into check verticals!)
    for(unsigned int column = 0; !player_won && column < size_N; ++column ){
      player_won = true;
      if(board[0][column] == n_player){
        for(unsigned int row = 0; player_won && row < size_N; ++row){
          player_won = board[row][column] == n_player;
        }
      }
    }
    //If it's a win, add it to the Hash table!
    if(player_won) HashWinnerBoard[size_N][board] = n_player;
    return player_won;
  }
}