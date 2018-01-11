# Makefile
# by:   Ying-Shu Kuo
# what: Compile any .c files in this directory, also libportsf.
# how:  make / make [program-name] / make clean / make veryclean

.PHONY: all clean portsf
all: sinewave wavetable_synth portsf text2sf

sinewave:
	gcc -o sinewave sinewave.c

wavetable_synth:
	gcc -o wavetable_synth wavetable_synth.c

portsf:
	$(MAKE) -C portsf

text2sf: portsf
	gcc -lm -lportsf -Lportsf/lib -Iportsf/inc text2sf.c -o text2sf

clean:
	rm -f sinewave wavetable_synth text2sf
	$(MAKE) -C portsf clean

veryclean: clean
	$(MAKE) -C portsf veryclean

