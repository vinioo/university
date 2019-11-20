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
		return novo;
	} else {
		codigos *tmp = lista;
		while (tmp->codigo != NULL) {
			tmp = tmp->proximo;
		}
		tmp->proximo = novo;
		return lista;
	}
}
