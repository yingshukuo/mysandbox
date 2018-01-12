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
    - what
        * This library aims to convert values to audio format.
    - some detail
        * In line 1592 of portsf.c, it does not handle overflow issue.
          Precisely, ```fsamp``` is bounded between ```-1.0f``` and ```1.0f```.
          Then ```ssamp = (short) psf_round(fsamp * 32768);``` makes it ```32768.0f```
          before casting ```short```. OVERFLOW!
        * Workaround: limit the maximum numbe to be less than 1.
          16 bit: ```fsamp = min(fsamp,0.99997f);```
          24 bit: ```fsamp = min(fsamp,0.99999995f);```
          32 bit: ```fsamp = min(fsamp,0.9999999996f);```
* text2sf
    - what
        * This program converts a list of string digits to a .wav file.
          With the help of libportsf.
    - how
        * gcc -lm -lportsf -Lportsf/lib -Iportsf/inc text2sf.c -o text2sf

## Annoying Issue
* vim-autoformat
    - I know it has nothing to do with this project, but I want to make it work
      smoothly. Now the main issue comes to the time when I load text2sf.c, it
      shows up the error on the line of #include <portsf.h>, whining that it
      can not find the portsf.h in its default library search path.
    - There are a couple of things to do to solve this issue.
        1. How do I know which C formatter is it using? astyle? clang-format?
           I checked ~/.vim/bundle/vim-autoformat/plugin/*.vim, and I got no
           clue so far.
        2. How do I manually set the library path only for text2sf.c, after I
           figured out which formatter I am using? I don't want to mess up with
           global library search path like PATH=$PATH:/blah/blah.
        3. Would be great to know how to fully control vim-autoformat. I don't
           even know how to peek those variables it sets, or how vim runs .vim
           files.

## Notes
* Check out https://github.com/andrewrk/libsoundio if some real-time audio I/O
  is needed.

