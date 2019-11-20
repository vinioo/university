/*
 * MinhasFuncoes.c
 *
 *  Created on: 13 de nov de 2019
 *      Author: amanda.oliveira
 */

#include <stdio.h>
#include <stdlib.h>

#include "MinhaBiblioteca.h"

cadastro* inserirInicio(cadastro *lista) {
	//Alocar novo espa�o
	cadastro *novo = (cadastro*) malloc (sizeof(cadastro));

	//Preencher o campos b�sicos
	novo->codigo = RANDOM;
	novo->proximo = lista;

	//REtornar o endere�o de mem�ria do novo
	return novo;
}

void imprimir(cadastro *listaSimples){
	if (listaSimples != NULL){
		printf("\nEndere�o %p - C�digo %d - Pr�ximo %p\n",
				listaSimples, listaSimples->codigo, listaSimples->proximo);
		imprimir(listaSimples->proximo);
	}
}

cadastro* inserirFim(cadastro *lista) {
	//Alocar novo espa�o
	cadastro *novo = (cadastro*) malloc (sizeof(cadastro));

	//Preencher o campos b�sicos
	novo->codigo = RANDOM;
	novo->proximo = NULL;

	if (lista == NULL){
		return novo;
	} else {
		cadastro *tmp = lista;
		while (tmp->proximo != NULL) {
			tmp = tmp->proximo;
		}
		tmp->proximo = novo;
		return lista;
	}
}

cadastro* inserirFimUltimo(cadastro *lista, cadastro **ultimo) {
	//Alocar novo espa�o
	cadastro *novo = (cadastro*) malloc (sizeof(cadastro));

	//Preencher o campos b�sicos
	novo->codigo = RANDOM;
	novo->proximo = NULL;

	if ((*ultimo) != NULL) {
		(*ultimo)->proximo = novo;
	}
	(*ultimo) = novo; //Atualizar o �ltimo registro
	if (lista == NULL) {
		return novo;
	} else {
		return lista;
	}
}

cadastro* excluirElemento (cadastro *lista, int cod){
	cadastro *tmp = lista,
			 *anterior = NULL;

	while (tmp != NULL) {
		if (tmp->codigo == cod){
			//Encontrei
			if (anterior != NULL) {
				anterior->proximo = tmp->proximo;
			} else {
				lista = lista->proximo;
			}

			free(tmp);
			break;
		} else {
			//N�o encontrei
			anterior = tmp;
			tmp = tmp->proximo;
		}
	}
	return lista;

}



