/* 
* Shape.cpp
*
* Created: 13/06/2015 22:04:36
* Author: drblah
*/


#include "Shape.h"
#include <stdlib.h>
#include <string.h>

// default constructor
Shape::Shape()
{
} //Shape

unsigned short *Shape::Draw()
{
	unsigned short initFrame[8][8]= {
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0}
	};
	
	this->Generate(initFrame);
	
	unsigned short *result = (unsigned short *)malloc(sizeof(short) * 8 * 8);
	memcpy(result, initFrame, sizeof(short) * 8 * 8);

	return result;
}

void Shape::Generate(unsigned short frame[8][8])
{
	
}

// default destructor
Shape::~Shape()
{
} //~Shape
