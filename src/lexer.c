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
            while (((nc >= 'A' && nc <= 'z') || nc == '_' || (nc >= '0' && nc <= '9')) && ctr < 15) {
                buf[ctr++] = tolower(nc);
                nc = fgetc(stream);
            }
            token_t res = 0;
            if ((nc >= 'A' && nc <= 'z') || nc == '_' || (nc >= '0' && nc <= '9')) {
                while ((nc >= 'A' && nc <= 'z') || nc == '_' || (nc >= '0' && nc <= '9'))
                    nc = fgetc(stream);
            } else {
                buf[ctr] = 0;
                if (strcmp(buf, "begin") == 0) res = TOK_BEGIN;
                else if (strcmp(buf, "end") == 0) res = TOK_END;
            }
            ungetc(nc, stream);
            if (res == 0) continue;
            else return res;
        }

	}

}
