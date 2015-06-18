/* 
* Rng.cpp
*
* Created: 11/06/2015 20:03:06
* Author: drblah
*/


#include "Rng.h"

unsigned short rngSeed;
unsigned short rngCounter;

// default constructor
Rng::Rng()
{
	rngSeed = 38;
	rngCounter = 0;
} //Rng

unsigned short Rng::NextNumber()
{
	rngSeed = (43*rngSeed+rngCounter) % 255;
	if (rngCounter < 255)
	{
		rngCounter++;
	}
	else
	{
		rngCounter = 0;
	}
	
	return rngSeed;
}

// default destructor
Rng::~Rng()
{
} //~Rng
