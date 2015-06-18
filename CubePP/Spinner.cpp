/* 
* Spinner.cpp
*
* Created: 14/06/2015 14:25:12
* Author: drblah
*/

#define F_CPU 16000000

#include "Spinner.h"
#include <util/delay.h>


unsigned short cornor1[3];
unsigned short cornor2[3];
unsigned short cornor3[3];
unsigned short cornor4[3];

// default constructor
Spinner::Spinner()
{
	cornor1[0] = 1;
	cornor1[1] = 3;
	cornor1[2] = 1;
	
	cornor2[0] = 2;
	cornor2[1] = 3;
	cornor2[2] = 1;
	
	cornor3[0] = 1;
	cornor3[1] = 4;
	cornor3[2] = 1;
	
	cornor4[0] = 2;
	cornor4[1] = 4;
	cornor4[2] = 1;
} //Spinner

void Spinner::Generate(unsigned short frame[8][8])
{
		
	frame[cornor1[1]][cornor1[2]] = (frame[cornor1[1]][cornor1[2]] | 1 << cornor1[0]); // To turn on an LED we bit shifts a 1 to the place in the strip.
	frame[cornor2[1]][cornor2[2]] = (frame[cornor2[1]][cornor2[2]] | 1 << cornor2[0]); // To turn on an LED we bit shifts a 1 to the place in the strip.
	frame[cornor3[1]][cornor3[2]] = (frame[cornor3[1]][cornor3[2]] | 1 << cornor3[0]); // To turn on an LED we bit shifts a 1 to the place in the strip.
	frame[cornor4[1]][cornor4[2]] = (frame[cornor4[1]][cornor4[2]] | 1 << cornor4[0]); // To turn on an LED we bit shifts a 1 to the place in the strip.

	this->Spin();
}

void Spinner::Spin()
{
	if (cornor1[2] == cornor3[2] && cornor1[1] < cornor3[1])
	{
		cornor1[2]++;
		cornor1[1]++;
		
		cornor2[2]++;
		cornor2[1]++;
	}
	else if (cornor1[2] == cornor3[2]+1 && cornor1[1] == cornor3[1])
	{
		cornor1[2]--;
		cornor1[1]++;
		
		cornor2[2]--;
		cornor2[1]++;
	}
	else if (cornor1[2] == cornor3[2] && cornor1[1] > cornor3[1])
	{
		cornor1[2]--;
		cornor1[1]--;
		
		cornor2[2]--;
		cornor2[1]--;
	}
	else if (cornor1[2] == cornor3[2]-1 && cornor1[1] == cornor3[1])
	{
		cornor1[2]++;
		cornor1[1]--;
		
		cornor2[2]++;
		cornor2[1]--;
	}
}

// default destructor
Spinner::~Spinner()
{
} //~Spinner
