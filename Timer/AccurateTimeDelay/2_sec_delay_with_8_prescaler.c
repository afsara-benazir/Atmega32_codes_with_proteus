/*
 * Created: 5/9/18 10:22:24 PM
 *  Author: spondon
 */ 


//create accurate 2s time delay no prescaler

#include <avr/io.h>
#include <avr/interrupt.h>
volatile int overFlow ;

ISR(TIMER1_OVF_vect){
	overFlow++ ;
	if(overFlow==4)// time required to overflow 2^16 * 8 * 4 ~= 2 sec
	{
		overFlow = 0 ;
		PORTB = ~PORTB ;
	}
}
void timer_init(){
	TCCR1A = 0x00 ;//normal mode
	TCCR1B = 0x02 ;//prescaler = 1,8,64,256,1024 
	TIMSK = 0x04 ;//enable overflow interrupt
}

int main(void)
{
	DDRB = 0xFF ;
	timer_init() ;
	overFlow = 0 ;
	PORTB = 0xFF ;
	sei() ;
    while(1)
    {
        //TODO:: Please write your application code 
    }
}