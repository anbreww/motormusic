#ifndef MUSIC_H
#define MUSIC_H

#include <avr/pgmspace.h>

/* note frequency constants */
const uint16_t notes[12] PROGMEM = {
    0x01,
    0x02,
    0x04,
    0x08,
    0x10,
    0x20,
    0x40,
    0x80,
    0x0a,
    0x05,
    0xa0,
    0x50
};

/* these keys refer to notes in the previous table */
typedef enum NOTES_enum
{
    A1 = 0,
    B1 = 1,
    C1 = 2,
    D1 = 3,
    E1 = 4,
    F1 = 5,
    G1 = 6,

    A2 = 7,
    B2 = 8,
    C2 = 9,
    D2 = 10,
    E2 = 11,
    F2 = 12,
    G2 = 13,
} NOTES_t;


/* 
 * {note, duration}, where note is a position in the notes[] table,
 * and duration is in n*tempo duration
 */


#define MELODY_LENGTH   16
const uint8_t melody[MELODY_LENGTH][2] PROGMEM = {
    {A1, 2},
    {B1, 4},
    {C1, 8},
    {D1, 2},
    {E1, 10},
    {A2, 5},
    {B2, 2},
    {C2, 2},
    {B2, 2},
    {C2, 2},
    {B2, 2},
    {C2, 2}
};

/*
 * how to read:
 * #define NUM 4
 * note = pgm_read_byte_far(melody[NUM][0]);
 * duration = pgm_read_byte_far(melody[NUM[1]);
 *
 * for 16-bit integers:
 * pgm_read_word_far(notes[2]);
 *
 */

#endif
