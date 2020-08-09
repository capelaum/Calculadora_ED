
#include "Res_exp.h"

// Define funcao que eh usada para definir a precedencia do operador. Quanto maior o valor inteiro retornado, maior a precedencia
int precedencia(char c)
{ // Usada no Algoritmo 2
	if (c == '*' || c == '/')
	{
		return (2);
	}
	else if (c == '+' || c == '-')
	{ // precedencia menor
		return (1);
	}
	else
	{
		return (0);
	}
}
//================================================================
// Algoritmo 2 - Transforma expressao infixa para posfixa
void transforma(char *exp_infixa, char *exp_posfixa)
{

	int i = 0, j = 0;
	char item = exp_infixa[i]; /* initialize before loop*/
	char c;

	t_pilha_c *pilha_c = (t_pilha_c *)aloca_pilha_c(); // Inicia Pilha

	while (item != '\0')
	{ // percorre toda expressao infixa

		if (item == '(' || item == '[' || item == '{')
		{
			empilha_c(item, pilha_c);
		}
		else if (tem_numero(item))
		{
			exp_posfixa[j++] = item; /* adiciona operando para expressao posfixa */
		}
		else if (tem_op(item))
		{ // caractere eh operador

			exp_posfixa[j++] = ' '; // coloca espa�os entre os operandos e operadores
			c = desempilha_c(pilha_c);

			while (tem_op(c) && precedencia(c) >= precedencia(item))
			{ // enquanto c for um operador e sua precedencia for maior que a do item

				exp_posfixa[j++] = c; /* desempilha todos operadores de precedencia mais alta */

				exp_posfixa[j++] = ' ';
				c = desempilha_c(pilha_c); /* adiciona para expressao posfixa */
			}

			empilha_c(c, pilha_c);		//  desempilhamos 1 operador a mais onde a condi��o falha e o loop termina, entao para esse caso
			empilha_c(item, pilha_c); /* empilha operador atual para a pilha */
		}
		else if (item == ')')
		{														 /* se o simbolo atual eh ')' entao */
			c = desempilha_c(pilha_c); /* desempilha e continua ateh */

			while (c != '(')
			{ /* '(' for encontrado */

				exp_posfixa[j++] = ' ';
				exp_posfixa[j++] = c;

				c = desempilha_c(pilha_c);
			}
		}
		else if (item == ']')
		{														 /* se o simbolo atual eh ']' entao */
			c = desempilha_c(pilha_c); /* desempilha e continua ateh */

			while (c != '[')
			{ /* '[' for encontrado */

				exp_posfixa[j++] = ' ';
				exp_posfixa[j++] = c;

				c = desempilha_c(pilha_c);
			}
		}
		else if (item == '}')
		{														 /* se o simbolo atual eh '}' entao */
			c = desempilha_c(pilha_c); /* desempilha e continua ateh */

			while (c != '{')
			{ /* '{' for encontrado */

				exp_posfixa[j++] = ' ';
				exp_posfixa[j++] = c;

				c = desempilha_c(pilha_c);
			}
		}
		else
		{ /* Caso nao seja nenhum dos casos: operando, operador ou separador */

			printf("\nExpressao Infixa Invalida\n"); /* caractere invalido */
			exit(1);
		}

		i++;
		item = exp_infixa[i]; /* proximo char */
	}												/* end while */

	while (!esta_vazia_c(pilha_c))
	{
		c = desempilha_c(pilha_c);
		exp_posfixa[j++] = ' ';
		exp_posfixa[j++] = c;
	}

	exp_posfixa[j] = '\0'; /* adiciona caractere nulo no final como sentinela */

	apaga_pilha_c(pilha_c);
}
