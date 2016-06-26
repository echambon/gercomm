# executable
all : main.o target.o
		gcc main.o target.o -o gercomm -lpthread
		
main.o : main.c target.c
		gcc -c main.c -o main.o

target.o : target.c
		gcc -c target.c -o target.o

#clinterp.o : clinterp.c
#		gcc -c clinterp.c -o clinterp.o
