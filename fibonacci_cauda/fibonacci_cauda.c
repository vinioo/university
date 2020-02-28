/*
 * fibonacci_cauda.c
 *
 *  Created on: 27 de fev de 2020
 *      Author: flavio.laper
 */

#include <stdio.h>

long fib_tail(int n, long ultimo, long penultimo) {
	if(n < 1)
		return penultimo;

	return fib_tail(n-1, ultimo+penultimo, ultimo);
}

long fib(int n) {
	return fib_tail(n,1,0);
}

int main(void) {
	int n = 8;

	printf("fib(%d) = %ld\n", n, fib(n));

	return 0;
}

