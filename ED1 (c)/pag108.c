/*
 ============================================================================
 Name        : pagina108.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void menu();
int cadastrarCodigo();
void cadastrarNome();
void cadastrarPreco();
void cadastrarQuantidade();
int totalProdutos();

	typedef struct {
		char nome[40];
		int codigo;
		float preco;
		int quantidade;
	} produtosStruct;

int main(void) {

}

void menu() {
	char opcao;

	do {
		printf("A - Criar estrutura para preenchimento");
		printf("B - Preencher dados");
		printf("C - Exibir produtos com estoque zerado");
		printf("D - Exibir produtos em estoque");
		printf("E - Finalizar");

		scanf("%c", &opcao);

		switch (opcao) {
			case 'A':
				produtosStruct *produtos = (produtosStruct*) malloc (sizeof(produtosStruct) * totalProdutos());

				break;
			case 'B':
				break;
			case 'C':
				break;
			case 'D':
				break;
			case 'E':
				break;
			default:
				break;
		}
	} while(opcao != 'E');
}

int totalProdutos() {
	int numero;
	do {
		printf("Digite o total de produtos (1 a 50)");
		scanf("%d", &numero);
		if (numero < 1 && numero > 50) {
			printf("O numero deve ser entre 1 e 50!!!");
		}
	} while(numero < 1 && numero > 50);

	return numero;
}

int cadastrarCodigo() {
	int numero;
	do {
		printf("Digite o numero do produto (1 a 50)");
		scanf("%d", &numero);
		if (numero < 1 && numero > 50) {
			printf("O numero deve ser entre 1 e 50!!!");
		}
	} while(numero < 1 && numero > 50);

	return numero;
}

void cadastrarNome() {
	char nomeproduto[30];
	do {
		printf("Digite o nome do produto:");
		scanf("%s", &nomeproduto);
		if (nomeproduto == '\0') {
			printf("O nome do produto não pode ser nulo!");
		}
	} while(nomeproduto == '\0');
}

void cadastrarPreco() {
	float preco;
	do {
		printf("Digite o preco do produto");
		scanf("%f", &preco);

		if (preco < 0) {
			printf("O preco deve ser positivo ou nulo!");
		}
	} while(preco < 0);
}

void cadastrarQuantidade() {
	int quantidade;
	do {
		printf("Digite a quantidade do produto");
		scanf("%d", &quantidade);

		if (quantidade < 0) {
			printf("A quantidade deve ser positiva ou nula!");
		}
	} while(quantidade < 0);
}

void cadastrarDadosProduto() {
	cadastrarCodigo();
	cadastrarNome();
	cadastrarPreco();
	cadastrarQuantidade();
}
