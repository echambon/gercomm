#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "serial.h" 	// Serial communication

// serial I/O in thread ?? -> pas forcément en fait
// user I/O in main thread, commands are sent over serial by the thread which reads the commands
// développer un sous-programme pour le contrôle du robot avec les flèches directionnelles
// suivi de path gps
// détection d'obstacle
// cartographie de zone
// utiliser SDL pour l'affichage

// first test: change the value of a variable on the arduino!!

/**
 * Constants
 **/
#define MOTD				"gercomm v0.1 - CL manager for DFRobotShop Rover V2 control\nType help to view the documentation.\n"
#define SERIAL_TARGET 		"/dev/ttyACM0"
#define USERIN_BUFFER_LEN 	100
#define SLEEP_CST			100

/**
 * Header
 **/
void quit(int*);
void motd();

void clinterp(int*,char*);

/**
 * int main(void);
 * Main loop where program is initialized and user inputs are processed.
 **/
int main(void) {
	int 	loop = 1;
	char 	userin[USERIN_BUFFER_LEN];
	
	// Welcome message
	motd();
	
	while(loop) {
		// Wait for user input
		printf(">");
		if(scanf("%s",userin) != 1)
			break;
			
		// Print user input (debug)
		//printf("%s\n",userin);
		
		// Process user input
		
		// Debug zone
		clinterp(&loop,userin);
		//quit(&loop);
		
		// Sleep for 100ms
		usleep(SLEEP_CST);
	}
	
	return 0;
}

// Application functions
/**
 * void quit(int*);
 * Quit program.
 **/
void quit(int* loop) {
	(*loop) = 0;
}

/**
 * void motd();
 * Welcome message.
 **/
void motd() {
	printf(MOTD);
}

// Interpreter
/**
 * void clinterp(char*)
 * Command Line Parameters
 **/
void clinterp(int* loop,char* uinput) {
	char* fname = strsep(&uinput," ");
	
	if(strcmp(fname,"quit") == 0) {
		quit(loop);
	} else if(strcmp(fname,"motd") == 0) {
		motd();
	} else {
		printf("!Invalid command, type help for info.\n");
	}
}
