#include "peg.h"

// default constructor
Peg::Peg()
{
	// set initial values for member variables
	mX = 0;
	mY = 0;
	mH = 0;
	mW = 0;
	xCenter = mX;
	curTop = 0;
	color = "BLACK";
	// diskVect already initialized
}

// parameterized constructor
Peg::Peg(int inX, int inY, int inW, int inH)
{
	// set member variables with input values
	mX = inX;
	xCenter = mX; // same value
	mY = inY;
	mW = inW;
	mH = inH;
	// also set other variables
	curTop = 0;
	color = "BLACK";
	// diskVect already initialized
}

// function to draw peg and corresponding disks on it
void Peg::draw(GWindow& gw)
{
	// calculate top left coordinates of peg
	int topLeftX = mX - (mW / 2);
	int topLeftY = mY - mH;

	// now draw the peg
	gw.setColor(color); // set the color
	gw.fillRect(topLeftX, topLeftY, mW, mH);

	// use loop to draw each disk from diskVector onto the peg
	for (Disk d: diskVect)
	{
		d.draw(gw); // draw each disk
	}
}

// function to add disk to peg's diskVector
void Peg::addDisk(Disk inDisk)
{
	// first set the x coordinate of upcoming disk
	inDisk.setX(xCenter); // will be same for all disks (all centered at peg center, just y coord change)

	// now set the y coordinate appropriately
	if (diskVect.empty())  // means incoming disk will be first disk on this peg (at index 0)
	{
		inDisk.setY(mY); // same as peg's bottom center Y coordinate
		curTop = mY - inDisk.getHeight(); // update current height
	}
	else // for all other disks on top of base disk (not index 0)
	{
		inDisk.setY(curTop); // the new bottom center y coordinate is the top center y coordinate of previous disk
		curTop -= inDisk.getHeight(); // update current height
	}

	// now, add the inputted disk to the end of the vector (with its approprite x,y coordinates)
	diskVect.push_back(inDisk); 
}

// function to remove disk from peg's diskVector
Disk Peg::removeDisk()
{
	Disk lastDisk = diskVect[diskVect.size() - 1]; // obtain the last disk from the vector

	// change the curValue to reflect the loss of the top disk which is about to be removed
	curTop += lastDisk.getHeight();

	diskVect.pop_back(); // now remove the last disk

	// lastly, return the former last element, now stored in lastDisk
	return lastDisk;
}