#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <stdio.h>


using namespace std;
//constant for array
const int MAX = 14;
//variable for player number
int playerNum;
// For the number of *'s
int star;
// array size
const int arraySize = 14;
//starting bin number
int startBin;
//beads from startBin
int startBeads;
//Function for lines across
void makeSolidLine(int star);
//Function for vertical lines
void makeDottedLine();
//Function to showBoard
void showBoard();
//Function for startingArray
void startingArray();
//Function for showTopBins
void showTopBins();
//Function for showBottomBins
void showBottomBins();
//Function for getStartingBin()
void getStartingBin();



//Loop for lines across
void makeSolidLine(int star) {
    for(int i = 0; i < star; i++) {
        cout << "*"; //prints as many stars needed (dependent on input)
    }
}

//Loop for vertical lines
void makeDottedLine() {
  cout << "*"; //starting point
    //Loop for number of stars
    for(int j = 0; j < 8; j++) {
            //nested loop for spacing 2*3 is 6 spaces
            for(int k = 0; k < 2; k++) {
                //Output display
                cout << "   ";
            }
    //Output Display
    cout << "*";
    }
}
//funtion for numbers in top bins
void showTopRowNumbers () {
  cout << "*    ";//first bin
  for (int t = 0; t < 6; t++) {
    cout << setw(3); // spacing for numbers
    cout << " *"; // star between numbers
    cout << setw(4); // spacing for numbers
    cout << t ;
  }
  cout<< "  *      *";//last bin
}
//function for numbers in bottom bins
void showBottomRowNumbers (){
  cout<< "*    "; //first bin
  for (int b = 12; b > 6; b--) {
    cout << setw(3); // spacing for numbers
    cout << " *"; // star between numbers
    cout << setw(4); // spacing for numbers
    cout << b;
  }
  cout<< "  *      *";//last bin
}

//Function for top bins
void showTopBins() {
  cout << "*    ";//first bin
  for (int t = 0; t < 6; t++) {
    cout << setw(3); // spacing for numbers
    cout << " *"; // star between numbers
    cout << setw(4); // spacing for numbers
    //All bins start with 4
    cout << 4 ;
  }
  cout<< "  *      *";//last bin
}

//Function for bottom bins
void showBottomBins() {
  cout << "*  0 ";//first bin
  for (int t = 0; t < 6; t++) {
    cout << setw(3); // spacing for numbers
    cout << " *"; // star between numbers
    cout << setw(4); // spacing for numbers
    //All bins start with 4
    cout << 4 ;
  }
  cout<< "  *   0  *";//last bin
}


//Function to display board
void showBoard () {
  makeSolidLine(57); //top line
  cout << endl;
  makeDottedLine(); //columns
  cout<< endl;
  makeDottedLine();//columns
  cout << endl;
  showTopRowNumbers(); // Number bin
  cout << endl;
  makeDottedLine(); //columns
  cout<< endl;
  showTopBins(); //number of beads on top
  cout << endl;
  makeDottedLine();//columns
  cout << endl;
  makeDottedLine(); //columns
  cout << endl;
  cout << "*"; //middle line first point
  cout << "  13  "; //spacing for larger bin
  makeSolidLine(43); // middle line
  cout << "   6  *"; //spacing for larger bin
  cout << endl;
  makeDottedLine(); //columns
  cout<< endl;
  makeDottedLine();//columns
  cout << endl;
  makeDottedLine(); //columns
  cout<< endl;
  showBottomRowNumbers(); // show bottom numbers
  cout << endl;
  makeDottedLine();//columns
  cout << endl;
  showBottomBins(); // number of beads in bottom
  cout << endl;
  makeDottedLine(); //columns
  cout << endl;
  makeDottedLine(); //columns
  cout << endl;
  makeSolidLine(57); // bottom line
}

//Function to print array
void printArray() {
  cout<< "Array is: ";
  //List for array for 14 characters
  for (int i=0; i < 14; i++) {
    //0 for larger bins numbers 13 and 6
    if (i == 6 || i == 13) {
      cout << setw(3); //spacing
      cout << 0; //prints 0
    }
    //For all other numbers display 4
    else {
      cout << setw(3); //spacing
      cout << 4; //prints 4
    }
  }
}

//Function to initialize array of beads
void startingArray(){
  //constant sequence
  const int startingArray[arraySize] = {4,4,4,4,4,4,0,4,4,4,4,4,4,0};
}

//Game over Function
int gameOverCheck(int beadArray[MAX]) {
  //vairables
  int winner = 0 ;// no winner yet
  int gameStatus = -1; //game not over
  int side1 = 0; //top side
  int side2= 0; //botom side

  //Loops to check that there are no beads in bins
  //top bins
  for (int i =0; i<6; i++) {
    side1 += beadArray[i];
  }
  //bottom bins
  for (int i =12; i >6; i--) {
    side2 += beadArray[i];
  }
  //Both sides are empty
  if (side1 == 0 || side2 == 0) {
    //check what side has the most beads (left or right)
    beadArray[6]=beadArray[6]+side1;
    beadArray[13]=beadArray[13]+side2;

    if(beadArray[6]>beadArray[13]) {
      winner = 1; // player 1 wins (collecting on right side)
    }
    else {
      winner = 2; // player 2 wins (collecting on the left side)
    }

  }
  else {
    winner = -1;// no winner yet
  }
  return winner;
}

//get starting bin function
int getStartingBin(beadArray, playerNum) {
  bool validStartingBin = false;

  while (validStartingBin == false) {
    std::cout << "Which bin do you want to start in?" << '\n';
    //get user input
    std::cin >> startBin;
    //accommodate for bead array starting from zero
    startBin--;
    //get number of beads in start bin
    startBeads = beadArray[startBin];

    //player one check
    if (((playerNum == 1) && (startBin > 5)) || ((playerNum == 2) && (startBin < 7)) || (startBin == 6) || (startBin == 13)) {
      //check if it is a player one middle bin
        std::cout << "Please choose a middle bin on your side of the board." << '\n';

    //make sure there are beads in the start bin chosen
    } else if (startBeads == 0) {
      std::cout << "Please choose a bin with beads in it." << '\n';
    } else {
      validStartingBin = true;
    }
  }
  return startBin;
}

//drop beads function
void dropBeads(playerNum) {
  //get number of beads in start bin
  startBeads = beadArray[startBin];
  //remove beads from starting bin to begin dropping beads
  beadArray[startBin] = 0;
  //while we have beads, start adding beads to the next bin
  while (startBeads > 0) {
    //iterate over bins
    for (int x = 0; x < beadArray.size(); x++) {
      //find the startBin that was chosen
      if (x == startBin) {
        //start adding beads to the bin after startBin
        x++;
          //player one check
          if ((playerNum == 1) && (x == 13)) {
            //do not add beads to player two bin
            // skip it and continue iterating from the beginning of player one bins
            x = 0;
            //add bead to bin
            beadArray[x] = beadArray[x] + 1;
            //keep track of beads leftover
            startBeads--;
          //player two check
          } else if ((playerNum == 2) && (x == 6)) {
            x = 7;
            //add bead to bin
            beadArray[x] = beadArray[x] + 1;
            //keep track of beads leftover
            startBeads--;
          }
          //add bead to bin
          beadArray[x] = beadArray[x] + 1;
          //keep track of beads leftover
          startBeads--;
      } else {
        //continue iterating until startBin is found
        continue;
      }
    }
  }
}

//main method
int main() {
  showBoard();
  cout << endl << endl;
  int beadArray [MAX] = {4,4,4,4,4,4,0,4,4,4,4,4,4,0};
  startingArray();
  printArray();
  return 0;
}
