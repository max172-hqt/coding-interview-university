CC=gcc
# Look at the current directory for .h file
CFLAGS=-I.
DEPS = arrays.h
OBJ = main.o arrays.o

# $@: Left of the :
# $<: First in the dependency list (.c)
# $^: All object

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm main *.o
