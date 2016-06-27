# executable
all : main.o target.o task.o
		gcc main.o target.o task.o -o gercomm -lpthread
		
main.o : main.c target.c task.c
		gcc -c main.c -o main.o

target.o : target.c target.h
		gcc -c target.c -o target.o
		
task.o : task.c task.h misc.h
		gcc -c task.c -o task.o
