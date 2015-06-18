/* 
* Plane.h
*
* Created: 11/06/2015 20:17:46
* Author: drblah
*/


#ifndef __PLANE_H__
#define __PLANE_H__

#include "Shape.h"

class Plane : public Shape
{
//variables
public:
	unsigned short origin[3];
	unsigned short size[2];
	unsigned short orientation;
protected:
private:

//functions
public:
	Plane(unsigned short x, unsigned short y, unsigned short z, unsigned short width, unsigned short length, unsigned short startOrientation);
	~Plane();
	void Generate(unsigned short frame[8][8]);
	void RotateX();
protected:
private:
	Plane( const Plane &c );
	Plane& operator=( const Plane &c );

}; //Plane

#endif //__PLANE_H__
