/*
 * biblioteca.c
 *
 *  Created on: 23 de out de 2019
 *      Author: n231013531
 */
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"


void menu() {
	char opcao;
	int quantidade;

	produtosStruct *produtos;

	do {
		printf("A - Criar estrutura para preenchimento \n");
		printf("B - Preencher dados \n");
		printf("C - Exibir produtos com estoque zerado \n");
		printf("D - Exibir produtos em estoque \n");
		printf("E - Finalizar \n");

		fflush(stdin);
		scanf("%c", &opcao);

		switch (opcao) {
			case 'A':
				quantidade = totalProdutos();
				 produtos = (produtosStruct*) malloc (sizeof(produtosStruct) * quantidade);
				 produtos->tamanho = quantidade;
				break;
			case 'B':
				cadastrarDadosProduto(produtos);
				break;
			case 'C':
				listarSemEstoque(produtos);
				break;
			case 'D':
				listarTodosProdutos(produtos);
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
		fflush(stdin);
		scanf("%d", &numero);
		if (numero < 1 && numero > 50) {
			printf("O numero deve ser entre 1 e 50!!!");
		}
	} while(numero < 1 && numero > 50);

	return numero;
}

int cadastrarCodigo() {
	int codigo;
	do {
		printf("Digite o numero do produto (1 a 50)");
		scanf("%d", &codigo);
		if (codigo < 1 && codigo > 50) {
			printf("O numero deve ser entre 1 e 50!!!");
		}
	} while(codigo < 1 && codigo > 50);

	return codigo;
}

void cadastrarNome(produtosStruct *produtos) {
	do {
		printf("Digite o nome do produto:");
		scanf("%s", *produtos->nome);
		if (produtos->nome == '\0') {
			printf("O nome do produto não pode ser nulo!");
		}
	} while(produtos->nome == '\0');
}

void cadastrarPreco(float *valor) {
	do {
		printf("Digite o preco do produto");
		scanf("%f", valor);

		if (*valor < 0) {
			printf("O preco deve ser positivo ou nulo!");
		}
	} while(*valor < 0);
}

void cadastrarQuantidade(int *valor) {
	do {
		printf("Digite a quantidade do produto");
		scanf("%d", valor);

		if (*valor < 0) {
			printf("A quantidade deve ser positiva ou nula!");
		}
	} while(*valor < 0);
}

void cadastrarDadosProduto(produtosStruct *produtos) {
	int i;
	for (i = 0; i < produtos->tamanho; i++) {
		produtos[i].codigo = cadastrarCodigo();
		cadastrarNome(produtos);
		cadastrarPreco(&produtos[i].preco);
		cadastrarQuantidade(&produtos[i].quantidade);

	}

}

void listarSemEstoque(produtosStruct *produtos) {
	int i;
		for (i = 0; i < produtos->tamanho; i++) {
			if (produtos[i].quantidade == 0) {
				printf("Produto %d sem estoque! \n", produtos[i].codigo);
			}
		}
	}

void listarTodosProdutos(produtosStruct *produtos) {
	int i;
	printf(" === Lista de produtos === ");
	for (i = 0; i < produtos->tamanho; i++) {
		printf("===================== \n");
		printf("Código: %d \n", produtos[i].codigo);
		printf("Nome: %s", *produtos[i].nome);
		printf("Preco: %f \n", produtos[i].preco);
		printf("Quantidade: %d \n", produtos[i].quantidade);
	}
}
