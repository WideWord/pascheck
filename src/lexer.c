#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

token_t get_token(FILE *stream) {

	int ctr = 0;
	char buf[16];

	while (1) {

        /* получим следующий символ из стека */
		int nc = fgetc(stream);

        /* если символ пробельный - пропустим его */
		if (nc == ' ' || nc == '\t' || nc == '\n')
			continue;

        /* обработка строк */
		if (nc == '\'') {
			while (1) {
				nc = fgetc(stream);
				if (nc == EOF)
					return TOK_ERR;
				if (nc == '\'') break;
				else if (nc == '\\') {
					nc = fgetc(stream);
					if (nc == EOF)
						return TOK_ERR;
				}
			}
			continue;
		}

        /* обработка комментариев */
		if (nc == '}')
			return TOK_ERR;

		if (nc == '{') {
			while (1) {
				nc = fgetc(stream);
				if (nc == EOF)
					return TOK_ERR;
				if (nc == '}')
					break;
			}
			continue;
		}

        /* обработка конца потока */
		if (nc == EOF)
			return TOK_EOF;

        /* обработка скобок */
		if (nc == '(' || nc == ')')
			return nc;

        /* обработка begin/end */
		if ((nc >= 'A' && nc <= 'z') || nc == '_' || (nc >= '0' && nc <= '9')) {
			if (ctr < 15) {
				buf[ctr++] = tolower(nc);
				buf[ctr] = 0;
				if (strcmp(buf, "begin") == 0)
					return TOK_BEGIN;
				if (strcmp(buf, "end") == 0)
					return TOK_END;
			}
		} else {
			ctr = 0;
		}

	}

}
