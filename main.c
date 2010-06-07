/*
 * MotorMusic
 *
 * Andrew Watson - 2010
 *
 * Play basic 1-bit "stereo" music on a pair of DC motors
 *
 */

#include <avr/io.h>
#include "config.h"
#include "music.h"

#include <util/delay.h>
#include "uart.h"

#include <avr/pgmspace.h>

#define DEBUG_DDR   DDRA
#define DEBUG_PORT  PORTA
#define DEBUG_PINS  PINA

#define TEMPO   200 /* in ms */

int main(void)
{
    // init i/o
    DEBUG_PORT = 0x00;
    DEBUG_DDR = 0xFF;
    uart_init(0,0,0,0,0);
    uart_transmit_byte_block('\n');
    uart_transmit_byte_block('\r');
    // init timers
    // setup pointers? (to melody and notes)
    int i;
    uint8_t note, duration;
    uint16_t freq;

    for(i = 0; i < MELODY_LENGTH; i++)
    {
        // load note
        note = pgm_read_byte(&melody[i][0]);
        freq = pgm_read_word(&notes[note]);
        duration = pgm_read_byte(&melody[i][1]);

    	DEBUG_PORT = (freq & 0xFF);
    	uart_transmit_byte_block(note);
    	uart_transmit_byte_block(freq);
    	uart_transmit_byte_block(' ');

        while (duration > 0)
        {
            _delay_ms(TEMPO);
            duration--;
        }
    }



    // main

    return 0;
    
}
