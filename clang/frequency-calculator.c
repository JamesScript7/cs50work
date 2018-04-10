#include <math.h>
#include <string.h>
#include <cs50.h>
#include <stdio.h>

int frequency(string note);

int main(void)
{
  frequency("C4");
  return 0;
}

int frequency(string note)
{
  // INPUT_NOTE_PREP
  // noteList[13]: From key C to B with 's' as a placeholder for "Accidentals."
  // theNote:      Grabs input char of the note as an int.
  // len:          Storing the length of the input as an int.
  char noteList[13] = { 'C', 's', 'D', 's', 'E', 'F', 's', 'G', 's', 'A', 's','B', '\0' };
  int theNote = note[0];
  int len = strlen(note);

  // INPUT_OCTAVE_PREP
  // octave: Convert the input octave char into int.
  char theOctave[2];
  sprintf(theOctave, "%c", note[len - 1]);
  int octave = atoi(theOctave);

  // WAVE_CALCULATION_PREP
  // count:             Keeps track of the semitones relative to C.
  // semitones:         Converts semitones so that it's relative to A.
  // semitoneCountOfA4: Semitone count of frequency A relative to C.
  // freq:              Frequency value of the note.
  // octaveAtZero:      Frequency of A0.
  int count = 0;
  int semitones = 0;
  int semitoneCountOfA4 = 10;
  float freq = 0;
  float octaveFreqAtA0 = 27.5;

  // If input contains Sharps or Flats aka Accidentals.
  // Sharps will INCREMENT and Flats will DECREMENT a semitone to "int count".
  // (ASCII value of # == 35 and b == 98)
  if (len == 3)
  {
    if (note[1] == 35)
      count++;
    else if (note[1] == 98)
      count--;
    else
      return 1;
  }

  for (int i = 0; i < strlen(noteList); i++)
  {
    // count++: Increments semitone count.
    // if:      Compares between the ASCII DEC value.
    count++;
    if (theNote == noteList[i])
    {
      // semitones: Number of semitones relative to note A.
      // octave:    Finds out the octave frequency of note A based on which level specified.
      // freq:      Final calculation to find out the frequency value of the note.
      semitones = count - semitoneCountOfA4;
      octave = octaveFreqAtA0 * pow(2, octave);
      freq = pow(2, (float) semitones / 12) * octave;
      freq = round((freq / 100) * 100);

      printf("%s => %0.0fHz\n", note, freq);
      return freq;
    }
  }
  return 1;
}

// frequency chart:
// https://pages.mtu.edu/~suits/notefreqs.html
