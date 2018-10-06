#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


typedef struct no {
  Token token;
  struct no *prox;
}No;

typedef struct pilha {
  No *primeiro;
}Pilha;
//fazer da forma da lista encadeada
Pilha* pilha_criar() {
	Pilha *p =(Pilha*)malloc(sizeof(Pilha));
	p->primeiro=NULL;
	return p;
}

void pilha_push(Pilha *p, Token t) {
	//Implemente
	No *n = (No*) malloc(sizeof(No));
	n->token = t;
	//Ajustar os ponteiros:
	n->prox = p->primeiro;
	p->primeiro = n;

}

Token pilha_pop(Pilha *p) {
	//Implemente
	Token token;
	//Verificar lista vazia:
	if(p->primeiro == NULL){
		printf("Pilha vazia\n");
		return token;
	}

	No *tmp = p->primeiro;
	token = tmp->token;

	p->primeiro = tmp->prox;
	free(tmp);
	//Retornar informacao armazenada:
	return token;

}

Token pilha_primeiro(Pilha *p) {
	Token token;

	No *tmp = p->primeiro;
	token = tmp->token;
	
	//Retornar informacao armazenada:
	return token;
}

int pilha_vazia(Pilha *p) {
	//Implemente
	if(p->primeiro==NULL){
		return 1;
		
	}else{
		return 0;
	}
}

void pilha_destruir(Pilha *p) {
	//Implemente
	No *tmp=p->primeiro;
	while(tmp!=NULL){
		No *excluir=tmp;
		tmp=tmp->prox;
		free(excluir);
		
	}
	free(p);
}

void pilha_imprimir(Pilha *p) {
	//Implemente
	No *tmp=p->primeiro;
	while(tmp != NULL){
		token_imprimir(tmp->token);
		tmp= tmp->prox;
		
	}
}
