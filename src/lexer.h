#ifndef _LEXER_H_
#define _LEXER_H_

#include <stdio.h>

typedef int token_t;

token_t get_token(FILE *stream);

#define TOK_EOF    256
#define TOK_BEGIN  257
#define TOK_END    258
#define TOK_ERR    259

#endif
