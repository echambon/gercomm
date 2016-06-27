#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "misc.h"
#include "task.h"

void task_init(Task *task, byte id, byte type, byte priority, char *content) {
	task->active = 1;
}
