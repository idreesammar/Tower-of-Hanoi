#pragma once

#include <iostream>
#include <string>
#include "gwindow.h"
#include <vector>

class Disk
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
	//        Calls the default Disk constructor to make a Disk object
	Disk();

	// Name:
	//        parameterized constructor
	// Input:
	//        4 integers input values for X, Y coordinates and width and height values
	// Output:
	//        None (it's a constructor)
	// Side effects:
	//        sets member variable values to corresponding input values
	// Summary:
	//        Calls the Disk constructor to make a Disk object
	Disk(int inX, int inY, int inW, int inH);

	// Name:
	//        draw
	// Input:
	//        a GWindow by reference
	// Output:
	//        None
	// Side effects:
	//        draws disk to window
	// Summary:
	//        use the GWindow and the member variables to create the colored rectangles that represent the Disk
	void draw(GWindow& gw);

	// Name:
	//        Setters (for X and Y)
	// Input:
	//        an integer input 
	// Output:
	//        None
	// Side effects:
	//        sets member variable value to input
	// Summary:
	//        changes the member variable values to new values given
	void setX(int inX);
	void setY(int inY);

	// Name:
	//        getter for Height
	// Input:
	//        none
	// Output:
	//        integer with disk height
	// Side effects:
	//        none
	// Summary:
	//        returns the value of the Disk's mH member variable
	int getHeight();

	// Name:
	//        getRandColor
	// Input:
	//        none
	// Output:
	//        a string with a color name
	// Side effects:
	//        none
	// Summary:
	//        Uses std::rand to pick a random color from a preset color vector of choices
	std::string getRandColor();

private:
	int mX;  // x coordinate of bottom center
	int mY;	// y coordinate of bottom center
	int mW;	// width in pixels
	int mH;	// height in pixels
	std::string mColor;	// color of disk
};