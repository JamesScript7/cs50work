#include <math.h>
#include <string.h>
#include <ctype.h>
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
    // 1. From key C to B with 's' as a placeholder for "Accidentals"
    // 2. Grabs input char of the note as an int
    char noteList[13] = { 'C', 's', 'D', 's', 'E', 'F', 's', 'G', 's', 'A', 's','B', '\0' };
    int theNote = note[0];

    // Storing the length of the input as an int
    char noteLen[2];
    sprintf(noteLen, "%lu", strlen(note));
    int len = atoi(noteLen);

    // Convert the input octave char into int:
    char theOctave[2];
    sprintf(theOctave, "%c", note[len - 1]);
    int octave = atoi(theOctave);

    // 1. Keeps track of the semitones relative to C
    // 2. Converts semitones so that it's relative to A
    // 3. Frequency value of the note
    // 4. Frequency of A0
    // 5. Semitone count of frequency A relative to C
    int count = 0;
    int semitones = 0;
    float freq = 0;
    float octaveAtZero = 27.5;
    int semitoneCountOfA4 = 10;

    // If input contains Sharps or Flats aka Accidentals
    if (len == 3)
    {
        // Stores the Accidental
        char accidental[2];
        sprintf(accidental, "%c", note[1]);

        // Converts ASCII value of # and b into char Sharps and Flats so we can strcmp()
        char sharp[2];
        char flat[2];
        sprintf(sharp, "%c", '#');
        sprintf(flat, "%c", 'b');

        // Sharps will increment and Flats will decrement a semitone, "int count"
        if (strcmp(accidental, sharp) == 0) count++;
        if (strcmp(accidental, flat) == 0) count--;
    }

    for (int i = 0; i < strlen(noteList); i++)
    {
        // 1. Increments semitone count
        // 2. Compares between the ASCII DEC value
        count++;
        if (theNote == noteList[i])
        {
            // 1. Number of semitones relative to note A
            // 2. Finds out the octave frequency of note A based on which level specified
            // 3. Final calculation to find out the frequency value of the note
            semitones = count - semitoneCountOfA4;
            octave = octaveAtZero * pow(2, octave);
            freq = pow(2, (float) semitones / 12) * octave;
        }
    }
    printf("%s => %0.2f\n", note, round(freq * 100) / 100);
    return round(freq * 100) / 100;
}

// frequency chart
// https://pages.mtu.edu/~suits/notefreqs.html
