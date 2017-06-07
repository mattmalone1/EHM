CC = gcc
CFLAGS = -g -Wall --std=c99
OBJECTS = main.o my_string.o

my_string: $(OBJECTS)
	$(CC) $(CFLAGS) -o my_string $(OBJECTS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
my_string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
clean:
	rm my_string $(OBJECTS)
