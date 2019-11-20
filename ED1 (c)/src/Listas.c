/*
 ============================================================================
 Name        : Listas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "listas.h"

int main(void) {
	cadastroStruct *lista = NULL;
	int i;
	for (i = 1; i <= 3; i++) {
		lista = cadastrarInicioLista(lista);
	}
	imprimirLista(lista);
	return EXIT_SUCCESS;
}
