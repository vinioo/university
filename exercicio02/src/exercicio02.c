/*
 ============================================================================
 Name        : exercicio02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void palindromo(char texto[], int tamanho) {
	if (tamanho < 0) {
		return;
	}
	if (texto[tamanho - 1] != texto[tamanho - tamanho + 1]) {
		printf("ultima: %c - primeira: %c \n", texto[tamanho - 1], texto[tamanho - tamanho + 1]);
	}
	printf("%c", texto[tamanho - 1]);
	palindromo(texto, tamanho - 1);
}

int main(void) {
	palindromo("rodador", strlen("rodador"));
	return EXIT_SUCCESS;
}
