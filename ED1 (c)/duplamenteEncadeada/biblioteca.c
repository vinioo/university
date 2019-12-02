/*
 * biblioteca.c
 *
 *  Created on: 20 de nov de 2019
 *      Author: n231013531
 */

#include <stdio.h>
#include <stdlib.h>

#include "listaDuplamenteEncadeada.h"

codigos* inserirInicio(codigos *lista) {
	//Alocar novo espaço
	codigos *novo = malloc (sizeof(codigos));

	//Preencher o campos básicos
	novo->codigo = RANDOM_NUMBER;
		novo->proximo = lista;
		novo->anterior = NULL;


	if (lista != NULL) {
		lista->anterior = novo;
	}

	return novo;

}

codigos* inserirFimLista(codigos *lista) {
	//Alocar novo espaço
	codigos *novo = (codigos*) malloc (sizeof(codigos));

	//Preencher o campos básicos
	novo->codigo = RANDOM_NUMBER;
	novo->proximo = NULL;

	if (lista == NULL){
		novo->anterior = NULL;
		return novo;
	} else {
		codigos *tmp = lista;
		while (tmp->proximo != NULL) {
			tmp = tmp->proximo;
		}
		tmp->proximo = novo;
		novo->anterior = tmp;
		return lista;
	}
}

codigos* excluirLista(codigos *lista, int numero) {
	codigos *posicaoAtual = lista;

	while(posicaoAtual != NULL) {

		// primeiro
		if (lista->codigo == numero && lista->anterior == NULL) {

			posicaoAtual->proximo = posicaoAtual->proximo->proximo;
			posicaoAtual->proximo->anterior = NULL;

			free(lista);

			return posicaoAtual;
		}

//		// fim
		if (lista->codigo == numero && lista->proximo == NULL) {

			posicaoAtual->anterior =
		}

		// meio
		if (lista->codigo == numero) {

			posicaoAtual->anterior->proximo = posicaoAtual->proximo;
			posicaoAtual->proximo->anterior = posicaoAtual->anterior;

			free(lista);

			return posicaoAtual;
		}


	}



}
