# executable
all : main.o serial.o
		gcc main.o serial.o -o gercomm
		
main.o : main.c serial.c
		gcc -c main.c -o main.o

serial.o : serial.c
		gcc -c serial.c -o serial.o

#clinterp.o : clinterp.c
#		gcc -c clinterp.c -o clinterp.o
