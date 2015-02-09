#include "queue.h"
#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_createQueue_creates_an_empty_queue (){
	Queue queue = createQueue();
	assertEqual(queue.list->count, 0);
	assert(queue.front == 0);
	assert(queue.rear == 0);
	free(queue.list);
}

void test_enqueue_inserts_a_new_element_in_queue (){
	Queue queue = createQueue();
	int data = 10;
	assertEqual(enqueue(&queue, (void*)&data),1);
	assertEqual(*(int*)(queue.front->data), 10);
	assertEqual(*(int*)(queue.rear->data), 10);
	free(queue.list);
}

void test_enqueue_inserts_a_two_new_elements_in_queue (){
	Queue queue = createQueue();
	int data1 = 10, data2 = 20;
	assertEqual(enqueue(&queue, (void*)&data1),1);
	assertEqual(enqueue(&queue, (void*)&data2),2);
	assertEqual(*(int*)(queue.front->data), 10);
	assertEqual(*(int*)(queue.rear->data), 20);
	free(queue.list);
}


void test_enqueue_inserts_a_new_element_of_float_type_in_queue (){
	Queue queue = createQueue();
	float data = 10.98;
	assertEqual(enqueue(&queue, (void*)&data),1);
	assertEqual(*(float*)(queue.front->data), (float)10.98);
	assertEqual(*(float*)(queue.rear->data), (float)10.98);
	free(queue.list);
}

void test_enqueue_inserts_a_two_new_elements_of_float_type_in_queue (){
	Queue queue = createQueue();
	float data1 = 10.45, data2 = 20.12;
	assertEqual(enqueue(&queue, (void*)&data1),1);
	assertEqual(enqueue(&queue, (void*)&data2),2);
	assertEqual(*(float*)(queue.front->data), (float)10.45);
	assertEqual(*(float*)(queue.rear->data), (float)20.12);
	free(queue.list);
}

void test_enqueue_populates_queue_with_two_char_elements (){
	Queue queue = createQueue();
	char data1 = 'k', data2 = 'r';
	assertEqual(enqueue(&queue, (void*)&data1),1);
	assertEqual(enqueue(&queue, (void*)&data2),2);
	assertEqual(*(char*)(queue.front->data), 'k');
	assertEqual(*(char*)(queue.rear->data), 'r');
	free(queue.list);
}

void test_enqueue_populates_queue_with_three_char_elements (){
	Queue queue = createQueue();
	char data1 = 'k', data2 = 'a', data3 = 'r';
	assertEqual(enqueue(&queue, (void*)&data1),1);
	assertEqual(enqueue(&queue, (void*)&data2),2);
	assertEqual(enqueue(&queue, (void*)&data3),3);
	assertEqual(*(char*)(queue.front->data), 'k');
	assertEqual(*(char*)(queue.rear->data), 'r');
	free(queue.list);
}

void test_enqueue_populates_queue_with_two_string_elements (){
	Queue queue = createQueue();
	String data1 = "Krati";
	String data2 = "Jain";
	assertEqual(enqueue(&queue, (void*)&data1),1);
	assertEqual(enqueue(&queue, (void*)&data2),2);
	assertEqual(strcmp(*(String*)(queue.front->data), "Krati"),0);
	assertEqual(strcmp(*(String*)(queue.rear->data), "Jain"),0);
	free(queue.list);
}

void test_dequeue_deletes_the_front_most_element_of_queue (){
	Queue queue = createQueue();
	int data1 = 10, data2 = 20;
	enqueue(&queue, (void*)&data1);
	enqueue(&queue, (void*)&data2);
	assertEqual(*(int*)dequeue(&queue),10);
	assertEqual(queue.list->count, 1);
	free(queue.list);
}

void test_dequeue_deletes_two_front_most_element_of_queue (){
	Queue queue = createQueue();
	int data1 = 10, data2 = 20, data3 = 30;
	enqueue(&queue, (void*)&data1);
	enqueue(&queue, (void*)&data2);
	enqueue(&queue, (void*)&data3);
	assertEqual(*(int*)dequeue(&queue),10);
	assertEqual(queue.list->count, 2);
	assertEqual(*(int*)dequeue(&queue),20);
	assertEqual(queue.list->count, 1);
	free(queue.list);
}