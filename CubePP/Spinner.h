/* 
* Spinner.h
*
* Created: 14/06/2015 14:25:12
* Author: drblah
*/


#ifndef __SPINNER_H__
#define __SPINNER_H__

#include "Shape.h"

class Spinner : public Shape
{
//variables
public:
	unsigned short cornor1[3];
	unsigned short cornor2[3];
	unsigned short cornor3[3];
	unsigned short cornor4[3];

protected:
private:

//functions
public:
	Spinner();
	~Spinner();
	void Generate(unsigned short frame[8][8]);
	void Spin();
protected:
private:
	Spinner( const Spinner &c );
	Spinner& operator=( const Spinner &c );

}; //Spinner

#endif //__SPINNER_H__
