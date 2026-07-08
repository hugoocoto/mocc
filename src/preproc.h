#include "cum.h"

#define JOIN1_PAIR(op, a, b, ...) a b __VA_OPT__(op OBSTRUCT(JOIN_PAIR_INDIRECT)()(op, __VA_ARGS__))
#define JOIN_PAIR_INDIRECT() JOIN1_PAIR
// join a,b,c,d, ... like a b OP c d OP ...
#define JOIN_PAIR(op, ...) __VA_OPT__(EVAL(JOIN1_PAIR(op, __VA_ARGS__)))

#define JOIN1_PAIR_COMMA(a, b, ...) a b __VA_OPT__(, OBSTRUCT(JOIN_PAIR_COMMA_INDIRECT)()(__VA_ARGS__))
#define JOIN_PAIR_COMMA_INDIRECT() JOIN1_PAIR_COMMA
// join a,b,c,d, ... like a b , c d , ...
#define JOIN_PAIR_COMMA(...) __VA_OPT__(EVAL(JOIN1_PAIR_COMMA(__VA_ARGS__)))

// clang-format off
#define ASSIGN1(_n_, _, _v, ...) node->as._n_._v = _v; __VA_OPT__(OBSTRUCT(ASSIGN_INDIRECT)()(_n_, __VA_ARGS__))
// clang-format on
#define ASSIGN_INDIRECT() ASSIGN1
#define ASSIGN_ALL(_n_, ...) __VA_OPT__(EVAL(ASSIGN1(_n_, __VA_ARGS__)))

// similar by join by comma but sing node as 'y', ignoring type 't'
#define NODE_VAL1(_n_, t, _v, ...) node->as._n_._v __VA_OPT__(, OBSTRUCT(NODE_VAL_INDIRECT)()(_n_, __VA_ARGS__))
#define NODE_VAL_INDIRECT() NODE_VAL1
#define NODE_VAL(_n_, ...) __VA_OPT__(EVAL(NODE_VAL1(_n_, __VA_ARGS__)))
