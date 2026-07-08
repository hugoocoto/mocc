#ifndef LEXER_H_
#define LEXER_H_

#include "tokens.h"

typedef struct Lexer {
        const char *YYCURSOR;
        const char *YYMARKER;
        const char *YYLIMIT;
        const char *tok;
        const char *linestart;
        int line;
} Lexer;

void lexer_init(Lexer *l, const char *src);
Token lexer_next(Lexer *l);

#endif // !LEXER_H_
