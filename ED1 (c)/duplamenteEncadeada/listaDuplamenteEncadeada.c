/*
 ============================================================================
 Name        : listaDuplamenteEncadeada.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "listaDuplamenteEncadeada.h"

int main(void) {
	int i;
	codigos *lista = NULL;
	for (i  = 0; i <= 10; i++) {
		lista = inserirInicio(lista);
	}

	printf("%p", lista);
	return EXIT_SUCCESS;
}
