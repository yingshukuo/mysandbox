// sinewave.c
// by:   Ying-Shu Kuo
// what: This program aims to print out sine wave in text form.
//       Given the frequency, duration of the sine wave with the sampling rate,
//       A stream of values will be printed out to stdout.
// ref:  Audio Programming Book

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.141592654)
#endif

// argument list
enum {
    ARG_NAME,   // name of this program
    ARG_DURA,   // sine wave duration (sec)
    ARG_FREQ,   // sine wave frequency (Hz)
    ARG_SR,     // sample rate (Hz)
    ARG_NARGS   // # arguments
};

int main(int argc, char* argv[]) {
    int i, nsamps;
    double val, duration, freq, srate;
    double two_pi = M_PI * 2.0;
    double delta;

    if (argc != ARG_NARGS) {
        fprintf(stderr, "Usage: sinewave duration freq srate\n");
        return 1;
    }
    duration    = atof(argv[ARG_DURA]);
    freq        = atof(argv[ARG_FREQ]);
    srate       = atof(argv[ARG_SR]);

    delta       = two_pi * freq / srate;
    nsamps      = (int)(srate * duration);

    for (i = 0; i < nsamps; i++) {
        val = sin(delta * i);
        fprintf(stdout, "%.8lf", val);
        if (i % 5 == 4) {
            fprintf(stdout, "\n");
        } else {
            fprintf(stdout, "\t");
        }
    }

    fprintf(stdout, "done.\n");
    return 0;
}
