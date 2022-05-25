#include "towers.h"

// function to ask for number of disks
int promptForDisks()
{
	int numDisks; // holds the number of disks 

	// ask for user input (between 2 and 10 inclusive)
	std::cout << "Enter the number of disks to use (between 2 and 10 inclusive): ";
	std::cin >> numDisks;

	// loop to make sure response is in valid range
	while (!((numDisks >= MINDISKS) && (numDisks <= MAXDISKS)))
	{
		std::cout << "Error, invalid choice. Please enter in valid range (2 to 10 inclusive): "; // error message
		std::cin >> numDisks; // take input again
	}

	// once input in valid range, return the number of disks
	return numDisks;
}

// function to ask for number of pegs 
void promptForPegs(int& firstPegChoice, int& lastPegChoice)
{
	// obtain user input of which peg to start on
	std::cout << "Enter which peg to start on (between 1 to 3 inclusive): ";
	std::cin >> firstPegChoice;
	
	// loop to make sure the first peg choice is in valid range
	while (!((firstPegChoice >= 1) && (firstPegChoice <= NUMPEGS)))
	{
		std::cout << "Error, invalid choice. Please enter in valid range (1 to 3 inclusive): "; // error message
		std::cin >> firstPegChoice; // take input again
	}
	

	// obtain input for peg to end on
	std::cout << "Enter which peg to end on (between 1 to 3 inclusive): ";
	std::cin >> lastPegChoice;

	// loop to make sure end peg is in valid range (+ is not the same as first peg choice)
	while (!((lastPegChoice >= 1) && (lastPegChoice <= NUMPEGS) && (firstPegChoice != lastPegChoice)))
	{
		std::cout << "Please enter in valid range (1 to 3 inclusive) and make sure it differs from start peg: "; // error message
		std::cin >> lastPegChoice; // take input again
	}

	// make appropriate adjustment for vector indexing
	firstPegChoice -= 1; 
	lastPegChoice -= 1; 
}

// function to ask for pause size
int promptForPause()
{
	int pauseLength; // holds the pause length (in milliseconds)

	// ask for user input (between 1 and 1000000 inclusive)
	std::cout << "Enter the pause interval (between 1 and 1000000 inclusive): ";
	std::cin >> pauseLength;

	// loop to make sure response is in valid range
	while (!((pauseLength >= 1) && (pauseLength <= MAXPAUSELEN)))
	{
		std::cout << "Error, invalid choice. Please enter in valid range (1 to 1000000 inclusive): "; // error message
		std::cin >> pauseLength; // take input again
	}

	// once input in valid range, return the pause length
	return pauseLength;
}

// function to ask for window size
void promptForWindowSize(int& inWidth, int& inHeight)
{
	// obtain user input for window width
	std::cout << "Enter the screen width (between 800 to 4096 inclusive): ";
	std::cin >> inWidth;

	// loop to make sure the first peg choice is in valid range
	while (!((inWidth >= MINSCREENWIDTH) && (inWidth <= MAXSCREENWIDTH)))
	{
		std::cout << "Error, invalid choice. Please enter in valid range (800 to 4096 inclusive): "; // error message
		std::cin >> inWidth; // take input again
	}

	// obtain user input for window height
	std::cout << "Enter the screen height (between 600 to 2160 inclusive): ";
	std::cin >> inHeight;

	// loop to make sure the first peg choice is in valid range
	while (!((inHeight >= MINSCREENHEIGHT) && (inHeight <= MAXSCREENHEIGHT)))
	{
		std::cout << "Error, invalid choice. Please enter in valid range (600 to 2160 inclusive): "; // error message
		std::cin >> inHeight; // take input again
	}
}

// function to draw the towers (all pegs with their disks)
void draw(GWindow& gw, std::vector<Peg>& pegVector, int pauseLength)
{
	gw.clear(); // first clear the current window

	// draw the three pegs by looping through pegVector
	for (Peg p : pegVector)
	{
		p.draw(gw); // draw each tower (peg with disks)
	}

	// pause the drawing with the given pause length
	pause(pauseLength);
}

// function to move disk from one peg to another
void moveDisk(GWindow& gw, std::vector<Peg>& pegVect, int startPeg, int destPeg, int pauseLength)
{
	// first remove the top disk from the starting Peg
	Disk movedDisk = pegVect[startPeg].removeDisk();
	
	// now add this disk to the destination peg
	pegVect[destPeg].addDisk(movedDisk);

	// now draw the new setup
	draw(gw, pegVect, pauseLength);
}

// function that uses recursion to solve the Tower of Hanoi challenge
void towerSolve(GWindow& gw, std::vector<Peg>& pegVect, int startPeg, int destPeg, int numDisks, int pauseLength)
{
	int tempPeg; // will hold the index of the temporary peg at each step of the solver

	// first label the temp peg (NOTE: the input has been modified for appropriate indexing (e.g. peg 1 is actually numbered 0)
	for (int i = 0; i < pegVect.size(); i++)
	{
		if (!((i == startPeg) || (i == destPeg))) // if peg is not the start or end, it will become the temp
		{
			tempPeg = i;
		}
	}

	// the recursive framework
	if (numDisks == 0)  // meaning no disks left to remove
	{
		return; // base case, just return
	}
	else
	{
		towerSolve(gw, pegVect, startPeg, tempPeg, numDisks - 1, pauseLength); // recursive transfer n-1 disks to temp 
		moveDisk(gw, pegVect, startPeg, destPeg, pauseLength); // actually moving the disk from start to end
		towerSolve(gw, pegVect, tempPeg, destPeg, numDisks-1, pauseLength);  // recursive transfer disks from temp to end locaton
	}
}



// function to run program
int towerRun()
{
	// prompt for window size
	int windowWidth;
	int windowHeight;
	promptForWindowSize(windowWidth, windowHeight);

	// make a peg vector with 3 peg objects (note they each have disk vector)																
	std::vector<Peg> pegVector(3); 
	// the (x,y) is scaled to fit the window size given (for testing purposes, I was only able to see up to my screen's max height -- see note below)
	// note: about 1400 for my screen's max width, between 700-800 for my max height (this was the size I could see till on my laptop screen)
	pegVector[0] = Peg(windowWidth / 4, windowHeight - 10, 10, windowHeight - 10);
	pegVector[1] = Peg(windowWidth / 2, windowHeight - 10, 10, windowHeight - 10);
	pegVector[2] = Peg(windowWidth * (3.0 / 4.0), windowHeight - 10, 10, windowHeight - 10);

	// prompt for number of disks
	int numDisks;
	numDisks = promptForDisks();

	// create desired # disks       
	std::vector<Disk> diskVector; // will hold the disks to eventually be added to pegs
	int diskWidth = windowWidth / 5; // for starting disk
	int widthSubtractor = diskWidth / 15; // how much width is taken away from the next smaller disk
	int diskHeight = (windowHeight - 10) / 10; // same height for all disk
	// use loop to add appropriate number of disks
	for (int i = 0; i < numDisks; i++)
	{
		// NOTE: x,y coordinates not too important for this step b/c they will be reset to peg's location when added later with addDisk
		Disk disk = Disk(0, 0, diskWidth, diskHeight);
		diskVector.push_back(disk); // add each disk to the disk Vector 
		diskWidth -= widthSubtractor; // to make sure each subsequent disk added is smaller in width
	}

	// prompt pegs choice (note the function takes account of adjustments needed for vector indexing)
	int startPeg;
	int endPeg;
	promptForPegs(startPeg, endPeg);
	
	// add number of disks to the starting peg choice
	for (Disk d : diskVector)
	{
		pegVector[startPeg].addDisk(d);
	}

	// prompt for pause length
	int pauseLength;
	pauseLength = promptForPause();

	// run draw function from towers
	GWindow gw(windowWidth, windowHeight); // create the window of desired size
	draw(gw, pegVector, pauseLength); // the initial set up of the Tower of Hanoi challenge

	// solve the Tower of Hanoi challenge
	towerSolve(gw, pegVector, startPeg, endPeg, diskVector.size(), pauseLength);

	return 0; // return the int for completion
}