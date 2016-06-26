#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TARGET_BUFFER_LEN 500

/**
 * struct Target
 * Basic structure for serial communication.
 **/
typedef struct Target Target;
struct Target {
	char location[20];
	char buffer_send[TARGET_BUFFER_LEN];
	char buffer_recv[TARGET_BUFFER_LEN];
};

// Functions
void target_init(Target*, char*);
