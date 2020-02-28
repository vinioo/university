/*
 * hanoi.c
 *
 *  Created on: 19 de fev de 2020
 *      Author: flavio.laper
 */

#include <stdio.h>
#include <stdlib.h>

void hanoi(int discos, char origem, char destino, char auxiliar) {
	// Retirando os discos menores de cima do maior
	if(discos > 1)
		hanoi(discos-1, origem, auxiliar, destino);

	// Movendo o disco maior para o destino
	printf("Mover disco %d de %c para %c\n", discos, origem, destino);

	// Recolocando os discos menores em cima do maior
	if(discos > 1)
		hanoi(discos-1, auxiliar, destino, origem);
}

int main (int argc, char** argv) {
	int discos = 0;

	if(argc < 2) {
		printf("Favor informar o número de discos");
		exit(-1);
	}

	discos = atoi(argv[1]);

	printf("Torre de Hanoi para %d discos\n", discos);

	hanoi(discos, 'A', 'C', 'B');

	return 0;
}
