#include <stdio.h>
#include <stdlib.h>

//Protótipos
void menu();
void concatenar();
void receberInteiro(char frase[], int *numero);
char retornarConceito(int nota);
int main(void) {
	setbuf(stdout, NULL);
	menu();
	return 0;
}




void menu(){
	int 	op;
	int *pontNumero, numero;
	pontNumero = &numero;

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

			receberInteiro("Digite um numero de 1 ate 100", pontNumero);
			printf("%d", *pontNumero);
			break;
		case 3:
			printf("%c",retornarConceito(20));
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
