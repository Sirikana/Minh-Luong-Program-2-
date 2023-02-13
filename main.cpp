/**------------------------------------------
    Program 2: Great 13

    Course: CS 141, Fall 2022.
    System: Linux x86_64 and G++
    Author: George Maratos and David Hayes
 ---------------------------------------------**/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <map>
#include <cstring>

/* Everything below this comment is starter code, and you are not
allowed to modify */

using namespace std;

// Function that displays the instructions to the user

void display_instructions()
{
    cout << "Class: CS 141" << endl
         << "Program 2: Great 13" << endl << endl
         << "Make a series of jumps until there is a single piece left" << endl
         << "anywhere on board. On each move you must jump an adjacent" << endl
         << "piece   into   an  empty  square,  jumping  horizontally," << endl
         << "vertically, or diagonally." << endl << endl
         << "Input of 'R' resets the board back to the beginning, and " << endl
         << "'X' exits the game." << endl;
}

// The internal representation of the board as an array. Do not modify directly.

char board[13]{};

/* These two functions are how you will get and set elements on the board. Only
use these two when changing, or reading the board. */

char get_element(char position)
{
    if ((position < 'A') || (position > 'M')) {
        cout << "Failed to get element at position " << position << endl
             << "Make sure the given position is an uppercase letter " << endl
             << "between A-M." << endl;
        exit(1);
    }
    return board[position - 'A'];
}

void set_element(char position, char value)
{
    if ((position < 'A') || (position > 'M')) {
        cout << "Failed to set element at postion " << position << endl
             << "Make sure the given position is an uppercase letter " << endl
             << "between A-M." << endl;
        exit(1);
    }
    board[position - 'A'] = value;
}

// print out the board with the legend on the right

void display_board()
{
    cout << endl;
    cout << setw(7) << "Board" << setw(12) << "Position" << endl;
    cout << setw(5) << board[0] << setw(11) << 'A' << endl
         << setw(3) << board[1] << ' ' << board[2] << ' ' << board[3]
         << setw(11) << "B C D" << endl
         << board[4] << ' ' << board[5] << ' ' << board[6] << ' '
         << board[7] << ' ' << board[8] << ' '
         << " E F G H I" << endl
         << setw(3) << board[9] << ' ' << board[10] << ' ' << board[11]
         << setw(11) << "J K L" << endl
         << setw(5) << board[12] << setw(11) << 'M' << endl;
    cout << endl;
}

/* This is the end of the starter code, and below is where you can
add your own code. Feel free to add helper functions or variables.
*/

/* forward declarations for the functions you will write later. This
is so the order of the function definitions, in this file,  does not
matter. */

void make_move(char& position1, char& jump, char& position2);
void initialize_board();
bool game_over(string position);
void line(string position);


int main()
{
    string position;
    int count = 0;
    display_instructions();
    initialize_board();
    display_board();
    cout << "Enter positions from, jump, and to (e.g. EFG): " << endl;
    cin >> position;
    for (int i = 0; i >= 0; i++){
      for (int i = 0; i < position.size(); i++){
        position.at(i) = toupper(position.at(i));
      }
      if (game_over(position) == true){
        make_move(position.at(0),position.at(1),position.at(2));
        count ++;
      } else{
        line(position);
      }
      cout << "Enter positions from, jump, and to (e.g. EFG): " << endl;
      cin >> position;
    }
    return 0;
}

void make_move(char& position1, char& jump, char& position2)
{
  char peg = get_element(position1);
  set_element(position1,get_element(position2));
  set_element(jump,'.');
  set_element(position2,peg);

  display_board();
}

bool game_over(string position)
{
    if (position != "X" && position != "R"){
      if (position.size() != 3){
        return false;
      }
      else if (position[0] < 'A' || position[0] > 'M' &&
               position[1] < 'A' || position[1] > 'M' &&
               position[2] < 'A' || position[2] > 'M'){
        return false;
      }
      else if (position != "ABE" && position != "EBA" &&
               position != "ADI" && position != "IDA" &&
               position != "EJM" && position != "MJE" &&
               position != "ILM" && position != "MLI" &&
               position != "ACG" && position != "GCA" &&
               position != "EFG" && position != "GFA" &&
               position != "IHG" && position != "GHI" &&
               position != "GKM" && position != "MKG" &&
               position != "BCD" && position != "DCB" &&
               position != "FGH" && position != "HGF" &&
               position != "JKL" && position != "LKJ" &&
               position != "BFJ" && position != "JFB" &&
               position != "CGK" && position != "KGC" &&
               position != "DHL" && position != "LHD" &&
               position != "BGL" && position != "LGB" &&
               position != "DGJ" && position != "JGD"){
        return false;
      }
      else if (board[position[0] - 'A'] == '.'){
        return false;
      }
      else if (board[position[1] - 'A'] == '.'){
        return false;
      }
      else if (board[position[2] - 'A'] != '.'){
        return false;
      }
      else{
        return true;
      }
    }
    
}

void initialize_board()
{
  for (int i = 0; i < 13; i++){
    board[i] = '#';
    board[6] = '.';
  }
}

void line(string position)
{
    if (position != "X" && position != "R"){
      if (position.size() != 3){
        cout << "*** Invalid sequence. Please retry." << endl;
      }
      else if (position[0] < 'A' || position[0] > 'M' &&
               position[1] < 'A' || position[1] > 'M' &&
               position[2] < 'A' || position[2] > 'M'){
        cout << "*** Given move has positions not on the board! Please retry." << endl;
      }
      else if (position != "ABE" && position != "EBA" &&
               position != "ADI" && position != "IDA" &&
               position != "EJM" && position != "MJE" &&
               position != "ILM" && position != "MLI" &&
               position != "ACG" && position != "GCA" &&
               position != "EFG" && position != "GFA" &&
               position != "IHG" && position != "GHI" &&
               position != "GKM" && position != "MKG" &&
               position != "BCD" && position != "DCB" &&
               position != "FGH" && position != "HGF" &&
               position != "JKL" && position != "LKJ" &&
               position != "BFJ" && position != "JFB" &&
               position != "CGK" && position != "KGC" &&
               position != "DHL" && position != "LHD" &&
               position != "BGL" && position != "LGB" &&
               position != "DGJ" && position != "JGD"){
        cout << "*** Move is invalid. Please retry." << endl;
      }
      else if (board[position[0] - 'A'] == '.'){
        cout << "*** Source needs a piece. Please retry." << endl;
      }
      else if (board[position[1] - 'A'] == '.'){
        cout << "*** Must jump a piece. Please retry." << endl;
      }
      else if (board[position[2] - 'A'] != '.'){
        cout << "*** Destination must be empty. Please retry." << endl;
      }
    }
    else{
      if (position == "X"){
        cout << "Exiting." << endl;
      }
      else if (position == "R"){
        cout << "Restarting game." << endl;
      }
      else{
        cout << "Congrats you win!" << endl;
      }
    }
}