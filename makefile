CC = gcc
DEBUG = -g
CFLAGS = -Wall -std=c99 -c
LFLAGS = -Wall -std=c99

raytrace : mainprog.o ppmformatter.o raycast.o
	$(CC) $(LFLAGS) mainprog.o ppmformatter.o raycast.o -o raytrace

mainprog.o : mainprog.c ppmformatter.h raycast.h
	$(CC) $(CFLAGS) mainprog.c

ppmformatter.o : ppmformatter.c ppmformatter.h raycast.h
	$(CC) $(CFLAGS) ppmformatter.c

raycast.o: raycast.c raycast.h
	$(CC) $(CFLAGS) raycast.c



clean:
	\rm *.o run