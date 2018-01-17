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

// lowpass filter:
//   y[n] = b0 * v[n] + b1 * v[n-1]
//   v[n] =  1 * x[n] - a1 * v[n-1]
//   where
//     b0 =  K   /(K+1)
//     b1 =  K   /(K+1), K = tan(pi * fc / fs), fc = cutoff, fs = sample
//     a1 = (K-1)/(K+1)
int main(int argc, char *argv[]) {
    // initialize
    int cutoff = 0;

    // argument check and assignment
    if (argc != ARG_NARGS) {
        fprintf(stderr, "Usage: lowpass path/to/input.wav path/to/output.wav "\
                        "cutoff[Hz]\n");
        return -1;
    }
    cutoff = atoi(argv[ARG_CUTOFF]);
    printf("input: %s %s %d\n", argv[ARG_INFILE], argv[ARG_OUTFILE], cutoff);

    // allocate spaces

    // open input file

    // create output file
    
    // read in a block based fashion
    //   in which do lowpass filter
    //   and put the result to the output file
    //   lowpass filter:
    //     y[n] = b0 * v[n] + b1 * v[n-1]   Y(z) = (b0 + b1 * z^-1) * V(z)
    //     v[n] =  1 * x[n] - a1 * v[n-1]   X(z) = (1 + a1 * z^-1) * V(z)
    //     where
    //       b0 =  K   /(K+1)
    //       b1 =  K   /(K+1), K = tan(pi * fc / fs), fc = cutoff, fs = sample
    //       a1 = (K-1)/(K+1)
    //   since lowpass filter only looks 1 previous signal,
    //   we only need 2 buffers representing v[n-1] (initially v[0-1] = 0)
    //   and v[n].

    // take care of the last block

    // close output file
    
    // close input file
    
    // deallocate spaces

    return 0;
}
