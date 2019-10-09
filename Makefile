num : numberCross.o
	gcc -o num numberCross.o

numberCross.o : numberCross.c
	gcc -c -o numberCross.o numberCross.c

clean :
	rm *.o num
