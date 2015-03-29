#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "int_stack.h"

void failed() {
	printf("no\n");
	exit(0);
}

int main () {

    /* создаём стек */
	int_stack_t *int_stack = int_stack_create();

	while (1) {
        /* получаем лексему из лексера */
		token_t tok = get_token(stdin);
        
        /* выход из цикла если достигнут конец файла */
		if (tok == TOK_EOF) break;

        /* лексер может сообщить об ошибке, например не законченном комментарии */
		if (tok == TOK_ERR)
			failed();

        /* если лексема открывает состояние - протолкнём это состояние в стек */
		if (tok == '(' || tok == TOK_BEGIN) {
			int_stack_push(int_stack, tok);
			continue;
		}

        /* если лексема закрывает состояние, заберём из стека состояние и проверим корректность */
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

    /* если стек не пустой - существует незакрытое состояние */
	if (!int_stack_empty(int_stack)) {
		failed();
	}

	printf("yes\n");

	return 0;
}
