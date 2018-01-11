#makefile for portsf
CFLAGS = -O2 -I ../include
CC=gcc

.PHONY:	clean veryclean
all:	libportsf.a

libportsf.a:	obj/ieee80.o obj/portsf.o
	ar -rc libportsf.a obj/ieee80.o obj/portsf.o
	ranlib libportsf.a
	mv libportsf.a lib

obj/ieee80.o:	src/ieee80.c src/ieee80.h
	$(CC) -c -O2 -o $@ $<

obj/portsf.o:	src/portsf.c inc/portsf.h src/ieee80.h
	$(CC) -c -O2 -o $@ -Iinc $<

clean:
	-rm -f obj/ieee80.o obj/portsf.o

veryclean: clean
	rm -f lib/libportsf.a

