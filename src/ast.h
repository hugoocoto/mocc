#ifndef AST_H_
#define AST_H_

#include "preproc.h"

#define LIST_OF_NODE_KINDS() \
        NODE(PROGRAM, program, Node *, statements)

typedef enum {
        NODE_INVALID = 0,
/*   */ #define NODE(x, n, ...) NODE_##x,
        LIST_OF_NODE_KINDS()
/*   */ #undef NODE
} NodeKind;

typedef struct Node Node;
struct Node {
        NodeKind kind;
        union {
#define NODE(x, n, ...)                    \
        struct {                           \
                JOIN_PAIR(;, __VA_ARGS__); \
        } n;
                LIST_OF_NODE_KINDS()
#undef NODE
        } as;
};

Node *node_new(NodeKind kind);
void node_free(Node *node);

char *nodekind_repr(NodeKind);

#define NODE(x, n, ...) Node *node_new_##n(JOIN_PAIR_COMMA(__VA_ARGS__));
LIST_OF_NODE_KINDS()
#undef NODE

typedef void (*AstWalkFn)(const Node *node, int depth, void *ctx);
void ast_walk(const Node *node, AstWalkFn walk_fn, void *ctx);

void ast_print(const Node *root);

#endif // !AST_H_
