#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

//Function for lines across
void makeSolidLine(int star);
//Function for vertical lines
void makeDottedLine();
//Function to showBoard
void showBoard();

int star; // For the number of *'s

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
    cout << "*" // star between numbers
    cout << setw(3); // spacing for numbers
    cout << t ;
  }
  cout<< "         *";//last bin
}
//function for numbers in bottom bins
void showBottomRowNumbers (){
  cout<< "*    "; //first bin
  for (int b = 12; b > 6; b--) {
    cout << setw(7); //spacing for numbers
    cout << b;
  }
  cout << "         *";//last bin
}

//Function to display board
void showBoard () {
  makeSolidLine(57); //top line
  cout << endl;
  makeDottedLine(); //columns
  cout<< endl;
  makeDottedLine();//columns
  cout << endl;
  showTopRowNumbers();
  cout << endl;
  makeDottedLine(); //columns
  cout<< endl;
  makeDottedLine();//columns
  cout << endl;
  makeDottedLine(); //columns
  cout << endl;
  cout << "*"; //middle line first point
  cout << "  13  "; //spacing for larger bin
  makeSolidLine(42); // middle line
  cout << "   6   *"; //spacing for larger bin
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
  makeDottedLine(); //columns
  cout << endl;
  makeDottedLine(); //columns
  cout << endl;
  makeSolidLine(57); // bottom line
}

//Function to print array
void printArray() {
  cout<< "Array is: ";
  for (int i=0; i < 14; i++) {
    if (i == 6 || i == 13) {
      cout << setw(3);
      cout << 0;
    }
    else {
      cout << setw(3);
      cout << 4;
    }
  }
}

//main method
int main() {
  showBoard();
  cout << endl << endl;
  const int startingArray[14] = {4,4,4,4,4,4,0,4,4,4,4,4,4,0};
  printArray();
  return 0;
}
