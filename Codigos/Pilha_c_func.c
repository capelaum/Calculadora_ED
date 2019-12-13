
// Funcoes da Resolucao de expressao (Modo 1)

#include "Res_exp.h"

//  ALOCACAO
//================================================================
// Aloca pilha de dados tipo char 
t_pilha_c* aloca_pilha_c(){                                                                             
	t_pilha_c* ptr = (t_pilha_c*) malloc(sizeof(t_pilha_c));
	
	ptr->primeiro = NULL;
	ptr->ultimo = NULL;
	ptr->qtd = 0;
	
	return ptr;
}

// Aloca os nos da pilha char
t_no_c* aloca_no_c (char dado){
	t_no_c* novo = (t_no_c*) malloc(sizeof(t_no_c));
	
	if(!novo){
		printf("\nERRO\n");
		return false;
	}
	
	novo->dado    = dado;
	novo->proximo = NULL;
	
	return novo;
}

// Empilha / Desempilha
//================================================================
// Empilha o dado tipo char na pilha no topo da pilha
int empilha_c (char dado, t_pilha_c* pilha_c){
	
	if(!pilha_c){
		printf("Pilha nao alocada!\n");
		return false;
	}
	
	t_no_c* ptr = aloca_no_c(dado);
	
	if(!ptr)
		return false;
		
	
	if(esta_vazia_c(pilha_c)){
		pilha_c->primeiro = ptr;
	}else{
		pilha_c->ultimo->proximo = ptr;	
	}
	
	pilha_c->ultimo = ptr;
	pilha_c->qtd++;
	return true;
}

//Desempilha elemento char do topo e retorna-o 
char desempilha_c (t_pilha_c* pilha_c){
	
	if(!pilha_c){
		printf("Pilha nao alocada!\n");
		return false;
	}
	
	if(esta_vazia_c(pilha_c)){
		return false;
	}
	
	char c = pilha_c->ultimo->dado;
	
	t_no_c* ptr = pilha_c->primeiro;
	
	
	if(!ptr)
		return false;
		
	if (pilha_c->primeiro == pilha_c->ultimo){ //unico elemento
			pilha_c->primeiro = NULL;
			pilha_c->ultimo   = NULL;
			free(ptr);
	}else{
		
		while( ptr->proximo != pilha_c->ultimo)
			ptr = ptr->proximo;
		
		ptr->proximo  = pilha_c->ultimo->proximo;
		pilha_c->ultimo = ptr;
	}
	
	
	pilha_c->qtd--;	
	return c;
}

// VAZIA / APAGA
//===============================================================
// Retorna true se pilha estiver vazia e false caso contrario
int esta_vazia_c (t_pilha_c* pilha_c){
	return (pilha_c->primeiro == NULL && pilha_c->ultimo == NULL);
}

// Apaga todos dados da pilha char
void apaga_pilha_c (t_pilha_c* pilha_c){
	t_no_c* ptr = pilha_c->primeiro;
	
	while(ptr){
		pilha_c->primeiro = pilha_c->primeiro->proximo;
		free(ptr);
		ptr = pilha_c->primeiro;
	}
	free(pilha_c);
}

