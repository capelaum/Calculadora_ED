// Menu.c - Arquivo principal que contem o Menu do projeto  

#include "Calculadora.h"
#include "Res_exp.h"

int main () {
int option = 0;
	
	printf("*********************************************\n");
	printf("                    MENU                     \n");
	printf("*********************************************\n");
	printf("\nModo desejado: \n");
	printf("--------->    (1)    - RESOLU%cAO DE EXPRESSAO\n", 128 );
	printf("--------->    (2)    - CALCULADORA  \n");
	printf("*********************************************\n");
	printf("(-1) para sair\n");
	
do{
	printf("*********************************************\n");
	printf("\nModo--> ");
	scanf("%d", &option);
	
// MODO Resolucao de Expressao Aritmetica (1)
if( option == 1 ){
	
	char exp [101];
	char exp_posfixa [101];
	int i = 0, p = true;
	
	do{
	
		printf("\nInsira Expressao: ");
		scanf("%s", exp);
		
		p = check_exp (exp); // Checa se expressao de entrada possui irregularidades
			
		if(!p) break; // Expressao invalida, sai do loop
		
		
		/*  ALGORITMO 1 */
		t_pilha_c* pilha_c = aloca_pilha_c(); // Inicia pilha
		
		if( valida_escopo(exp, pilha_c) ) { // Escopos Validos
			
			printf("\nExpressao V%clida!\n\n", 160); 
			apaga_pilha_c (pilha_c); // apaga pilha ao final da verificacao
		
		}
		else{
			
			printf("\nExpressao Inv%clida!\n\n", 160); // Escopos Invalidos
			apaga_pilha_c (pilha_c); // apaga pilha ao final da verificacao
			p = false; // Sai do loop
			break;
		
		}	
		
		
		/*  ALGORITMO 2 */
		transforma (exp, exp_posfixa); // transforma a expressao de infixa para posfixa
		printf("Expressao posfixa = %s \n", exp_posfixa); // imprime a expressao no formato posfixo
		
		/*  ALGORITMO 3 */
		float resultado_1 = resolve_posfixa (exp_posfixa); // resultado recebe o valor float retornado da funcao de resolucao da expressao posfixa
		printf( "\nResultado da Expressao fornecida: %.4f \n", resultado_1); // imprime o resultado em tela com casas decimais conforme exemplos dados
		
		p = false; // Sai do loop indenpendente de qualquer entrada, valida ou nao
		
	}while (p);
			
printf ("\nVolta ao Menu\n");		
// MODO Calculadora (2)
}else if( option == 2 ){

	char entrada [31]; // recebe entrada do usuario
	int p = true;
	float resultado_2; // recebe resultado das operacoes
		
	t_pilha* pilha = aloca_pilha(); // Inicia pilha de dados tipo float
		
	printf("\nInsira (s) para voltar ao menu principal\n");
	do{
		printf("*********************************************\n");	
		printf("Modo calculadora\n");
		if(esta_vazia (pilha) ) printf ("Pilha vazia!\n");
			
		imprime_pilha(pilha);
			
		printf("-> ");
		scanf("%s", entrada); // Entrada de dados 
			
		if (entrada[0] == 's'){  // Caso sair e voltar para Menu Principal - 's'
			printf ("\nVolta ao Menu\n");
			p = false;
			break;  // Sair do loop
		}
			
		int res = check (entrada); // Valida Entrada 
	
		if(res){
				
			if(tem_operador (entrada[0]) && entrada[0] != 'c'){ // Caso for operador qualquer diferente de 'c' copia  de elemento	
					
				if(verifica_pilha (pilha)){ // Verifica se tem 2 ou + operandos empilhados
					
					if(entrada[1] == '!'){ // Caso  operador de repeti��o '!'
							
						while(pilha->primeiro != pilha->ultimo){
								
							resultado_2 = desempilha_e_calcula_2 (entrada[0], pilha); 
							empilha (resultado_2, pilha);
							
						}
							
					}else{ // Caso operador - ( + - * / )
							
						resultado_2 = desempilha_e_calcula_2 (entrada[0], pilha); // desempilha 2 ultimos e retorna resultado conforme operador dado 
						empilha (resultado_2, pilha); // Resultado � empilhado
						
					}
				}
			}else if(entrada[0]=='c'){ // Caso operador - c�pia de elemento
					
				if(verifica_pilha(pilha)){ // Verifica se tem 2 ou + operandos empilhados
					copia_elemento (pilha); // Fun��o que realiza opera��o
				}
					
			}else{ // Caso entrada for operando 
					
				float numero;	
				numero = str_em_float (entrada); // Funcao que onverte string para float
				empilha (numero, pilha); // Empilha operando 
					
			}
		}else{
			printf("Entrada Invalida!\n"); // Entrada invalida, pois nao pertenceu a nenhum caso possivel
		}
			
	}while(p); // enquanto p = true
		
	apaga_pilha (pilha);
		
}else{  // Caso modo diferrente de 1 e 2
	if (option != -1){ // Caso diferente de Sair
		option = 0; // reseta option
		printf("Modo Inv%clido!\n\n\n",160); // Caso modo invalido
	}
}
	
limpabuffer();  // Retira caracteres remanescentes na �rea de armazenamento tempor�rio

}while(option != -1);
	
printf("\nEXIT\n");
return 0;
}
//END_MAIN

