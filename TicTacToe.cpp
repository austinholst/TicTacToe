#include <iostream>
using namespace std;

/* Name: Austin Holst
 * Date: 09-28-17
 * Code: Plays TicTacToe
 */

bool checkWin(int player);
void printBoard();
void clearBoard();
bool checkTie();

int board[3][3];
int  BLANK = 0;
char  X_MOVE = 'X';
char  O_MOVE = 'O';

int x_turn = 0;
int o_turn = 1;
int turn = x_turn;
bool stillPlaying = true;
int x_wins = 0;
int o_wins = 0;

char yesno = 0;
int test = 0;

bool checkWin();

int main() {
  char input[3];
  while(stillPlaying == true) {
    while(checkWin(X_MOVE) == false && checkWin(O_MOVE) == false && checkTie() == false) {
      printBoard();
      cin >> input;
      int length = strlen(input);
      if(length > 2) {
	cout << "input a letter followed by a number" << endl;
      }
      else  if(input[0] != 'a' && input[0] != 'b' && input[0] != 'c') {
	cout << "row must be an a b or c" << endl;
      }
      else if(input[1] != '1' && input[1] != '2' && input[1] != '3') {
	cout << "column must be a 1 2 or 3" << endl;
      }
      else {
	int row = input[0] - 'a';
	int column = input[1] - '1';
	if(board[row][column] == BLANK) {
	  if(turn == x_turn) {
	    board[row][column] = X_MOVE;
	    test++;
	    turn = o_turn;
	  }
	  else {
	    board[row][column] = O_MOVE;
	    test++;
	    turn = x_turn;
	  }
	}
	else {
	  cout << "That spot has already been played!" << endl;
	}
      }
    }
    //If there is a tie
    if(checkTie() == true) {
      printBoard();
      cout << "It's a tie" << endl;
      clearBoard();
      cout << "X wins: " << x_wins << endl;
      cout << "O wins: " << o_wins << endl;
      cout << "Would you like to play again? Input 'y' or 'n'" << endl;
      cin >> yesno;
      if(yesno == 'y') {
	
      }
      else if(yesno == 'n') {
	cout << "You are no longer playing" << endl;
	stillPlaying = false;
      }
      else {
	cout << "You need to input y or n" << endl;
      }
    }
    //If X wins
    if(checkWin(X_MOVE) == true) {
      printBoard();
      cout << "X wins!" << endl;
      clearBoard();
      x_wins++;
      cout << "X wins: " << x_wins << endl;
      cout << "O wins: " << o_wins << endl;
      cout << "Would you like to play again? Input 'y' or 'n'" << endl;
      cin >> yesno;
      if(yesno == 'y') {
      
      }
      else if(yesno == 'n') {
	cout << "You are no longer playing" << endl;
	stillPlaying = false;
      }
      else {
	cout << "You need to input y or n" << endl;
      }
    }
    //If O wins
    else if(checkWin(O_MOVE) == true) {
      printBoard();
      cout << "O wins: " << o_wins << endl;
      clearBoard();
      o_wins++;
      cout << "X wins: " << x_wins << endl;
      cout << "O wins: " << o_wins << endl;
      cout << "Would you like to play again? Input 'y' or 'n'" << endl;
      cin >> yesno;
      if(yesno == 'y') {
       
      }
      else if(yesno == 'n') {
	cout << "You are no longer playing" << endl;
	stillPlaying = false;
      }
      else {
	cout << "You need to input y or n" << endl;
      }
    }
  }  
  return 0;
}

//Prints the board
void printBoard() {
  cout << "\t1\t2\t3" << endl;
  printf("a\t%c\t%c\t%c", board[0][0], board[0][1], board[0][2]);
  cout << endl;
  printf("b\t%c\t%c\t%c", board[1][0], board[1][1], board[1][2]);
  cout << endl;
  printf("c\t%c\t%c\t%c", board[2][0], board[2][1], board[2][2]);
  cout << endl;
}


//Check to see if someone won
bool checkWin(int player) {
  if(board[0][0] == player && board[0][1] == player && board[0][2] == player) {
    return true;
  }
  if(board[1][0] == player && board[1][1] == player && board[1][2] == player) {
    return true;
  }
  if(board[2][0] == player && board[2][1] == player && board[2][2] == player) {
    return true;
  }
  if(board[0][0] == player && board[1][0] == player && board[2][0] == player) {
    return true;
  }
  if(board[0][1] == player && board[1][1] == player && board[2][1] == player) {
    return true;
  }
  if(board[0][2] == player && board[1][2] == player && board[2][2] == player) {
    return true;
  }
  if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if(board[2][0] == player && board[1][1] == player && board[0][2] == player) {
    return true;
  }
  return false;
}

//Check to see if there is a tie
bool checkTie() {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(board[i][j] == BLANK) {
	return false;
      }
    }
  }
  return true;
  }

//Clear the board
void clearBoard() {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      board[i][j] = BLANK;
    }
  }
}
