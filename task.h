#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "misc.h"

#define TASK_BUFFER_LEN 256

// Priorities
#define PRIORITY_SYSTEM 255
#define PRIORITY_HIGH	2
#define PRIORITY_MEDIUM	1
#define PRIORITY_LOW 	0

// Types
#define	TASK_ABORT 		0
#define TASK_PING		1

/**
 * struct Target
 * Basic structure for task management.
 **/
typedef struct Task Task;
struct Task {
	byte id;
	byte type;
	byte priority;
	byte active; 					// While not answered, keep the task active, waiting for an answer
	char content[TASK_BUFFER_LEN];
};

// Prototypes
void task_init(Task*, byte, byte, byte, char*);
