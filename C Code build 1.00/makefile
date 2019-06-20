CC = gcc

output: main.o myfunctions.o
	$(CC) main.o myfunctions.o -o marslog
main.o: main.c
	$(CC) -c main.c
myfunctions.o: myfunctions.c
	$(CC) -c myfunctions.c
clean:
	rm *.o marslog