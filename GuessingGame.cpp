#include <iostream>

using namespace std;

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
      //Too big
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
