#ifndef _int_stack_H_
#define _int_stack_H_

typedef struct {
	void *next;
	int data;
} int_stack_node_t;

typedef struct {
	int_stack_node_t *front;
} int_stack_t;

int_stack_t *int_stack_create();
void int_stack_destroy(int_stack_t *int_stack);
void int_stack_push(int_stack_t *int_stack, int value);
int int_stack_pop(int_stack_t *int_stack);
int int_stack_empty(int_stack_t *int_stack);

#endif
