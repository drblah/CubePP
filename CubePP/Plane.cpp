/* 
* Plane.cpp
*
* Created: 11/06/2015 20:17:46
* Author: drblah
*/


#include "Plane.h"
#include <stdlib.h>
#include <string.h>

unsigned short origin[3];
unsigned short size[2];
unsigned short orientation;
// default constructor
Plane::Plane(unsigned short x, unsigned short y, unsigned short z, unsigned short width, unsigned short length, unsigned short startOrientation)
{
	origin[0] = x;
	origin[1] = y;
	origin[2] = z;
	
	size[0] = width;
	size[1] = length;
	orientation = startOrientation;
} //Plane

void Plane::Generate(unsigned short frame[8][8])
{
	
	switch(orientation)
	{
		case 0:
			
			for (unsigned short width = 0; width < size[0]; width++)
			{
				for (unsigned short length = 0; length < size[1]; length++)
				{
					frame[origin[1]][origin[2]+length] = (frame[origin[1]][origin[2]+length] | 1 << (origin[0]+width));
				}
				
			}
			
		break;
		
		case 1:
			
			for (unsigned short width = 0; width < size[0]; width++)
			{
				for (unsigned short length = 0; length < size[1]; length++)
				{
					frame[origin[1]+length][origin[2]+length] = (frame[origin[1]+length][origin[2]+length] | 1 << (origin[0]+width));
				}
				
			}
		
		break;
		
		case 2:
			
			for (unsigned short width = 0; width < size[0]; width++)
			{
				for (unsigned short length = 0; length < size[1]; length++)
				{
					frame[origin[1]+length][origin[2]] = (frame[origin[1]+length][origin[2]] | 1 << (origin[0]+width));
				}
				
			}
		
		break;
		
		case 3:
		
		for (unsigned short width = 0; width < size[0]; width++)
		{
			for (unsigned short length = 0; length < size[1]; length++)
			{
				frame[origin[1]+length][origin[2]-length] = (frame[origin[1]+length][origin[2]-length] | 1 << (origin[0]+width));
			}
			
		}
		
		break;
		
		case 4:
		
			for (unsigned short width = 0; width < size[0]; width++)
			{
				for (unsigned short length = 0; length < size[1]; length++)
				{
					frame[origin[1]][origin[2]-length] = (frame[origin[1]][origin[2]-length] | 1 << (origin[0]+width));
				}
				
			}
		
		break;
		
		case 5:
		
		for (unsigned short width = 0; width < size[0]; width++)
		{
			for (unsigned short length = 0; length < size[1]; length++)
			{
				frame[origin[1]-length][origin[2]-length] = (frame[origin[1]-length][origin[2]-length] | 1 << (origin[0]+width));
			}
			
		}
		
		break;
		
		case 6:
		
			for (unsigned short width = 0; width < size[0]; width++)
			{
				for (unsigned short length = 0; length < size[1]; length++)
				{
					frame[origin[1]-length][origin[2]] = (frame[origin[1]-length][origin[2]] | 1 << (origin[0]+width));
				}
				
			}		
		
		break;
		
		case 7:
		
		for (unsigned short width = 0; width < size[0]; width++)
		{
			for (unsigned short length = 0; length < size[1]; length++)
			{
				frame[origin[1]-length][origin[2]+length] = (frame[origin[1]-length][origin[2]+length] | 1 << (origin[0]+width));
			}
			
		}
		
		break;
	}
	

}

void Plane::RotateX()
{
	orientation++;
	if (orientation > 7)
	{
		orientation = 0;
	}
}

// default destructor
Plane::~Plane()
{
} //~Plane
