#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "target.h"

void target_init(Target* target, char* location) {
	strcpy(target->location, location);
	
	printf("!target initialized at %s\n",location);
}

