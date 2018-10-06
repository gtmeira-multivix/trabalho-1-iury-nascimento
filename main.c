#include <stdio.h>
#include <math.h>
#include "pilha.h"
#include "fila.h"
#include "tokenizacao.h"

int main() {
	//acccc
	//Substitua esta função pela implementação do seu trabalho.
	printf("Digite uma expressão:\n");
	Token t = token_proximo();
	Pilha *pilha_s=pilha_criar();
	Fila *fila_s=fila_criar();
	Token Topo;
	
	while(t.tipo != FIM && t.tipo != ERRO){
		//printf("\nToken = ");
		//token_imprimir(t);
		if(t.tipo==NUMERO){
			fila_adicionar(fila_s,t);
		}else if(t.tipo==OPERADOR){
			while((pilha_primeiro(pilha_s).precedencia > t.precedencia ) ||
				(pilha_primeiro(pilha_s).precedencia == t.precedencia && t.associatividade==ESQUERDA)){
			
				Topo=pilha_pop(pilha_s);
				fila_adicionar(fila_s,Topo);
			}
			pilha_push(pilha_s,t);	
		}else if(t.tipo==ABRE_PARENTESES){
			pilha_push(pilha_s,t);
		}else if(t.tipo==FECHA_PARENTESES){
			while(pilha_primeiro(pilha_s) !=ABRE_PARENTESES ){
				
				Topo=pilha_pop(pilha_s);
				fila_adicionar(fila_s,Topo);
				
			}
			
		}
		
		
		t = token_proximo();
	}
	
	while(pilha_vazia(pilha_s)!=1){
		
		Topo=pilha_pop(pilha_s);
		fila_adicionar(fila_s,Topo);
		
		
	}
	
	
	return 0;
}
