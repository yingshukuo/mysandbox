// lowpass.c
// by:   Ying-Shu Kuo
// what: This progarm aims to act as a simple low pass filter.
//       Given a wav file, expected output file name, and the cutoff frequency,
//       the program will spit out the filtered wav file to the output file.
// how:  ./lowpass path/to/input.wav path/to/output.wav cutoff[Hz]

#include <stdio.h>
#include <stdlib.h>
#include <portsf.h>

// debugging
#ifndef _DEBUG
#define _DEBUG
#endif

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
    int ret = 0;
    int input_fd = 0;
    int output_fd = 0;
    PSF_PROPS *input_props = NULL;

    // argument check and assignment
    if (argc != ARG_NARGS) {
        fprintf(stderr, "Usage: lowpass path/to/input.wav path/to/output.wav "\
                        "cutoff[Hz]\n");
        return -1;
    }
    cutoff = atoi(argv[ARG_CUTOFF]);
#ifdef _DEBUG
    printf("input: %s %s %d\n", argv[ARG_INFILE], argv[ARG_OUTFILE], cutoff);
#endif

    // allocate spaces
    input_props = malloc(sizeof(PSF_PROPS));
    if (input_props == NULL) {
        fprintf(stderr, "Error: can not allocate memory.\n");
        return -1; //FIXME: errno
    }
    
    // start system
    ret = psf_init();
    if (ret != 0) {
        fprintf(stderr, "Error %d: can not start the portsf system.", ret);
        // deallocate spaces FIXME
        free(input_props);
        return ret;
    }
#ifdef _DEBUG
    printf("open system success\n");
#endif
    

    // open input file
    ret = psf_sndOpen(argv[ARG_INFILE], input_props, 0);
    if (ret < 0) {
        fprintf(stderr, "Error %d: can not open input file %s.\n",\
                        ret, argv[ARG_INFILE]);
        // deallocate spaces FIXME
        free(input_props);
        return ret;
    }
    input_fd = ret;
#ifdef _DEBUG
    printf("input_fd = %d\n", input_fd);
#endif

    // create output file
    ret = psf_sndCreate(argv[ARG_OUTFILE], input_props,\
                        1, 0, PSF_CREATE_WRONLY);
    if (ret < 0) {
        fprintf(stderr, "Error %d: can not create output file %s.\n",\
                        ret, argv[ARG_OUTFILE]);
        // deallocate spaces FIXME
        free(input_props);
        return ret;
    }
    output_fd = ret;
#ifdef _DEBUG
    printf("output_fd = %d\n", output_fd);
#endif
    
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
    ret = psf_sndClose(output_fd);
    if (ret != 0) {
        fprintf(stderr, "Error %d: can not close output file %s\n",\
                        ret, argv[ARG_OUTFILE]);
        // deallocate spaces FIXME
        free(input_props);
        return ret;
    }
#ifdef _DEBUG
    printf("close output file success\n");
#endif
    
    // close input file
    ret = psf_sndClose(input_fd);
    if (ret != 0) {
        fprintf(stderr, "Error %d: can not close input file %s\n",\
                        ret, argv[ARG_INFILE]);
        // deallocate spaces FIXME
        free(input_props);
        return ret;
    }
#ifdef _DEBUG
    printf("close input file success\n");
#endif

    // end system
    ret = psf_finish();
    if (ret != 0) {
        fprintf(stderr, "Error %d: can not terminate the system.", ret);
        // deallocate spaces FIXME
        free(input_props);
        return ret;
    }
#ifdef _DEBUG
    printf("close system success\n");
#endif
    
    // deallocate spaces
    free(input_props);

    return 0;
}
