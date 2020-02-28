/*
 * fibonacci.c
 *
 *  Created on: 27 de fev de 2020
 *      Author: flavio.laper
 */

#include <stdio.h>

long fib(int n) {
	if(n < 2)
		return n;

	return fib(n-1) + fib(n-2);
}

int main(void) {
	int n = 6;

	printf("fib(%d) = %ld\n", n, fib(n));

	return 0;
}
