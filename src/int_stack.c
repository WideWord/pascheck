#include "int_stack.h"

#include <stdlib.h>

#define int_stack_t int_stack_t

int_stack_t* int_stack_create() {
	int_stack_t *int_stack = (int_stack_t*) malloc(sizeof(*int_stack));
	int_stack->front = NULL;
	return int_stack;
}

void int_stack_destroy(int_stack_t *int_stack) {
	while (!int_stack_empty(int_stack))
		int_stack_pop(int_stack);
	free(int_stack);
}

void int_stack_push(int_stack_t *int_stack, int data) {
	int_stack_node_t *node = (int_stack_node_t*) malloc(sizeof(*node));
	node->next = int_stack->front;
	node->data = data;
	int_stack->front = node;
}

int int_stack_pop(int_stack_t *int_stack) {
	int_stack_node_t *node = int_stack->front;
	int data = node->data;
	int_stack->front = node->next;
	free(node);
	return data;
}

int int_stack_empty(int_stack_t *int_stack) {
	return int_stack->front == NULL;
}
