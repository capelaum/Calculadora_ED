
#include "Calculadora.h"

// Fun��es de suporte
//===============================================================
// Fun��o da opera��o c�pia de elemento c
int copia_elemento(t_pilha *pilha)
{ // k � dado a ser copiado / N � o numero de c�pias
	int N, i;
	float k;

	N = pilha->ultimo->dado; // N recebe o valor do dado do �ltimo elemento

	t_no *ptr = pilha->primeiro;

	if (!ptr)
		return false;

	while (ptr->proximo != pilha->ultimo)
		ptr = ptr->proximo;

	k = ptr->dado; // k recebe o valor do dado anterior ao �ltimo elemento

	remove_ultimo(pilha);

	for (i = 1; i < N; i++)
		empilha(k, pilha);

	return true;
}
//===============================================================
// Libera caracteres remanescentes na �rea de armazenamento tempor�rio
void limpabuffer()
{
	scanf("%*[^\n]");
	scanf("%*c");
}
//===============================================================
// Tranforma string de entrada em float
float str_em_float(char *str)
{

	int cont = 0, num = 0, i = 0;

	char *ptr;
	ptr = strpbrk(str, ","); //retorna um ponteiro para a posi��o da string que contem ","

	if (ptr)
		*ptr = '.'; //faz a substitui��o da ',' por '.'

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == '.')
		{ // verifica se tem o separador '.'
			cont++;
			continue;
		}
	}

	if (cont > 1)
		return false;

	i = 0;

	// parte inteira
	while (str[i] != '.' && str[i] != '\0')
	{
		num = num * 10 + (str[i++] - '0');
	}

	// pula o separador decimal '.' que fez sair do loop while
	i++;

	float valor = 1.0, x = 0.0, temp;

	// parte decimal, apos o separador '.'
	while (cont == 1 && str[i] != '\0')
	{
		valor = valor * 0.1;
		temp = valor * (str[i++] - '0');
		x = x + temp;
	}

	// adiciona parte inteira num com a decimal
	x = x + num;

	return x;
}
