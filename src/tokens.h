#ifndef TOKENS_H_
#define TOKENS_H_

#include <stdlib.h>

#include "ast.h"

typedef struct {
        int type;
        const char *start;
        int len;
        int line;
        char *text;
        long ival;
} Token;

typedef struct {
        Node *root;
        int had_error;
} ParseState;

void token_print(Token t);

#endif // TOKENS_H_
