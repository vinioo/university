/*
 ============================================================================
 Name        : exercicio01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverter(char texto[], int tamanho) {
	if (tamanho < 0) {
		return;
	}
	printf("%c", texto[tamanho - 1]);
	inverter(texto, tamanho - 1);
}

int main(void) {
	inverter("oie", strlen("oie"));
	return EXIT_SUCCESS;
}
