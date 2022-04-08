#include <stdint.h>
#include "lib/hd44780.h"
#include <avr/io.h>
#define delay 0xFCF3 // Determine the delay between polls
/* The delay global constant determine the polling rate of the potentiometer
 * delay value 0xFCF3 correspond to a 50ms gap between polls
 * it is calculated by 65536-(x*15625/1000) with x being the gap between polls in milliseconds
 */

uint16_t poval = 1;
// initialize the built-in ADC of the Arduino to read the potentiometer from pin A0
static inline void initADC0(void) {
	ADMUX |= (1 << REFS0); //reference voltage on AVCC
	ADCSRA |= (1 << ADPS1) | (1 << ADPS0); //ADC clock prescaler /8
	ADCSRA |= (1 << ADEN); //enables the ADC
}
// initialize the timer
void timer_init()
{
	TCNT1 = delay;
	TIFR1 |= 0x01;
	TCCR1B = 0x05;
}
// the timer_delay is less accurate than _delay_ms, due to the extra instructions in the if clause
uint16_t timer_delay(unsigned long x)
{
	while(--x!=0) {
		if ((TIFR1 & 0x01)!=0) {
			TCNT1 = delay; //reset the timer
			TIFR1 |= 0x01;
			// Poll the potentiometer into the ADC variable
			ADCSRA |= (1<<ADSC);
			while( ADCSRA & (1<<ADSC) );
			/* Put any other code you want to execute along with the polling here.
			 * Here I save it to poval and print it onto the LCD
			 */
			poval = ADC+1;
			LCD_ClearLine(0);
			LCD_GotoXY(0,0);
			LCD_PrintInteger(poval);	
		}
		_delay_ms(1);
	}
	return ADC;
}
int main(void)
{
	
	uint32_t loops = 0;
	// initialize the ADC, LCD and timer
	initADC0();
	LCD_Setup();
	LCD_Clear();
	timer_init();
	uint16_t del;	
	/* put the code of your project here and call timer_delay when you need to delay. Note that
	 * the potentiometer only poll during the delays, and continues to poll as oppose to stop
	 * when using _delay_ms
	 */
	while(1) 
	{
		/* for the purpose of my project the potentiometer control the rate at which loops
		 * count up, but you can implement your own instructios
		 */
		del = poval*5;
		timer_delay(del);			
	       	LCD_ClearLine(1);
		LCD_GotoXY(0, 1);	
		LCD_PrintInteger(loops);
		loops++;
	}	
	return 0;
}
