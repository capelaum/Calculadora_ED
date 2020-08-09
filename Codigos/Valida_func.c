
#include "Calculadora.h"

// Funcoes de validacao da string de entrada do Modo Calculadora
//===============================================================
// Retorna True apenas se char de entrada for v�lido
bool valida_str(char c)
{
	switch (c)
	{
		case ',':
		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '+':
		case '-':
		case '*':
		case '/':
		case '!':
		case 'c':
			return true;
		default:
			return false;
	}
}

// Retorna True apenas se char de entrada for diferente de numeros
bool tem_char(char c)
{
	switch (c)
	{
		case ',':
		case '.':
		case '+':
		case '-':
		case '*':
		case '/':
		case '!':
		case 'c':
			return true;
		default:
			return false;
	}
}
// Retorna True apenas se char for um operador
bool tem_operador(char c)
{
	switch (c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '!':
		case 'c':
			return true;
		default:
			return false;
	}
}

// Funcao que checa a string de entrada usando as funcoes bool anteriores
int check(char *str)
{
	int i, cont = 0, entrada = true;
	char op;

	for (i = 0; str[i] != '\0'; i++)
	{

		if (!valida_str(str[i]))
		{ // Verifica se ha char irregular em toda string
			entrada = false;
			break;
		}

		if (tem_char(str[i]))
		{ // Verifica se string possui caracteres diferentes de numeros
			cont += 1;

			if (str[i] == '!')
			{ // Caso caractere especial
				if (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/')
				{
					cont--; // Para contador nao ultrapassar 1 apenas nesse caso;
				}
				else
				{
					entrada = false;
					break;
				}
			}
		}
	}

	if (cont > 1)
		entrada = false; // Se contador de char > 1, � invalido

	if (cont == 1)
	{ // Caso de apenas 1 operador

		int num = false;

		for (i = 0; str[i] != '\0'; i++)
		{
			if (isdigit(str[i]))
			{
				num = true; // Tem digito '0' a '9' na string
				break;
			}
		}

		if (num)
		{

			for (i = 0; str[i] != '\0'; i++)
			{
				if (tem_operador(str[i]))
				{									 // Verifica se tem (+ - * / ! c )
					entrada = false; // Tem operador juntamente com numero na string -> entrada inv�lida
					break;
				}
			}
		}
	}

	return entrada;
}
