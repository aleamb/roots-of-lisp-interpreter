#ifndef _TYPES_H
#define _TYPES_H_

typedef enum _s_exp_type {
    ATOM,
    CONS
} S_EXP_TYPE;

typedef struct _s_exp {
    S_EXP_TYPE type;
    struct _s_exp* expr;
} S_EXP;

typedef struct _atom {
    char *name;
} TATOM;

typedef struct _cons {
    S_EXP* car;
    S_EXP* cdr;
} TCONS;

#endif /* _TYPES_H_ */
