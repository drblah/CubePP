/*
 * CubePP.cpp
 *
 * Created: 09/06/2015 18:29:14
 *  Author: drblah
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>
#include "Frame.h"
#include "Plane.h"
#include "Rain.h"
#include "Spinner.h"

Frame LEDCube;

void InitTimer()
{
	// Timer set up for CTC mode at clkio/256 from prescaler
	TCCR0 |= ( (0 << FOC0) | (0 << WGM00) | (0 << COM01) | (0 << COM00) | (1 << WGM01) | (1 << CS02) | (0 << CS01) | (0 << CS00) );
	
	// Initialize counter to 0
	TCNT0 = 0;
	
	// Set compare value
	OCR0 = 40;
	
	// Enable Compare Match Interrupt
	TIMSK |= 1 << OCIE0;
	
	// Enable global interrupts
	sei();
}

ISR(TIMER0_COMP_vect)
{
	LEDCube.Draw();
}


int main(void)
{
	//Init IO
	DDRA = 0xff;
	DDRB = 0xff;
	DDRC = 0xff;
	
	InitTimer();
	
	Plane myPlane(6, 1, 0, 2, 2, 3);
	
	//Rain rainGenerator(4);
	
    while(1)
    {
		/*
		LEDCube.Add(rainGenerator.Draw());
		_delay_ms(500);
		LEDCube.ShiftDown();
		*/
		for (unsigned short i = 0; i < 3; i++)
		{
			LEDCube.Add(myPlane.Draw());
			_delay_ms(250);
			LEDCube.Clear();
			myPlane.RotateX();
		}
		if (myPlane.origin[1] < 6)
		{
			myPlane.origin[1] = myPlane.origin[1] + 1;
			myPlane.orientation = 3;
		}
		else
		{
			myPlane.origin[1] = 1;
			myPlane.orientation = 3;
		}

    }
}