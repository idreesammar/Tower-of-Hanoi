#include "disk.h"

// default constructor
Disk::Disk()
{
	// set member variables to initialized value
	mX = 0;
	mY = 0;
	mH = 0;
	mW = 0;
	mColor = getRandColor(); // use the random color function I made below
}

// parameterized constructor
Disk::Disk(int inX, int inY, int inW, int inH)
{
	// set member variables to values from the input 
	mX = inX;
	mY = inY;
	mW = inW;
	mH = inH;
	mColor = getRandColor(); // use the random color function I made below
}

// setter functions of x and y coordinates
void Disk::setX(int inX)
{
	mX = inX; // set the x coordinate with input value
}

void Disk::setY(int inY)
{
	mY = inY; // set the y coordinate with input value
}

// getter for the height
int Disk::getHeight()
{
	return mH; // return the height member variable
}

// function to draw the disk
void Disk::draw(GWindow& gw)
{
	// calculate top left coordinates
	int topLeftX = mX - (mW / 2);
	int topLeftY = mY - mH;
	
	// need to use gw.drawRect(x,y,width,height) where (x,y) are TOP LEFT of rectangle
	gw.setColor(mColor); // set the color
	gw.fillRect(topLeftX, topLeftY, mW, mH);
}

// function to generate a random color string
std::string Disk::getRandColor()
{
	// vector holding supported color values as strings (from Lecture 2/15) excluding light gray, white (too hard to see)
	std::vector<std::string> colorVect{ "BLACK", "BLUE", "CYAN", "DARK_GRAY", "GRAY", "GREEN", "MAGENTA",
				"ORANGE", "PINK", "RED", "YELLOW" };

	// get a random number
	int randomChoice = std::rand() % colorVect.size(); // obtain random value from 0 up to the last index of colorVect

	// return the random color
	return colorVect[randomChoice];
}