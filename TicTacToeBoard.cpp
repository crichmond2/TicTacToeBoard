#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  gameOver = false;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X)
    turn = O;
  else
    turn = X;
  return turn;
  //return Invalid;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if(row > BOARDSIZE || column > BOARDSIZE)
    return Invalid;
  
  if(board[row][column] == Blank && gameOver == false){
    board[row][column] = turn;
  
  int point = 0;
  if(turn == X)
    point = 1;
  else
    point = -1;
  playerScore[row] += point;
  playerScore[BOARDSIZE+column] += point;
  if(row == column)
    playerScore[2*BOARDSIZE] += point;
  if(BOARDSIZE - 1 - column == row)
  playerScore[2*BOARDSIZE+1] += point;
    toggleTurn();
    return board[row][column];
    
  }
  
  else
    return board[row][column];

  
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row <= BOARDSIZE && row >= 0){
    if(column <= BOARDSIZE && column >= 0){
      return board[row][column];
    }
    else return Invalid;
  }
  else return Invalid;
  //return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  for(int i = 0; i < 2*BOARDSIZE+2; i++){
    if(playerScore[i] == BOARDSIZE){
      gameOver = true;
      return X;
      
      
    }
    else if(playerScore[i] == BOARDSIZE*-1){
      gameOver = true;
      return O;
      
    }
  }
  for(int i = 0; i < BOARDSIZE; i++){
    for(int j = 0; j < BOARDSIZE; j++){
      if(board[i][j] == Blank)
        return Invalid;
    }
    
  }
  return Invalid;
}
