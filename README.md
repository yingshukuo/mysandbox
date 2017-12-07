# mysandbox

## list of code
* sinewave.c
    - what
        * This program aims to print out sine wave in text form.
          Given the frequency, duration of the sine wave with the sampling rate,
          A stream of values will be printed out to stdout.
    - how
        * gcc -o sinewave sinewave.c
* wavetable_synth.c
    - what
        * This progarm serves as a demonstration of a very simple implementation
          of wavetable synthesis. Wavetable synthesis is essentially gluing the 
          same clip again and again. A very simple example would be a 1-cycle
          sine wave: gluing 5 1-cycle sine wave together will make it a 5-cycle
          sine wave.
    - how
        * gcc -o wavetable_synth wavetable_synth.c

