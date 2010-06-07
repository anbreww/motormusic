#ifndef MUSIC_H
#define MUSIC_H

#include <avr/pgmspace.h>

/* note frequency constants */
const uint16_t notes[17] PROGMEM = {
    's',
    'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'i',
    'g',
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'I',
    'G'
};

/* these keys refer to notes in the previous table */
typedef enum NOTES_enum
{
    s = 0, /* silence */
    a = 1,
    b = 2,
    c = 3,
    d = 4,
    e = 5,
    f = 6,
    fis = 7,
    g = 8,

    a1 = 9,
    b1 = 10,
    c1 = 11,
    d1 = 12,
    e1 = 13,
    f1 = 14,
    fis1 = 15,
    g1 = 16
} NOTES_t;


/* 
 * {note, duration}, where note is a position in the notes[] table,
 * and duration is in n*tempo duration
 */

// lilypond segment
/*
 s2 g'8 fis' e' e' |
  fis' s4*5 a8 g' fis' e' e'4 fis'8 s4 d'8 s e' a |
  s8*7 a8 |
  e'4 fis'8 g'4 s8 e' cis'4 s8 d' e'4. a8 a4 fis' s8*9 g'8 fis' e' e' |
  fis' s4*5 a8 g' fis' e' e' |
  s4 fis'8 d' s4 e'8 a |
*/
#define MELODY_LENGTH 18
const uint8_t melody[MELODY_LENGTH][2] PROGMEM = {
    {s,2}, {g1,8}, {fis1,1}, {e1,1}, {e1,1},

    {fis1,1}, {s,4*5}, {a,8}, {g1,1}, {fis1,1}, {e1,1}, {e1,4},
    {fis1,8}, {s,4}, {d1,8}, {s,1}, {e1,1}, {a,1}
};



/*
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
*/

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
