#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <stdio.h>


using namespace std;
//constant for array
const int MAX = 14;
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

int star; // For the number of *'s
const int arraySize = 14; // array size

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

//main method
int main() {
  showBoard();
  cout << endl << endl;
  int beadArray [MAX] = {4,4,4,4,4,4,0,4,4,4,4,4,4,0};
  startingArray();
  printArray();
  return 0;
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
