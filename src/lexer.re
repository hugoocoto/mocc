// vim: ft=c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cum.h"
#include "lexer.h"
#include "tokens.h"

void
lexer_init(Lexer *l, const char *src)
{
        l->YYCURSOR = src;
        l->YYMARKER = src;
        l->YYLIMIT = src + strlen(src) + 1;
        l->tok = src;
        l->linestart = src;
        l->line = 1;
}

Token
lexer_next(Lexer *l)
{
#define YYCURSOR l->YYCURSOR
#define YYMARKER l->YYMARKER
#define YYLIMIT l->YYLIMIT

        Token t = { 0 };
loop:
        l->tok = YYCURSOR;
        /*!re2c
        re2c:define:YYCTYPE = int;
        re2c:yyfill:enable  = 0;
        re2c:eof            = 0;

        WS = [ \f\v\t\r]+;
        NL = "\n";
        ID = [a-zA-Z_][a-zA-Z0-9_]*;
        INT = [0-9]+;

        WS                  { goto loop; } // WHITESPACE
        NL                  { l->line++; l->linestart = YYCURSOR; goto loop; } // NEWLINE
        "//" [^\n\x00]*     { goto loop; } // COMMENT

        // I have to fill t somehow
        $ | "\x00"          { return t; } // EOF
        "int"               { return t; }
        *                   { return t; }
     */
#undef YYCURSOR
#undef YYMARKER
#undef YYLIMIT

        Todo("Unreachable\n");
        return t;
}
