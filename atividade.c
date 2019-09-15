#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
int getNumber();
void getFloatPositiveNumber(float *numero);
void calcPaymentValue(int workDays, float *salarioFinal);
float calcPayment(float salary);
float retornarSoma(float *pontVetor, int tamanho);

int main() {

	setbuf(stdout, NULL);
    menu();
  return 0;
}

void menu() {
  float salarioFinal, *pontVetor;
  int tamanho;

	char option;

		printf("\n A- Resultado do exercício 04 \n B- Resultado do exercício 6 \n C- Finalizar \n");
		scanf("%c", &option);
		fflush(stdin);
		switch (option) {
			case 'A':
			    calcPaymentValue(getNumber(), &salarioFinal);
			    printf("\n O numero digitado foi de %f", salarioFinal);
				break;
			case 'B':
				printf("\n Digite o tamanho do vetor");
				scanf("%d", &tamanho);
				pontVetor = (float*) malloc (sizeof(float) * tamanho);
				printf("A media dos salarios e de R$%.2f", retornarSoma(pontVetor, tamanho));
				break;
			case 'C':
				break;
		}

}

float retornarSoma(float *pontVetor, int tamanho) {
	int i;
	float soma = 0;
	for (i = 0; i < tamanho; i++) {
		getFloatPositiveNumber(pontVetor);
		soma += calcPayment(*pontVetor);
		pontVetor++;
	}

	return soma / tamanho;

}
int getNumber() {
  int number;
	  do {
	  printf("\n Digite um número inteiro positivo ou nulo:");
	  scanf("%d", &number);
		if (number < 0 && number != '\0') {
		  printf("\n O número não pode ser negativo!");
		}
	  } while (number < 0 && number != '\0');

  return number;
}

void getFloatPositiveNumber(float *numero) {
	  do {
	  printf("\n Digite um número real positivo:");
	  scanf("%f", numero);
	  	  if(*numero <= 0) {
	  		  printf("Valor invalido");
	  	  }
	  } while (*numero <= 0);
}


void calcPaymentValue(int workDays, float *salarioFinal) {
	*salarioFinal = (workDays * 130) * 0.92;
}

float calcPayment(float salary) {
  float newSalary;

  if (salary <= 1500) {
    newSalary = salary + (salary * 0.15);
  } else if (salary > 1500 && salary <= 5000) {
    newSalary = salary + (salary * 0.10);
  } else {
    newSalary = salary;
  }

  return newSalary;
}
