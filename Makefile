CC = gcc
CFLAGS = -g -Wall --std=c99
OBJECTS = main_lab6.o my_string.o

main: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o main
my_string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
main_lab6.o: main_lab6.c
	$(CC) $(CFLAGS) -c main_lab6.c -o main_lab6.o
clean:
	rm main $(OBJECTS)
