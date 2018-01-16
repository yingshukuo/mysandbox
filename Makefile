# Makefile
# by:   Ying-Shu Kuo
# what: Compile any .c files in this directory, also libportsf.
# how:  make / make [program-name] / make clean / make veryclean

.PHONY: all clean portsf
all: sinewave wavetable_synth portsf text2sf lowpass

sinewave:
	gcc -o sinewave sinewave.c

wavetable_synth:
	gcc -o wavetable_synth wavetable_synth.c

portsf:
	$(MAKE) -C portsf

text2sf: portsf
	gcc -lm -lportsf -Lportsf/lib -Iportsf/inc text2sf.c -o text2sf

lowpass: portsf
	gcc -lm -lportsf -Lportsf/lib -Iportsf/inc lowpass.c -o lowpass

clean:
	rm -f sinewave wavetable_synth text2sf lowpass
	$(MAKE) -C portsf clean

veryclean: clean
	$(MAKE) -C portsf veryclean

