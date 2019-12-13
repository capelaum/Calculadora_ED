
#include "Res_exp.h"
#include "Calculadora.h"

//=====================================================================================
// Algoritmo 3 - Resolve a expressao posfixa dada de entrada
// Utiliza diversas funcoes de Pilha_func.c / Valida_func.c / Suporte_func.c
// Portanto, necessario incluir Calculadora.h

float resolve_posfixa (char* str)  {
	
	float res; // armazena o resultado
	int i = 0, j = 0, conta_num = 0, conta_op =0;

	t_pilha* pilha = (t_pilha*) aloca_pilha(); // Inicia Pilha

	char num [15];
	
	for(i=0; str[i] != '\0' ;i++) {  // percorre toda expressao posfixa
	
		
		if( tem_numero (str[i])){
			
			conta_num += 1;
			j=0;
			
			while( tem_numero (str[i]) ){ // Coleta os operandos e copia na na string num
				num[j++] = str[i++];
			}
			
			num[j] = '\0';             // sinalizador de final da string num contendo operando  
			res = str_em_float (num); // tranforma string numero em float
			
			if(!res) return false;
			
			empilha (res, pilha);    // empilha na pilha  float
			
		}
		
		if(tem_op (str[i]) ){
			conta_op += 1; // Conta numero de operadores
			char op = str[i]; // op guarda caractere de operador ( * / - + )
			
			if (verifica_pilha (pilha)){ // verifica se pilha possui operandos suficientes (2 valores float)
				res = desempilha_e_calcula_1 (op, pilha); // desempilha os dois valores do topo e realiza a operacao 
				empilha (res, pilha); // empilha o resultado
			}else{ 
				break;
			}
				
				
		}
		
	}	
	
	return res; // retorna resultado 
}

