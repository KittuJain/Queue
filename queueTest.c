#include "queue.h"
#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_createQueue_creates_an_empty_queue (){
	Queue queue;
	queue = createQueue();
	assertEqual(queue.list->count, 0);
	assert(queue.front == 0);
	assert(queue.rear == 0);
	free(queue.list);
}