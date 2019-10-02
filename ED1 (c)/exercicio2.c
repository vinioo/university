#include <stdio.h>
#include <stdlib.h>

//Protótipos
void menu();
void concatenar();
void receberInteiro(char frase[], int *numero);
char retornarConceito(int nota);
void funcao04(int *vetorInt, char *vetorChar, int tamanho);
float funcao05(int *vetorInt, char *vetorChar, int tamanho, int *maiorNota);
int main(void) {
	setbuf(stdout, NULL);
	menu();
	return 0;
}




void menu(){
	int 	op;
	int numero, tamanho, *vetorInt, maiorNota;
	char *vetorChar;
	float media;

	do {

		printf("\n1 - Função 01"
				"\n2 - Função 02"
				"\nSair"
				"\nDigite sua opção: ");
		scanf("%d", &op);

		switch (op){
		case 1:
			printf("\nExecutar todas as chamadas da função 01 \n");
			concatenar("teste", "vinicius");
			break;
		case 2:
			printf("\nExecutar todas as chamadas da função 05 \n");
			vetorInt = (int*) malloc (sizeof(int) * tamanho);
			vetorChar = (char*) malloc (sizeof(char) * tamanho);
			receberInteiro("Digite o tamanho dos vetores", &numero);
			media = funcao05(vetorInt, vetorChar, numero, &maiorNota);

			printf("A maior nota foi: %d \n", maiorNota);
			printf("A media da turma foi: %.2f \n", media);
			break;
		case 3:

			printf("\nPrograma encerrado.");
			break;
		default:
			printf("\nValor inválido.");
		}
	} while (op != 3);
}


void concatenar(char a[], char b[]) {
	int i = 0;
    int tamanho1 = 0;
    while (a[tamanho1]) tamanho1++;

    int tamanho2 = 0;
    while (b[tamanho2]) tamanho2++;

    int tamanho3 = tamanho1 + tamanho2 + 1;
    char *c = (char *) malloc(tamanho3);

    for (i = 0; a[i]; i++) {
        c[i] = a[i];
    }

    for (i = 0; b[i]; i++) {
        c[i + tamanho1] = b[i];
    }

    c[tamanho1 + tamanho2] = 0;

    printf("%s\n", c);
    free(c);
}

void receberInteiro(char frase[], int *numero) {
	do {
		printf("%s", frase);
		scanf("%d", numero);
		if (*numero < 0 || *numero > 100) {
			printf("\n O numero deve ser entre 1 e 100!");
		}
	} while(*numero < 0 || *numero > 100);
}

char retornarConceito(int nota) {
	if (nota >= 60 && nota <= 100) {
		return 'A';
	} else if (nota >= 20 && nota <= 59) {
		return 'E';
	} else {
		return 'R';
	}
}

void funcao04(int *vetorInt, char *vetorChar, int tamanho) {
  int i;

  for (i = 0; i < tamanho; i++) {
	receberInteiro("Digite um numero entre 1 e 100", vetorInt);
	*vetorChar = retornarConceito(*vetorInt);

	vetorChar++;
	vetorInt++;
  }

}

float funcao05(int *vetorInt, char *vetorChar, int tamanho, int *maiorNota) {
	int i;
	float media;
	*maiorNota = 0;

	funcao04(vetorInt, vetorChar, tamanho);

	for (i = 0; i < tamanho; i++) {
		  printf("Conceito: %c \n", *vetorChar);
		  printf("Nota: %d \n", *vetorInt);

		  media += *vetorInt;

		  if (*vetorInt > *maiorNota) {
			  *maiorNota = *vetorInt;
		  }

		  vetorChar++;
		  vetorInt++;

	}

	return media / tamanho;
}


