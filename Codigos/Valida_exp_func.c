
#include "Res_exp.h"

// Funcoes de validacao do Modo (1) - Resolucao de Expressao
//===================================================================================================
//Retorna True apenas se char de entrada for um caractere valido
bool valida_str_1(char c)
{
	switch (c)
	{
	case ',': // separadores decimais
	case '.':
	case '0': // numeros
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '+': // operadores
	case '-':
	case '*':
	case '/':
	case '}': // escopos
	case '{':
	case '[':
	case ']':
	case ')':
	case '(':
		return true;
	default:
		return false;
	}
}
//Retorna True apenas se char de entrada for um caractere 'operando'
bool tem_numero(char c)
{
	switch (c)
	{
	case ',': // separadores decimais
	case '.':
	case '0': // numeros
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return true;
	default:
		return false;
	}
}
// retorna True apenas se char for um escopo
bool tem_escopo(char c)
{
	switch (c)
	{
	case '(':
	case ')':
	case '[':
	case ']':
	case '{':
	case '}':
		return true;
	default:
		return false;
	}
}

// retorna True apenas se char for um operador valido
bool tem_op(char c)
{
	switch (c)
	{
	case '+':
	case '-':
	case '/':
	case '*':
		return true;
	default:
		return false;
	}
}
//===============================================================================================================
// Checa irregularidades na string de entrada do Modo (1) Resolucao de Expressao
int check_exp(char *str)
{

	for (int i = 0; str[i] != '\0'; i++)
	{

		// testa se expressao possui algum caractere invalido
		if (!valida_str_1(str[i]))
		{
			printf("\nExpressao Inv%clida!\n\n", 160);
			return false;
		}

		// testa se ha operadores juntos
		if (tem_op(str[i]) && (tem_op(str[i + 1]) || tem_op(str[i - 1])))
		{ // testa se ha operadores juntos
			printf("\nExpressao Inv%clida!\n\n", 160);
			return false;
		}
	}

	return true;
}

//=============================================================================================================
