PROG=main.exe
CC=gcc
CFLAGS=-g -Wall -Werror
DEPS = safeinput.h
OBJ = main.o safeinput.o
 
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
 
$(PROG): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)