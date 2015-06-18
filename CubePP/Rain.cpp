/* 
* Rain.cpp
*
* Created: 13/06/2015 16:09:19
* Author: drblah
*/


#include "Rain.h"
#include "Rng.h"
#include <stdlib.h>
#include <string.h>

Rng rainGen;

unsigned short drops;

// default constructor
Rain::Rain(unsigned short nrOfDrops)
{
	drops = nrOfDrops;
} //Rain
/*
unsigned short *Rain::Draw()
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

	for (unsigned short d = 0; d < drops; d++)
	{
			unsigned short x = rainGen.NextNumber()>>5;
			unsigned short z = rainGen.NextNumber()>>5;
			initFrame[7][z] = (initFrame[7][z] | 1 << x);
	}

	unsigned short *result = (unsigned short *)malloc(sizeof(short) * 8 * 8);
	memcpy(result, initFrame, sizeof(short) * 8 * 8);

	return result;
}
*/
void Rain::Generate(unsigned short frame[8][8])
{
	for (unsigned short d = 0; d < drops; d++)
	{
		unsigned short x = rainGen.NextNumber()>>5;
		unsigned short z = rainGen.NextNumber()>>5;
		frame[7][z] = (frame[7][z] | 1 << x);
	}
}

// default destructor
Rain::~Rain()
{
} //~Rain
