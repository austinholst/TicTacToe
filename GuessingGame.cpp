#include <iostream>

using namespace std;

/*
 *Name: Austin Holst
 *Date: 09 - 13 - 17
 *Code: Number guessing game against the computer. Guess the number between
 *1-100 and it will tell you how many tries it took
 */

int main() {
 
  bool stillPlaying = true;
 
  while(stillPlaying == true) {
    
    //Random Number Gen
     srand(time(NULL));
    int randomNum = rand() % 100 + 1;
    //Initializing Guess Variable
    int userNum = 0;
    cout << "Guess my number" << endl;
    cin >> userNum;
    //Number of turns variable
    int turns = 0;

    //Comparing numbers
    while(userNum != randomNum) {
      //Too High
      if (userNum > randomNum) {
       cout << "your number was bigger than mine. Choose again." << endl;
       turns++;
       cin >> userNum;
     }
     //Too low
     else if(userNum < randomNum) {
       cout << "your number was less than mine. Choose again." << endl;
       turns++;
       cin >> userNum;
     }
     else {
       cout << "Please enter a number" << endl;
     }
    }

    //Guessed Correctly
    cout << "You guessed my number!" << endl;
    turns++;
    cout << "It took you " << turns << " tries!" << endl;

    //Play again stuff
    cout << "Would you like to play again?" << endl;
    char  yesno;
    cin >> yesno;
    if (yesno == 'y') {
      stillPlaying = true;
    }
    else if(yesno == 'n'){
      cout << "you are not longer playing" << endl;
      stillPlaying = false;
    }
    else {
      cout << "That was not an option" << endl;
    }
  }
}
