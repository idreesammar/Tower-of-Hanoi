#pragma once

#include "disk.h"
#include "peg.h"
#include "gwindow.h"

#include <vector>

// Name:
//        promptForDisks
// Input:
//        None
// Output:
//        an int with the number of desired disks
// Side effects:
//        none
// Summary:
//        asks for and stores user input about number of disk for the tower (with error checking)
int promptForDisks();

// Name:
//        promptForPegs
// Input:
//        2 ints (by reference) used for start peg and end peg choice
// Output:
//        none
// Side effects:
//        outputs messages and takes input for two variables
// Summary:
//        asks for and stores user input for first and last peg choices (with error checking)
void promptForPegs(int& firstPegChoice, int& lastPegChoice);

// Name:
//        promptForPause
// Input:
//        none
// Output:
//        int with the pause length in milliseconds
// Side effects:
//        none
// Summary:
//        asks for and stores user input about pause interval (with error checking)
int promptForPause();

// Name:
//        promptForWindowSize
// Input:
//        2 ints (by reference) used for window screen width and height 
// Output:
//        none
// Side effects:
//        outputs messages and takes input for two variables
// Summary:
//        asks for and stores user input for screen width and height in pixels (with error checking)
void promptForWindowSize(int& inWidth, int& inHeight);

// Name:
//        draw
// Input:
//        1) GWindow to draw to (by reference)
//		  2) vector that holds all the peg objects
//		  3) int that holds the pause length
// Output:
//        none
// Side effects:
//        draws the towers to the screen
// Summary:
//        uses given peg vector to draw 3 towers with disk to a screen and pauses for a set time
void draw(GWindow& gw, std::vector<Peg>& pegVector, int pauseLength);

// Name:
//        moveDisk
// Input:
//        1) GWindow to draw to (by reference)
//		  2) vector that holds all the peg objects
//		  3) int that holds the index of the starting peg in the peg vector
//        4) int that holds the index of the destination peg in the peg vector
//		  5) int that holds the pause length
// Output:
//        none
// Side effects:
//        draws the new tower arrangement to the screen after removing the disk from one peg to another
// Summary:
//        uses given peg vector to take top disk off of starting vector and adding it to destination vector
void moveDisk(GWindow& gw, std::vector<Peg>& pegVect, int startPeg, int destPeg, int pauseLength);

// Name:
//        towerSolve
// Input:
//        1) GWindow to draw to (by reference)
//		  2) vector that holds all the peg objects
//		  3) int that holds the index of the starting peg in the peg vector
//        4) int that holds the index of the destination peg in the peg vector
//		  5) int that holds the number of disks to be moved 
//		  6) int that holds the pause length
// Output:
//        none
// Side effects:
//        draws the new tower arrangements for each step of the Tower of Hanoi experiment
// Summary:
//        uses given peg vector to take top disk off of starting vector and adding it to destination vector over multiple steps
void towerSolve(GWindow& gw, std::vector<Peg>& pegVect, int startPeg, int destPeg, int numDisks, int pauseLength);

// Name:
//        towerRun
// Input:
//        None
// Output:
//        an int (0 to indicate success)
// Side effects:
//        displays the various stages of the Tower of Hanoi challenge using the GWindow and calling the needed functions
// Summary:
//        calls all the necessary functions to run the Tower of Hanoi problems and display the various stages to a window
int towerRun();

const int MINSCREENWIDTH = 800;
const int MINSCREENHEIGHT = 600;
const int MAXSCREENWIDTH = 4096;
const int MAXSCREENHEIGHT = 2160;
const int MINDISKS = 2;
const int MAXDISKS = 10;
const int NUMPEGS = 3;
const int MAXPAUSELEN = 1000000;