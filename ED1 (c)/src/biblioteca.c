/*
 * listas.s
 *
 *  Created on: 12 de nov de 2019
 *      Author: n231013531
 */

#include <stdio.h>
#include <stdlib.h>
#include "listas.h"


cadastroStruct* cadastrarInicioLista(cadastroStruct *lista) {
	cadastroStruct *lista2;
	lista2 =  malloc (sizeof(cadastroStruct));

	lista2->codigo = RANDOM_NUMBER;
	lista2->proximo = lista;

	return lista2;

}

void imprimirLista(cadastroStruct *lista) {
	if (lista != NULL) {
		printf("Endereco atual:");
		printf(" %p \n", lista);
		printf("Codigo: %d \n", lista->codigo);
		printf("Proximo endereco");
		printf("%p", lista->proximo);
		imprimirLista(lista->proximo);
	}
}

cadastroStruct* inserirFimLista(cadastroStruct *lista) {
	cadastroStruct *lista2;
	lista2 =  malloc (sizeof(cadastroStruct));

	lista2->codigo = RANDOM_NUMBER;
	lista2->proximo = NULL;

	if (lista == NULL) {
		return lista2;
	} else {
		cadastroStruct *tmp = lista;
		while(lista->proximo != NULL) {
			tmp = tmp->proximo;
		}
		return lista;
	}
}
