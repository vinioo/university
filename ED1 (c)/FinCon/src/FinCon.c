
/*
 ============================================================================
 Name        : TrabalhoED1.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main(void) {
	setbuf(stdout, NULL);
	cliente *cliente = NULL;
	cliente = inserirClienteFim(cliente);
	exibirClienteLista(cliente);
	exibirClientePorCodigo(cliente);
	exibirClientePorCartao(cliente);
//	menu();
	return EXIT_SUCCESS;
}
