
#include "Res_exp.h"

//============================================================================================================
// Algoritmo 1 - Valida os escopos conforme descrito na descricao do projeto
int valida_escopo (char* str, t_pilha_c* pilha_c) { 
   
	for (int i = 0; str[i] != '\0'; i++) {
      char c;
		
		if(tem_escopo (str[i]) ){
			
			switch (str[i]) {
				
	         case ')': if (esta_vazia_c (pilha_c)) return false;
	                   c = desempilha_c (pilha_c);
	                   if (c != '(') return false;
	                   break;
	                   
	         case ']': if (esta_vazia_c (pilha_c)) return false;
	                   c = desempilha_c (pilha_c);
	                   if (c != '[') return false;
	                   break;
	                   
	         case '}': if (esta_vazia_c (pilha_c)) return false;
	                   c = desempilha_c (pilha_c);
	                   if (c != '{') return false;
	                   break;
	                   
	         default:  empilha_c (str[i],pilha_c);
	      }
	   
		}
	
	}
	
	return esta_vazia_c (pilha_c); // Retorna 0 se for invalida e 1 se for valida -> pilha deve estar vazia
}
//==================================================================================================================================
