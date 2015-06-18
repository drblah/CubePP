/* 
* Frame.h
*
* Created: 09/06/2015 18:30:20
* Author: drblah
*/


#ifndef __FRAME_H__
#define __FRAME_H__


class Frame
{
//variables
public:
	unsigned short frame[8][8];
protected:
private:

//functions
public:
	Frame();
	~Frame();
	void Draw();
	void SetPixelAt(unsigned short x, unsigned short y, unsigned short z, bool state);
	void Clear();
	void ClearLayer(unsigned short l);
	void ShiftDown();
	void ShiftUp();
	void Add(unsigned short *shape);
protected:
private:
	Frame( const Frame &c );
	Frame& operator=( const Frame &c );

}; //Frame

#endif //__FRAME_H__
