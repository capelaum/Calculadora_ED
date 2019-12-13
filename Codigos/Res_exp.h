// Resolucao de expressao - header
//===================================================================================================
//Diretivas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#ifndef T1_R_H
#define T1_R_H

//===================================================================================================
// Structs - Pilha de dados tipo char
typedef struct no_c{
	char dado;
	struct no_c* proximo;
}t_no_c;

typedef struct {
	t_no_c* primeiro;
	t_no_c* ultimo;

	int qtd;
}t_pilha_c;
//===================================================================================================
//                                 FUNCTIONS
//===================================================================================================
// - Pilha_c_func.c - Funcoes da pilha char

t_pilha_c* aloca_pilha_c ();
t_no_c*    aloca_no_c    (char dado);

int  esta_vazia_c        (t_pilha_c* pilha_c);
void apaga_pilha_c       (t_pilha_c* pilha_c);


int  empilha_c          (char dado, t_pilha_c* pilha_c);
char desempilha_c       (t_pilha_c* pilha_c);

//===============================================================
// - Valida_exp_func.c - Validacao

bool valida_str_1    (char c);
bool tem_numero      (char c);
bool tem_escopo      (char c);
bool tem_op          (char c);

int  check_exp       (char *str); 

//===============================================================

/* Algoritmo_1.c - Valida os escopos da string de entrada */
int  valida_escopo   (char* str, t_pilha_c* pilha_c);

/* Algoritmo_2.c - Transforma a expressao infixa em posfixa */
int  precedencia     (char c);
void transforma      (char* exp_infixa, char* exp_posfixa);

/* Algoritmo_3.c - Resolve a expressao posfixa dada */
float resolve_posfixa(char* str);

//===================================================================================================
#endif // end T1_R_H
