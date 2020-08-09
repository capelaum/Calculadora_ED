// Calculadora - header
//===================================================================================================
// Diretivas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#ifndef T1_C_H
#define T1_C_H
//===================================================================================================
//Structs da pilha de dados tipo float

typedef struct no{
	float dado;
	struct no* proximo;
}t_no;

typedef struct {
	t_no* primeiro;
	t_no* ultimo;

	int qtd;
}t_pilha;

//===================================================================================================
//                                 FUNCTIONS
//===================================================================================================
//  Pilha_func.c - Funcoes da pilha float

t_pilha* aloca_pilha     ();
t_no*    aloca_no        (float dado);

int      empilha         (float dado, t_pilha* pilha);

void     imprime_pilha   (t_pilha* pilha);
int      esta_vazia      (t_pilha* pilha);
void     apaga_pilha     (t_pilha* pilha);

//===================================================================================================
// - Pilha_func.c - Operacoes

int    verifica_pilha           (t_pilha* pilha);

float  desempilha_e_calcula_1   (char op, t_pilha* pilha);
float  desempilha_e_calcula_2   (char op, t_pilha* pilha); // utilizado no Algoritmo_3.c

int    remove_ultimo            (t_pilha* pilha);

//===================================================================================================
//- Valida_func.c - Vallidacao

bool valida_str   (char c);
bool tem_char     (char c);
bool tem_operador (char c);

int check         (char* str);

//===================================================================================================
// - Suporte_func.c - Suporte

int   copia_elemento (t_pilha* pilha);

void limpabuffer();

float str_em_float   (char* str);

//===================================================================================================

#endif //T1_C_H
