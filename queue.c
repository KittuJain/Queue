#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue createQueue(void){
	LinkedList* list = calloc(sizeof(LinkedList), 1);
	Queue queue = {list, list->head, list->tail};
	return queue;
}