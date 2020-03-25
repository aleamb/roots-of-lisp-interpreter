#include "rol.h"
#include <stdlib.h>
#include <string.h>


S_EXP* T;
S_EXP* NIL;
S_EXP* env;

S_EXP* rol_make_atom_from_string(const char* name) {

  if (strcmpi(name, "NIL") == 0) return NIL;

  TATOM *atom = (TATOM*)malloc(sizeof(TATOM)); 
  S_EXP *s_expr = (S_EXP*)malloc(sizeof(S_EXP));

  atom->name = strdup(name);

  s_expr->type = ATOM;
  s_expr->expr = atom;
  return s_expr;
}

S_EXP* rol_make_cons(S_EXP* car, S_EXP* cdr)  {
  TCONS *cons = (TCONS*)malloc(sizeof(TCONS));
  S_EXP *s_expr = (S_EXP*)malloc(sizeof(S_EXP));
  
  s_expr->type = CONS;
  s_expr->expr = cons;
  cons->car = car;
  cons->cdr = cdr;

  return s_expr;
}

void rol_set_cdr(S_EXP* current, S_EXP* cdr) {
    ((TCONS*)(current->expr))->cdr = cdr;
}

char* rol_get_atom_name(S_EXP* atom) {
  if (atom->type == ATOM) {
    return ((TATOM*)atom->expr)->name;
  }
  return NULL;
}

int rol_nil(S_EXP* s_expr) {
  return (s_expr == NULL || s_expr->expr == NULL || s_expr == NIL || rol_empty_list(s_expr) );
}

int rol_t(S_EXP* s_expr) {
  return (s_expr != NULL && s_expr->expr != NULL && s_expr == T || !rol_empty_list(s_expr) );
}

int rol_is_atom(S_EXP* s_exp) {
  return s_exp->type == ATOM;
}

int rol_is_cons(S_EXP* s_exp) {
  return s_exp->type == CONS;
}

int rol_empty_list(S_EXP* s_expr) {
  return ( s_expr->type != ATOM && ((TCONS*)s_expr->expr)->car == NULL && ((TCONS*)s_expr->expr)->cdr == NULL );
}

S_EXP* rol_get_car(S_EXP* s_exp) {
  return ((TCONS*)(s_exp->expr))->car;
}

S_EXP* rol_get_cdr(S_EXP* s_exp) {
  return ((TCONS*)(s_exp->expr))->cdr;
}
