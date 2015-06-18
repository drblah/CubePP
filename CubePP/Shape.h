/* 
* Shape.h
*
* Created: 13/06/2015 22:04:36
* Author: drblah
*/


#ifndef __SHAPE_H__
#define __SHAPE_H__


class Shape
{
//variables
public:
protected:
private:

//functions
public:
	Shape();
	~Shape();
	unsigned short *Draw();
	virtual void Generate(unsigned short frame[8][8]);
protected:
private:
	Shape( const Shape &c );
	Shape& operator=( const Shape &c );

}; //Shape

#endif //__SHAPE_H__
