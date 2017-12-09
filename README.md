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
* portsf
    - some detail
        * In line 1592 of portsf.c, it does not handle overflow issue.
          Precisely, ```fsamp``` is bounded between ```-1.0f``` and ```1.0f```.
          Then ```ssamp = (short) psf_round(fsamp * 32768);``` makes it ```32768.0f```
          before casting ```short```. OVERFLOW!

## Notes
* Check out https://github.com/andrewrk/libsoundio if some real-time audio I/O
  is needed.

