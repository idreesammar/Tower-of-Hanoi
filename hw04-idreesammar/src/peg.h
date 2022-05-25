#pragma once

#include <string>

#include <vector>
#include "gwindow.h"

#include "disk.h"

class Peg
{
public:
	// Name:
	//        default constructor
	// Input:
	//        None
	// Output:
	//        None (it's a constructor)
	// Side effects:
	//        sets member variables to initialized values
	// Summary:
	//        Calls the default Peg constructor to make a Peg object
	Peg();

	// Name:
	//        parameterized constructor
	// Input:
	//        4 integers input values for X, Y coordinates and width and height values
	// Output:
	//        None (it's a constructor)
	// Side effects:
	//        sets member variable values to corresponding input values
	// Summary:
	//        Calls the Peg constructor to make a Peg object
	Peg(int inX, int inY, int inW, int inH);

	// Name:
	//        draw
	// Input:
	//        a GWindow by reference
	// Output:
	//        None
	// Side effects:
	//        draws a peg and all disks on it to window
	// Summary:
	//        use the GWindow and the member variables to create a peg and all disks on it from diskVect
	void draw(GWindow& gw);

	// Name:
	//        addDisk
	// Input:
	//        a Disk object
	// Output:
	//        None
	// Side effects:
	//        appropriately sets the x,y coordinates of the disk before adding 
	//		  updates curValue 
	// Summary:
	//        adds a Disk to the end of the peg's disk vector member variable
	void addDisk(Disk inDisk);

	// Name:
	//        removeDisk
	// Input:
	//        None
	// Output:
	//        a Disk object
	// Side effects:
	//        decreases the peg's diskVect size by 1
	//		  updates curValue 
	// Summary:
	//        removes a disk from the end of the peg's disk vector member variable
	Disk removeDisk();

private:
	int mX; // x coordinate (bottom center)
	int mY;	// y coordinate (bottom center)
	int mW; // width
	int mH; // height
	int xCenter; // center of peg on x axis (also center of each disk on peg)
	int curTop; // denotes top center y coordinate of current hightest disk on peg

	std::string color;	// color of peg

	std::vector<Disk> diskVect; // vector of all disks of the peg
};