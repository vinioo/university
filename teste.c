#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
int getNumeroInteiro();
float valorLiquidoSalario(int numeroDias, float *salarioFinal);
float getNumeroReal(float *numero);
float calcularNovoSalario(float salario);
float calcularMediaSalarios();

int main() {
  setbuf(stdout, NULL);
  menu();
}

void menu() {
  char opcao;
  float *pontVetor, *salarioFinal, media;
  int invalida = 0, dias, tamanho;
  
  printf("\n A - Resultado do exercicio 04 \n B - Resultado do exercicio 05 \n C - Finalizar");
  scanf("%c", &opcao);
  fflush(stdin);

  do {
    switch (opcao) {
    case 'A':
    
      printf("\n Digite o numero de dias trabalhados");
      scanf("%d", &dias);
      valorLiquidoSalario(dias, salarioFinal);
      printf("\n O salario novo sera de %f", *salarioFinal);
      break;
    case 'B': 
      tamanho = getNumeroInteiro();
      pontVetor = (float*) malloc (sizeof(float) * tamanho);
      media = calcularMediaSalarios(tamanho, pontVetor);
      printf("\n A media de salarios sera de %f", media);
      break;
    case 'C':
      break;
    default:
      invalida = 1;
      printf("\n Opcao inváida!");
      break;
    }
  } while (invalida == 0);
}


int getNumeroInteiro() {
  int numero;
  do {
    printf("\n Digite um numero inteiro");
    scanf("%i", &numero);

    if (numero < 0) {
      printf("\n O numero deve ser positivo!");
    }
  } while (numero < 0);

  return numero;
}

float getNumeroReal(float *numero) {
  do {
    printf("\n Digite um numero real positivo");
    scanf("%f", numero);
    if (*numero < 0) {
      printf("\n O numero deve ser positivo!");
    }
  } while(*numero < 0);
}

float valorLiquidoSalario(int numeroDias, float *salarioFinal) {
  return *salarioFinal = (numeroDias *  130)  * 0.92;
}

float calcularNovoSalario(float salario) {
  float novoSalario;
  if (salario <= 1500) {
    novoSalario = salario + (salario * 0.15);
  } else if (salario > 1500 && salario <= 5000) {
    novoSalario = salario + (salario * 0.10);
  } else {
    novoSalario = salario;
  }
  return novoSalario;
}

float calcularMediaSalarios(int tamanho, float *pontVetor) {
  float soma;
  int i;

  for (i = 0; i < tamanho; i++) {
    getNumeroReal(pontVetor);
    soma += calcularNovoSalario(*pontVetor);
    pontVetor++;
  }

  return soma / tamanho;

}