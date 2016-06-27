#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include "target.h" 	// Target communication
#include "task.h" 		// Task to be executed by the target

// serial I/O in thread ?? -> pas forcément en fait, si, il faut un thread pour écouter (et envoyer)
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
#define MOTD					"gercomm v0.1 - CL manager for DFRobotShop Rover V2 control\nType help to view the documentation.\n"
#define SERIAL_TARGET_DEFAULT	"/dev/ttyACM0"
#define USERIN_BUFFER_LEN 		100
#define SLEEP_CST				100
#define TASK_STACK_SIZE			10 		// Maximum number of planned tasks

/**
 * Header
 **/
void quit(int*);
void motd();

void clinterp(int*,char*);

void *txthread_loop(void *arg);

/**
 * int main(void);
 * Main loop where program is initialized and user inputs are processed.
 **/
int main(void) {
	int 		loop = 1;
	char 		userin[USERIN_BUFFER_LEN];
	Target 		mytarget;
	Task 		mytasks[TASK_STACK_SIZE];
	pthread_t 	txthread;
	
	// Welcome message
	motd();
	
	// Initialize target structure
	target_init(&mytarget,SERIAL_TARGET_DEFAULT);
	
	// Initialize TX thread
	if(pthread_create(&txthread, NULL, txthread_loop, NULL) == -1) {
		perror("pthread_create");
		return EXIT_FAILURE;
    }
	
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
		usleep(SLEEP_CST*1000);
	}
	
	return EXIT_SUCCESS;
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
	} else if(strcmp(fname,"target") == 0) {
		// Target related functions
	} else {
		printf("?invalid command, type help for info\n");
	}
}

// TX thread
// manage task list and priorities here
void *txthread_loop(void *arg) {
	int txon = 1; //TODO: put this in the target structure
	(void) arg;
	
	// while loop and then: if txon
	while(txon) {
		//printf("bonjour\n");
		usleep(1000*1000);
	}
	
	pthread_exit(NULL);
}
