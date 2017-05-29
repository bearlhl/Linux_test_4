main:main.o sort.o
	gcc main.o sort.o -o main
main.o:main.c
	gcc -c main.c
sort.o:sort.c
	gcc -c sort.c

clean:
	rm main *.o
