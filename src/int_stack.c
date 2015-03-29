#include "int_stack.h"

#include <stdlib.h>

#define int_stack_t int_stack_t

int_stack_t* int_stack_create() {
    /* выделяем память под структуру стека */
	int_stack_t *int_stack = (int_stack_t*) malloc(sizeof(*int_stack));
    /* инициализируем стек */
	int_stack->front = NULL;
	return int_stack;
}

void int_stack_destroy(int_stack_t *int_stack) {
    /* удаляем все элементы из стека */
	while (!int_stack_empty(int_stack))
		int_stack_pop(int_stack);
    /* освобождаем структуру стека */
	free(int_stack);
}

void int_stack_push(int_stack_t *int_stack, int data) {
    /* выделяем память под элемент стека */
	int_stack_node_t *node = (int_stack_node_t*) malloc(sizeof(*node));
    /* заполняем поля структуры */
	node->next = int_stack->front;
	node->data = data;
	int_stack->front = node;
}

int int_stack_pop(int_stack_t *int_stack) {
    /* получаем элемент на вершине */
	int_stack_node_t *node = int_stack->front;
	int data = node->data;
	int_stack->front = node->next;
    /* освобождаем память */
	free(node);
	return data;
}

int int_stack_empty(int_stack_t *int_stack) {
    /* проверяем отсутствие элементов в стеке */
	return int_stack->front == NULL;
}
