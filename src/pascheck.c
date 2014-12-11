#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "int_stack.h"

void failed() {
	printf("no\n");
	exit(0);
}

int main () {

	int_stack_t *int_stack = int_stack_create();

	while (1) {
		token_t tok = get_token(stdin);
		if (tok == TOK_EOF) break;

		if (tok == TOK_ERR)
			failed();

		if (tok == '(' || tok == TOK_BEGIN) {
			int_stack_push(int_stack, tok);
			continue;
		}

		if (tok == ')') {
			if (int_stack_empty(int_stack))
				failed();
			if ('(' != (int)int_stack_pop(int_stack))
				failed();
		}

		if (tok == TOK_END) {
			if (int_stack_empty(int_stack))
				failed();
			if (TOK_BEGIN != int_stack_pop(int_stack))
				failed();
		}
	}

	if (!int_stack_empty(int_stack)) {
		failed();
	}

	printf("yes\n");

	return 0;
}
