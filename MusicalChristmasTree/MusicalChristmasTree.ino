#include "pitches.h"

const int buzzerPin = 10; 

//We Wish You A Merry Christmas

// notes in the melody: 
int melody[] = {
   G4,C5,C5,D5,C5,B4,A4,A4,
   A4,D5,D5,E5,D5,C5,B4,G4,
   G4,E5,E5,F5,E5,D5,C5,A5,G4,G4,A4,D5,B4,C5,
   G4,C5,C5,D5,C5,B4,A4,A4,
   A4,D5,D5,E5,D5,C5,B4,G4,
   G4,E5,E5,F5,E5,D5,C5,A5,G4,G4,A4,D5,B4,C5,
   G4,C5,C5,C5,B4,B4,C5,B4,A4,G4,
   D5,E5,D5,D5,C5,C5,G5,G4,G4,G4,A4,D5,B4,C5 
   };

// note durations: 4 = quarter note, 8 = eighth note, etc.: 
int noteDurations[] = {
                        4,4,8,8,8,8,4,4,
                        4,4,8,8,8,8,4,4,
                        4,4,8,8,8,8,4,4,8,8,4,4,4,2,
                        4,4,8,8,8,8,4,4,
                        4,4,8,8,8,8,4,4,
                        4,4,8,8,8,8,4,4,8,8,4,4,4,2,
                        4,4,4,4,2,4,4,4,4,2,
                        4,4,8,8,8,8,4,4,8,8,4,4,4,2,   
                        };


void setup() 
{
  int legthOfMelody = sizeof(melody);
  
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < legthOfMelody; thisNote++) 
  {
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 50% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.50;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin); 
  }
}

void loop() 
{
  // no need to repeat the melody.
}
