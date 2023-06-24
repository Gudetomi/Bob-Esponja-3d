CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lGL -lGLU -lglut -lm

.PHONY: all clean

all: bob

bob: bob_func.o bob_draw.o bob_esponja.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

bob_func.o: bob_func.c bob.h
	$(CC) $(CFLAGS) -c $< -o $@

bob_draw.o: bob_draw.c bob.h
	$(CC) $(CFLAGS) -c $< -o $@

bob_esponja.o: bob_esponja.c bob.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f bob_func.o bob_draw.o bob_esponja.o bob