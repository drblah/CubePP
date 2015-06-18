/* 
* Rng.h
*
* Created: 11/06/2015 20:03:06
* Author: drblah
*/


#ifndef __RNG_H__
#define __RNG_H__


class Rng
{
//variables
public:
	unsigned short rngSeed;
	unsigned short rngCounter;
protected:
private:

//functions
public:
	Rng();
	~Rng();
	unsigned short NextNumber();
protected:
private:
	Rng( const Rng &c );
	Rng& operator=( const Rng &c );

}; //Rng

#endif //__RNG_H__
