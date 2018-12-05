/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest,Turns){
	TicTacToeBoard object;
	Piece result = object.toggleTurn();
	ASSERT_EQ(result,O);
}

TEST(TicTacToeBoard,sevenToggles){
	TicTacToeBoard object;
	object.toggleTurn();
	object.toggleTurn();
	object.toggleTurn();
	object.toggleTurn();
	object.toggleTurn();
	object.toggleTurn();
	object.toggleTurn();
	Piece result = object.toggleTurn();
	ASSERT_EQ(result,X);
}
TEST(TicTacToeBoard,placePieceOpen){
	TicTacToeBoard object;
	Piece result = object.placePiece(1,1);
	ASSERT_EQ(result,X);
}
TEST(TicTacToeBoard,InvalidMove){
	TicTacToeBoard object;
	object.placePiece(1,1);
	Piece result = object.placePiece(1,1);
	ASSERT_EQ(result,X);
}
TEST(TicTacToeBoard,OutOfBounds){
	TicTacToeBoard object;
	Piece result = object.placePiece(200,200);
	ASSERT_EQ(result,Invalid);
}
TEST(TicTacToeBoard,TwoPlaces){
	TicTacToeBoard object;
	object.placePiece(1,1);
	Piece result = object.placePiece(2,2);
	ASSERT_EQ(result,O);
}

TEST(TicTacToeBoard,getPiece){
	TicTacToeBoard object;
	object.placePiece(1,1);
	Piece result = object.getPiece(1,1);
	ASSERT_EQ(result,X);
}
TEST(TicTacToeBoard,InvalidCol){
	TicTacToeBoard object;
	ASSERT_EQ(object.getPiece(1,200),Invalid);
}
TEST(TicTacToeBoard,InvalidRow){
	TicTacToeBoard object;
	ASSERT_EQ(object.getPiece(200,1),Invalid);
}
TEST(TicTacToeBoard,NoWinner){
	TicTacToeBoard object;
	for(int i = 0; i < BOARDSIZE; i++){
		for(int j = 0; j <BOARDSIZE; j++){
			object.placePiece(i,j);
			//object.toggleTurn();
		}
	}
	ASSERT_EQ(object.getWinner(),Invalid);
}
TEST(TicTacToeBoard, NoWinnerBlanks){
	TicTacToeBoard object;
	object.placePiece(2,2);
	ASSERT_EQ(object.getWinner(),Invalid);
}