/* 
* Frame.cpp
*
* Created: 09/06/2015 18:30:20
* Author: drblah
*/

#include <avr/io.h>
#include <stdlib.h>
#include "Frame.h"

unsigned short layer = 0;
unsigned short strip = 0;
unsigned short counter = 0;
unsigned short frame[8][8];

// default constructor
Frame::Frame()
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
	
	for (unsigned short l = 0; l < 8; l++)
	{
		for (unsigned short s = 0; s < 8; s++)
		{
			frame[l][s] = initFrame[l][s];
		}
	}
} 

/*
	The main Draw function which takes each element of the 8x8 frame array and clocks it out on the shift registers.
	The function will only draw one layer each time it is called in order to improve the visibility of the LEDs.
	If the LEDs are too dim, try and increase the allowed size of counter as this will cause the draw function to draw each layer multiple times.
	Be aware that drawing the layer multiple times will slow the draw loop significantly and will require some tweaking of the counters for the interrupt to remove flickering.
*/
void Frame::Draw()
{
	if (counter < 1)
	{
		PORTB = 0b00001000; // Disable output on shift register

		for (strip = 0; strip < 8; strip++)
		{
			PORTB = 0b00001000 | strip;
			PORTA = this->frame[layer][strip];
		}
			
		PORTB = 0; // Output enable shift register
		PORTC = (1 << layer); // Enable layer
			
		counter++;
			
	}
	else
	{
		counter = 0;
			
		if (layer < 7)
		{
			layer++;
		}
		else
		{
			layer = 0;
		}
	}
}

/*
	Set the On/Off state of an individual LED.
*/

void Frame::SetPixelAt(unsigned short x, unsigned short y, unsigned short z, bool state)
{
	if (state == true)
	{
		this->frame[y][z] = (this->frame[y][z] | 1 << x); // To turn on an LED we bit shifts a 1 to the place in the strip.
	}
	else
	{
		this->frame[y][z] = ~(~this->frame[y][z] | 1 << x); // Basically we do the same when turning it off, but here we first invert, then bit shift 1 to the place and finally inverts everything once again.
	}
}

void Frame::Clear()
{
	for (unsigned short l = 0; l < 8; l++)
	{
		for (unsigned short s = 0; s < 8; s++)
		{
			this->frame[l][s] = 0;
		}
	}
}

void Frame::ClearLayer(unsigned short l)
{
	for (unsigned short i = 0; i < 8; i++)
	{
		this->frame[l][i] = 0;
	}
}

void Frame::ShiftUp()
{
	for (unsigned short l = 7; l > 0; l--)
	{
		for (unsigned short s = 0; s < 8; s++)
		{
			this->frame[l][s] = this->frame[l-1][s];
		}
	}
	this->ClearLayer(0);
}

void Frame::ShiftDown()
{
	for (unsigned short l = 0; l < 7; l++)
	{
		for (unsigned short s = 0; s < 8; s++)
		{
			this->frame[l][s] = this->frame[l+1][s];
		}
	}
	this->ClearLayer(7);
}

void Frame::Add(unsigned short *shape)
{
	for (unsigned short l = 0; l < 8; l++)
	{
		for (unsigned short s = 0; s < 8; s++)
		{
			this->frame[l][s] |= *(shape + s + (l*8));
		}
	}
	free(shape);
}

// default destructor
Frame::~Frame()
{
} //~Frame
