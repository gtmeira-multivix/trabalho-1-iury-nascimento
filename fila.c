#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no {
  Token token;
  struct no *prox;
} No;

typedef struct fila {
  No *primeiro, *ultimo;
}Fila;


Fila* fila_criar() {
	Fila *f =(Fila*)malloc(sizeof(Fila));
	f->primeiro=NULL;
	f->ultimo=NULL;
	return f;
	
	
}

void fila_adicionar(Fila *f, Token t) {
	//Implemente
	No *n=(No*)malloc(sizeof(No));
	n->token=t;
	n->prox=NULL;
	if(f->ultimo==NULL){
		f->primeiro=n;
		f->ultimo=n;
		return;
	}
	
	f->ultimo->prox=n;
	f->ultimo=n;
	
}

Token fila_remover(Fila *f) {
	Token token;
	
	if(f->primeiro==NULL){
		printf("lista vazia");
		return token;
	}
	No *excluir=f->primeiro;
	f->primeiro=f->primeiro->prox;
	if(f->primeiro== NULL){
		f->ultimo=NULL;
		
	}
	token= excluir->token;
	free(excluir);
	return token;
	
	
}

int fila_vazia(Fila *f) {
	//Implemente
	if(f->primeiro==NULL){
		return 1;
		
	}else{
		return 0;
	}
}

void fila_destruir(Fila *f) {
	//Implemente
	No *tmp=f->primeiro;
	while(tmp!=NULL){
		No *excluir=tmp;
		tmp=tmp->prox;
		free(excluir);
		
	}
	free(f);
	
}

void fila_imprimir(Fila *f) {
	//Implemente
	No *tmp=f->primeiro;
	while(tmp != NULL){
		token_imprimir(tmp->token);
		tmp= tmp->prox;
		
	}
}
