#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
int getNumber();
float getFloatPositiveNumber();
float calcPaymentValue(int days);
float calcPayment(float salary);
float calcAverageSalary(float salary[]);

int main() {
  char option[1];
  int workDays;
  float newSalary;
  do {
    menu();
    scanf("%s", &option);
  } while (strcmp(option, "C") || strcmp(option, "A") || strcmp(option, "B"));
  // Seria essa a melhor forma para comparação de strings no C?

  if (option == "A") {
    workDays = getNumber();
    // Como passar o parametro de salario por referencia aqui
    newSalary = calcPaymentValue(workDays);
    printf("\n O valor do pagamento será de %f", newSalary);
  }

  if (option == "B") {
    newSalary = calcPayment(newSalary);
    printf("\n O valor do salario será de %f", newSalary);
  }
  getNumber();
  return 0;
}

void menu() {
  printf("\n A- Resultado do exercício 04 \n B- Resultado do exercício 5 \n C- Finalizar");
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

float getFloatPositiveNumber() {
  float number;
  do {
  printf("\n Digite um número real positivo:");
  scanf("%f", &number);
    if (number < 0) {
      printf("\n O número não pode ser negativo!");
    }
  } while (number < 0);

  return number;
}

float calcPaymentValue(int workDays) {

  int newSalary = (workDays * 130) * 0.92;
  return newSalary;
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