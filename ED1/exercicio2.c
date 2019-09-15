#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
int getNumeroPositivo();
float getNumeroReal(float *numero);
float calcularNovoSalario(int dias, float *novoSalario);
float calcularMediaSalarios(float *vetor, int tamanho);

int main() {
  setbuf(stdout, NULL);
  menu();
  return 0;
}

void menu() {
  int valida = 0, tamanho;
  float *salarioFinal, media;
  char opcao;
  do {
    printf("\n A- Resultado do exercicio 04 \n B- Resultado do exercicio 05 \n C- Finalizar \n");
    scanf("%c", &opcao);

    switch (opcao) {
    case 'A':
      calcularNovoSalario(getNumeroPositivo(), salarioFinal);
      printf("O salario final será de %.2f", *salarioFinal);
      break;
    case 'B':
      tamanho = getNumeroPositivo();
      float *pontVetor = (float*) malloc (sizeof(float) * tamanho);
      media = calcularMediaSalarios(pontVetor, tamanho);
      printf("A media sera de: %f", media);
      break;
    default:
      valida = 1;
      printf("\n Opcao invalida!");
      break;
    }
  } while(valida = 0);
}

int getNumeroPositivo() {
  int numero;
  do {
  printf("Digite um numero inteiro positivo:");
  scanf("%d", &numero);
    if (numero < 0) {
      printf("O número deve ser positivo!");
    }
  } while (numero < 0);

  return numero;
}

float getNumeroReal(float *numero) {
  do {
    printf("Digite um numero real positivo");;
    scanf("%f", numero); 
    if (*numero < 0) {
      printf("O numero deve ser positivo!");
    }
  } while (*numero < 0);

  return *numero;
}

float calcularNovoSalario(int dias, float *novoSalario) {
  return *novoSalario =  (130 * dias) * 0.92;
}

float calcularAumentoSalario(float salario) {
  float novoSalario;
  if (salario <= 1500) {
    novoSalario = salario + (salario * 0.15);
  } else if (salario > 1500 && salario <= 5000) {
    novoSalario = salario + (salario * 0.10);
  } else {
    return salario;
  }
  return novoSalario;
}

float calcularMediaSalarios(float *vetor, int tamanho) {
 int i;
 float soma;

 for (i = 0; i < tamanho; i++) {
   getNumeroReal(vetor);
   soma += *vetor;
   vetor++;
 }

 return soma / tamanho ;
}
