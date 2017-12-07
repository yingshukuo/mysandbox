// wavetable_synth.c
// by:   Ying-Shu Kuo
// what: This progarm serves as a demonstration of a very simple implementation
//       of wavetable synthesis. Wavetable synthesis is essentially gluing the 
//       same clip again and again. A very simple example would be a 1-cycle
//       sine wave: gluing 5 1-cycle sine wave together will make it a 5-cycle
//       sine wave.
// what2:A 2-D array of double is used as the wavetable. The length of each
//       wave is always 32. Currently this program does not support stretching
//       or fade-in fade-out.
// how:  ./wavetable_synth wavetype(0~2) duration(s) srate(Hz)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum {
    ARG_NAME,   // name of this program
    ARG_TYPE,   // wave type (0~2)
    ARG_DURA,   // wave duration (sec)
    ARG_SR,     // sample rate (Hz)
    ARG_NARGS   // # arguments
};

typedef enum {
    TYPE_TRI,   // triangle wave
    TYPE_SINE,  // sine wave
    TYPE_SQ,    // square wave
    TYPE_NTYPE       // # of wavetypes
} wavetype;

const double wavetable[3][32] = {
    {0.0,   0.125,  0.25,   0.375,  0.5,    0.625,  0.75,   0.875,
     1.0,   0.875,  0.75,   0.625,  0.5,    0.375,  0.25,   0.125,
     0.0,   -0.125, -0.25,  -0.375, -0.5,   -0.625, -0.75,  -0.875,
     -1.0,  -0.875, -0.75,  -0.625, -0.5,   -0.375, -0.25,  -0.125
    },
    {0.0,   0.1951, 0.3827, 0.5556, 0.7071, 0.8315, 0.9239, 0.9808,
     1.0,   0.9808, 0.9239, 0.8315, 0.7071, 0.5556, 0.3827, 0.1951,
     0.0,   -0.1951,-0.3827,-0.5556,-0.7071,-0.8315,-0.9239,-0.9808,
     -1.0,  -0.9808,-0.9239,-0.8315,-0.7071,-0.5556,-0.3827,-0.1951
    },
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     1.0,   1.0,    1.0,    1.0,    1.0,    1.0,    1.0,    1.0,
     0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,
     -1.0,  -1.0,   -1.0,   -1.0,   -1.0,   -1.0,   -1.0,   -1.0
    }
};

int main(int argc, char* argv[]) {
    int         tmp, i, j;
    wavetype    wtype;
    int         nsamps;
    double      duration, srate;
    double      val;

    if (argc != ARG_NARGS) {
        fprintf(stderr, "Usage: wavetable_synth type(0~2) duration srate\n");
        return 1;
    }
    tmp         = atoi(argv[ARG_TYPE]);
    duration    = atof(argv[ARG_DURA]);
    srate       = atof(argv[ARG_SR]);
    if (tmp >= (int)TYPE_NTYPE || tmp < 0) {
        fprintf(stderr, "Usage: wavetable_synth type(0~2) duration srate\n");
        return 1;
    }
    wtype       = (wavetype)tmp;

    nsamps      = (int)(srate * duration);

    i = nsamps;
    for (i = nsamps; i >= 32; i -= 32){
        for (j = 0; j < 32; j++) {
            val = wavetable[wtype][j];
            fprintf(stdout, "%.8lf", val);
            if (j % 8 == 7) {
                fprintf(stdout, "\n");
            } else {
                fprintf(stdout, "\t");
            }
        }
    }
    tmp = i;
    for (j = 0; j < tmp; j++) {
        val = wavetable[wtype][j];
        fprintf(stdout, "%.8lf", val);
        if (j % 8 == 7) {
            fprintf(stdout, "\n");
        } else {
            fprintf(stdout, "\t");
        }
    }
    if (j % 8 != 0) {
        fprintf(stdout, "\n");
    }

    return 0;
}




