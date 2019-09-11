#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
int getNumber();
void getFloatPositiveNumber(float *numero);
void calcPaymentValue(int workDays, float *salarioFinal);
float calcPayment(float salary);
float calcAverageSalary(float salary[]);

int main() {

  int workDays;
  float newSalary, *pontNewSalary;
  pontNewSalary = &newSalary;

    menu();

    // Como passar o parametro de salario por referencia aqui

	printf("Digite o numero de dias trabalhados");
	workDays = getNumber();

    calcPaymentValue(workDays, pontNewSalary);
    printf("\n O valor do pagamento será de %f", newSalary);


//
//    newSalary = calcPayment(newSalary);
//    printf("\n O valor do salario será de %f", newSalary);

  getNumber();
  return 0;
}

void menu() {
  int workDays;
  float realNumber, *pontRealNumber;
  pontRealNumber = &realNumber;
	char option;
    scanf("%c", &option);
	do {
		printf("\n A- Resultado do exercício 04 \n B- Resultado do exercício 5 \n C- Finalizar");
		switch (option) {
			case 'A':
			    workDays = getNumber();
			    printf("\n O numero digitado foi de %d", workDays);
				break;
			case 'B':
				getFloatPositiveNumber(pontRealNumber);
				printf("\n O numero digitado foi %f", realNumber);
				break;
			case 'C':
				break;
		}
	} while (option != 'C');
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
