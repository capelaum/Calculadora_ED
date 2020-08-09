
#include "Calculadora.h"

// Fun��es da pilha
//===============================================================
// ALOCA��O
//===============================================================
// Aloca pilha de dados tipo float
t_pilha *aloca_pilha()
{
	t_pilha *ptr = (t_pilha *)malloc(sizeof(t_pilha));

	ptr->primeiro = NULL;
	ptr->ultimo = NULL;
	ptr->qtd = 0;

	return ptr;
}
// Aloca os nos da pilha float
t_no *aloca_no(float dado)
{
	t_no *novo = (t_no *)malloc(sizeof(t_no));

	if (!novo)
	{
		printf("numero nao alocado!\n");
		return false;
	}

	novo->dado = dado;
	novo->proximo = NULL;

	return novo;
}
//===============================================================
// Empilha os operandos na pilha float
int empilha(float dado, t_pilha *pilha)
{

	if (!pilha)
	{
		printf("pilha nao alocada!\n");
		return false;
	}

	t_no *ptr = aloca_no(dado);

	if (ptr == NULL)
		return false;

	if (esta_vazia(pilha))
	{
		pilha->primeiro = ptr;
	}
	else
	{
		pilha->ultimo->proximo = ptr;
	}

	pilha->ultimo = ptr;
	pilha->qtd++;
	return true;
}
//IMPRIME / VAZIA / APAGA
//===============================================================
// Imprime a pilha float - usada no Modo Calculadora(2) a cada loop do-while
void imprime_pilha(t_pilha *pilha)
{
	t_no *ptr = pilha->primeiro;

	if (esta_vazia(pilha))
		return;

	int cont = pilha->qtd;
	while (ptr != NULL)
	{
		printf("%d. %.4f \n", cont--, ptr->dado); // Imprimindo certo
		ptr = ptr->proximo;
	}
}

// Retorna true se pilha estiver vazia e false caso contrario
int esta_vazia(t_pilha *pilha)
{
	return (pilha->primeiro == NULL && pilha->ultimo == NULL);
}

// Apaga todos dados da pilha float
void apaga_pilha(t_pilha *pilha)
{
	t_no *ptr = pilha->primeiro;

	while (ptr)
	{
		pilha->primeiro = pilha->primeiro->proximo;
		free(ptr);
		ptr = pilha->primeiro;
	}
	free(pilha);
}

//===============================================================
//********************PILHA FLOAT OPERACOES**********************
//===============================================================

// Verifica se possui 2 ou mais numeros na pilha, usado no Menu.c-Modo Calculadora(2) e Algoritmo_3.c
int verifica_pilha(t_pilha *pilha)
{
	if (pilha->qtd >= 2)
	{
		return true;
	}
	else
	{
		printf("\n----->Numero de operandos insuficiente<-----\n\n");
		return false;
	}
}

// Desempilha 2 ultimos numeros float da pilha e faz opera��o dada, sendo o antepenultimo valor o primeiro operando nos casos ( - e / )
float desempilha_e_calcula_1(char op, t_pilha *pilha)
{ // Usada no modo (2) - Calculadora

	float x1;
	float x2;

	if (!pilha)
	{
		printf("Pilha nao alocada!\n");
		return false;
	}

	if (esta_vazia(pilha))
	{
		return false;
	}

	t_no *ptr = pilha->primeiro;

	if (!ptr)
		return false;

	if (pilha->primeiro == pilha->ultimo)
	{ //unico elemento
		printf("Opera��o inv�lida -> unico elemento\n");
		return false;
	}
	else
	{

		while (ptr->proximo != pilha->ultimo)
			ptr = ptr->proximo;

		x1 = ptr->proximo->dado;
		x2 = ptr->dado;
	}

	float x; //Recebe resultado da opera��o
	switch (op)
	{
	case '+':
		x = x1 + x2;
		break;
	case '-':
		x = x2 - x1;
		break;
	case '*':
		x = x1 * x2;
		break;
	case '/':
		x = x2 / x1;
		break;

	default:
		return false;
	}

	//Remove 2 ultimos
	remove_ultimo(pilha);
	remove_ultimo(pilha);
	return x;
}

// Desempilha 2 ultimos numeros float da pilha e faz opera��o dada, sendo o antepenultimo valor o segundo operando nos casos ( - e / )
float desempilha_e_calcula_2(char op, t_pilha *pilha)
{ // Usada no Modo (1) - Resolucao de Expressao - no Algoritmo_3.c

	float x1;
	float x2;

	if (!pilha)
	{
		printf("Pilha nao alocada!\n");
		return false;
	}

	if (esta_vazia(pilha))
	{
		return false;
	}

	t_no *ptr = pilha->primeiro;

	if (!ptr)
		return false;

	if (pilha->primeiro == pilha->ultimo)
	{ // unico elemento
		printf("Opera��o inv�lida -> unico elemento\n");
		return false;
	}
	else
	{

		while (ptr->proximo != pilha->ultimo)
			ptr = ptr->proximo;

		x1 = ptr->proximo->dado;
		x2 = ptr->dado;
	}

	float x; // Recebe resultado da opera��o
	switch (op)
	{
	case '+':
		x = x1 + x2;
		break;
	case '-':
		x = x1 - x2; // diferente do desempilha_e_calcula_1
		break;
	case '*':
		x = x1 * x2;
		break;
	case '/':
		x = x1 / x2; // diferente do desempilha_e_calcula_1
		break;

	default:
		return false;
	}

	//Remove 2 ultimos nos
	remove_ultimo(pilha);
	remove_ultimo(pilha);
	return x;
}
//===============================================================
// Funcao que remove o ultimo no da pilha, usado em ambas funcoes de desempilhar
int remove_ultimo(t_pilha *pilha)
{

	if (!pilha)
	{
		printf("Pilha nao alocada!\n");
		return false;
	}

	if (esta_vazia(pilha))
	{
		return false;
	}

	t_no *ptr = pilha->primeiro;

	if (!ptr)
		return false;

	if (pilha->primeiro == pilha->ultimo)
	{ //unico elemento
		pilha->primeiro = NULL;
		pilha->ultimo = NULL;
		free(ptr);
	}
	else
	{
		while (ptr->proximo != pilha->ultimo)
			ptr = ptr->proximo;

		ptr->proximo = pilha->ultimo->proximo;
		pilha->ultimo = ptr;
	}

	pilha->qtd--;

	return true;
}
//===============================================================
