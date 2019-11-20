/*
 ============================================================================
 Name        : listaSimplesmenteEncadeada.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "MinhaBiblioteca.h"

int main(void) {
	setbuf(stdout, NULL);
	cadastro *lista = NULL,
			 *ultimo = NULL;
	int i;

	for (i = 1; i <= 5; i++) {
		lista = inserirFim(lista);
		//lista = inserirFimUltimo(lista, &ultimo);
	}

	printf("\nLista\n");
	imprimir(lista);

	//Excluir o primeiro
	printf("\nLista\n");
	lista = excluirElemento(lista, 18467);
	imprimir(lista);

	printf("\nLista\n");
	lista = excluirElemento(lista, 41);
	imprimir(lista);

	printf("\nLista\n");
	lista = excluirElemento(lista, 26500);
	imprimir(lista);

	printf("\nLista\n");
	lista = excluirElemento(lista, 19);
	imprimir(lista);

	printf("\nLista\n");
	lista = excluirElemento(lista, 19169);
	imprimir(lista);

	printf("\nLista\n");
	lista = excluirElemento(lista, 6334);
	imprimir(lista);


	return EXIT_SUCCESS;
}
