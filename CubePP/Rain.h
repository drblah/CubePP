/* 
* Rain.h
*
* Created: 13/06/2015 16:09:19
* Author: drblah
*/


#ifndef __RAIN_H__
#define __RAIN_H__

#include "Shape.h"

class Rain : public Shape
{
//variables
public:
protected:
private:

//functions
public:
	Rain(unsigned short nrOfDrops);
	~Rain();
	//unsigned short *Draw();
	void Generate(unsigned short frame[8][8]);
protected:
private:
	Rain( const Rain &c );
	Rain& operator=( const Rain &c );

}; //Rain

#endif //__RAIN_H__
