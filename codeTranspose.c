#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define     NCHORDS     12;
const char *chords[] = {"A", "A#(Bb)", "B", "C", "C#(Db)", "D", "D#(Eb)", "E", "F", "F#(Gb)", "G", "G#(Ab)"};

char* compactChord(const char *chord)
{
    size_t len = strlen(chord);
    size_t newLength = 1;

    if((len > 1) && ((chord[1] == '#') || (chord[1] == 'b'))) newLength = 2;

    char *cChord = (char *)malloc(sizeof(char) * (newLength + 1));
    strncpy(cChord, chord, newLength);
    cChord[newLength] = '\0';

    return cChord;
}

char *transpose(char* chord, int n)
{
    return "a";
}

int main(int argc, char const *argv[])
{
    char *cChord = compactChord("C#aug7");
    printf("%s\n", cChord);
    free(cChord);
    return 0;
}
