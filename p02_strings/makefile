CC = g++
CFLAGS = -I -Weffc++ -Wall
DEPS = alphabet_class.h word_class.h
OBJ = main_strings.o alphabet_class.o word_class.o

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main_strings: $(OBJ)
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm -rf *.o 