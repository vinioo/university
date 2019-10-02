/*
 ============================================================================
 Name        : pagina103.c
 Author      : vinicius
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum {fibonacci = 1, fatorial = 2} opcao;

typedef union {
	int opcao;
	int numero;
} escolha;

typedef struct {
	float resultado;
	int termo;
} resultadoTermo;


void menu();
void receberInteiro(char texto[], int *numero, opcao tipo);
int calcularFibonacci(resultadoTermo resultadoFibonacci);
int calcularFatorial(resultadoTermo resultadoFatorial);

int main(void) {
	setbuf(stdout, NULL);
	menu();
	return EXIT_SUCCESS;
}

void menu() {
	escolha escolha;
	resultadoTermo cfibonacci;
	resultadoTermo cfatorial;
	do {
		printf("\n 1 - Calcular sequencia de Fibonacci \n 2 - Calcular Fatorial \n 3 - Finalizar");
		fflush(stdin);
		scanf("%d", &escolha.opcao);
		switch (escolha.opcao) {
			case fibonacci:
				receberInteiro("Digite o numero fibonacci positivo \n", &cfibonacci.termo, fibonacci);
				cfibonacci.resultado = calcularFibonacci(cfibonacci);
				printf("%.2f", cfibonacci.resultado);
				break;
			case fatorial:
				receberInteiro("Digite o numero fatorial, positivo ou nulo", &cfatorial.termo, fatorial);
				cfatorial.resultado = calcularFatorial(cfatorial);
				printf("%.2f", cfatorial.resultado);
				break;
			default:
				break;
		}
	} while(escolha.opcao != 3);
}

void receberInteiro(char texto[], int *numero, opcao tipo) {
	if (tipo == fibonacci) {
		do {
			printf("%s", texto);
			scanf("%d", numero);

			if (*numero < 0 && *numero != '\0') {
				printf("\n O numero deve ser positivo!!");
			}
		} while(*numero < 0 && *numero != '\0');
	} else {
		do {
			printf("%s", texto);
			scanf("%d", numero);
			if (*numero < 0 && *numero != '\0') {
				printf("\n O numero deve ser positivo!!");
			}
		} while(*numero < 0);
	}

}


int calcularFibonacci(resultadoTermo resultadoFibonacci) {
	  int i, fib1 = 1, fib2 = 1, soma;
	      for (i = 3; i <= resultadoFibonacci.termo; i = i + 1)
	      {
	        soma = fib1 + fib2;
	        fib1 = fib2;
	       fib2 = soma;
	     }
	     return fib2;
}

int calcularFatorial(resultadoTermo resultadoFatorial) {
	int fat;
	  for(fat = 1; resultadoFatorial.termo > 1; resultadoFatorial.termo = resultadoFatorial.termo - 1)
	  {
		  fat = fat * resultadoFatorial.termo;
	  }

	  return fat;
}



