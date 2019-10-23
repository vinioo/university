/*
 * biblioteca.h
 *
 *  Created on: 23 de out de 2019
 *      Author: n231013531
 */
#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

	typedef struct {
		char *nome[40];
		int codigo;
		float preco;
		int quantidade;
		int tamanho;
	} produtosStruct;

void menu();
int cadastrarCodigo();
void cadastrarNome();
void cadastrarPreco(float *valor);
void cadastrarQuantidade(int *valor);
int totalProdutos();
void listarSemEstoque(produtosStruct *produtos);
void cadastrarDadosProduto(produtosStruct *produtos);
void listarTodosProdutos(produtosStruct *produtos);
void cadastrarNome(produtosStruct *produtos);



#endif /* BIBLIOTECA_H_ */
