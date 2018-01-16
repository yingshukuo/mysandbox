// lowpass.c
// by:   Ying-Shu Kuo
// what: This progarm aims to act as a simple low pass filter.
//       Given a wav file, expected output file name, and the cutoff frequency,
//       the program will spit out the filtered wav file to the output file.
// how:  ./lowpass path/to/input.wav path/to/output.wav cutoff[Hz]

#include <stdio.h>
#include <stdlib.h>
#include <portsf.h>

enum {
    ARG_NAME,   // name of this program
    ARG_INFILE, // name of input file
    ARG_OUTFILE,// name of output file
    ARG_CUTOFF, // cutoff frequency
    ARG_NARGS   // number of arguments
};

int main(int argc, char *argv[]) {
    int cutoff = 0;
    if (argc != ARG_NARGS) {
        fprintf(stderr, "Usage: lowpass path/to/input.wav path/to/output.wav "\
                        "cutoff[Hz]\n");
        return -1;
    }
    cutoff = atoi(argv[ARG_CUTOFF]);
    printf("input: %s %s %d\n", argv[ARG_INFILE], argv[ARG_OUTFILE], cutoff);
    return 0;
}
