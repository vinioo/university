/*
 * biblioteca.c
 *
 *  Created on: 14 de nov de 2019
 *      Author: vinicius
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

const int QUANTIDADE_DEPENTENTES = 2;
const int ANO_ATUAL = 2019;

void menu() {
	char opcao;
	int opcaoSubMenu;
	cliente *cliente = NULL;

	do {
		printf("\n ================= MENU =================");
		printf(
				"\n A - Inserir \n B - Excluir \n C - Relatórios \n D - Finalizar ");
		fflush(stdin);
		scanf(" %c", &opcao);
		switch (opcao) {
		case 'A':
			do {
				printf(" ================= SUBMENU A ================= ");
				printf(
						"\n 1 - Efetuar inclusão de cliente \n 2 - Efetuar incusão de dependente");
				scanf("%d", &opcaoSubMenu);
				switch (opcaoSubMenu) {
				case 1:
					printf(
							" ================= INSERIR CLIENTE ================= ");
					cliente = inserirClienteFim(cliente);
					puts("Cliente inserido com sucesso!");
					break;
				case 2:
					printf(
							" ================= INSERIR DEPENDENTE ================= ");
					inserirDepententeEmClienteJaExistente(cliente);
					break;
				}
			} while (opcaoSubMenu != 1 && opcaoSubMenu != 2);
			break;
		case 'B':
			printf(
					"1 - Efetuar exclusão de cliente \n 2 - Efetuar exclusão de dependente");
			scanf("%d", &opcaoSubMenu);
			switch (opcaoSubMenu) {
			case 1:
				cliente = excluirCliente(cliente);
				break;
			case 2:
				cliente->listaDependentes = excluirDependente(
						cliente->listaDependentes);
				break;
			}
			break;
		case 'C':
			printf(
					" 1  - Listar todos os dados dos clientes cadastrados e exibir a média dos limites \n 2 - Listar todos os dados de um cliente por código \n 3 - Listar clientes por tipo de cartão");
			scanf("%d", &opcaoSubMenu);
			switch (opcaoSubMenu) {
			case 1:
				exibirClienteLista(cliente);
				break;
			case 2:
				exibirClientePorCodigo(cliente);
				break;
			case 3:
				exibirClientePorCartao(cliente);
				break;
			}
			break;
		case 'D':
				puts("Programa finalizado.");
			break;
		default:
			printf("\n Opção inválida!!");
			break;
		}
	} while (opcao != 'D');

}

cliente* inserirClienteFim(cliente *lista) {
	cliente *novo = malloc(sizeof(lista));

	cadastrarNome(novo->nome, "\n Digite o nome do cliente: ");
	//novo->codigo = "a"; //TODO: Concatenar com a primeira letra do nome
	novo->dataNascimento = cadastrarNascimento(0);
	cadastrarTipo();
	cadastrarLimite(novo);
	cadastrarQtdeDependente(novo);
	novo->proximo = NULL;

	if (lista == NULL) {
		return novo;
	} else {
		cliente *tmp = lista;
		while (tmp->proximo != NULL) {
			tmp = tmp->proximo;
		}
		tmp->proximo = novo;
		return lista;
	}
}

void cadastrarNome(char *nome, char *texto) {
	do {
		printf("%s \n", texto);
		fflush(stdin);
		scanf("%s", nome);

		if (strlen(nome) > 50) {
			printf(
					"\n ERRO! O nome do cliente deve ter no máximo 50 caracteres! \n");
		}
	} while (strlen(nome) > 50);

}

char* cadastrarNascimento(int dependenteOk) {
	char *dataNascimento = malloc(sizeof(char) * 10);
	int error = 1, idade;
	do {
		printf("Digite o ano de nascimento: \n");
		scanf("%s", dataNascimento);
		fflush(stdin);

		idade = obterIdade(dataNascimento);

		if (dataNascimento[2] != '/' || dataNascimento[5] != '/'
				|| strlen(dataNascimento) > 10) {
			printf("\n ERRO! A data deve ser no formato DD/MM/YYYY");
		} else {
			error = 0;
		}

		if (dependenteOk == 1) {
			if (idade < 0 || idade > 100) {
				printf(
						"\n ERRO! A idade para dependente deve ser entre 0 e 100 anos.");
			}
		} else {
			if (idade < 18 || idade > 100) {
				printf(
						"\n ERRO! A idade para cliente deve ser entre 0 e 100 anos.");
			}
		}

	} while (error == 1);

	return dataNascimento;
}

void cadastrarLimite(cliente *cliente) {
	int idade = obterIdade(cliente->dataNascimento);

	if (idade >= 18 && idade <= 40) {
		cliente->limite = 10000;
	} else if (idade >= 41 && idade <= 60) {
		cliente->limite = 15000;
	} else if (idade >= 61 && idade < 75) {
		cliente->limite = 5000;
	} else if (idade >= 75) {
		cliente->limite = 2500;
	} else {
		cliente->limite = 0;
	}

	if (cliente->TIPO_CARTAO == 'N') {
		cliente->limite = cliente->limite * 1.05;
	} else if (cliente->TIPO_CARTAO == 'I') {
		cliente->limite = cliente->limite * 1.20;
	}
}

int obterIdade(char *dataNascimento) {
	char ano[4];

	strncpy(ano, dataNascimento + 6, 4);

	return ANO_ATUAL - atoi(ano);
}

char cadastrarTipo() {
	char tipoCartao;
	do {
		puts(
				"Digite o tipo do cartão:\nU - Universitário | N - Nacional | I - Internacional");
		fflush(stdin);
		scanf(" %c", &tipoCartao);
		if (tipoCartao != 'U' && tipoCartao != 'N' && tipoCartao != 'I') {
			printf("\n Tipo inválido!!!");
		}
	} while (tipoCartao != 'U' && tipoCartao != 'N' && tipoCartao != 'I');

	return tipoCartao;
}

void cadastrarQtdeDependente(cliente *cliente) {
	int quantidadeDependentes, i;
	dependente *listaDependentes = NULL;
	do {
		printf("Digite a quantidade de dependentes do cliente %s ",
				cliente->nome);
		fflush(stdin);
		scanf("%d", &quantidadeDependentes);

		if (quantidadeDependentes > 2) {
			printf(" ERRO! O cliente deve possuir no máximo 2 dependentes!");
		}
	} while (quantidadeDependentes > 2);
	cliente->quantidadeDependentes = quantidadeDependentes;

	for (i = 0; i < quantidadeDependentes; i++) {
		cliente->listaDependentes = inserirDependenteInicio(listaDependentes);
	}
}

dependente* inserirDependenteInicio(dependente *lista) {
	dependente *novo = malloc(sizeof(dependente));

	cadastrarNome(novo->nome, "Digite o nome do dependente:");
	//novo->codigo = "a"; //TODO: Concatenar com a primeira letra do nome
	novo->dataNascimento = cadastrarNascimento(1);
	cadastrarTipoDependente(novo->TIPOS_DEPENDENTE);
	novo->proximo = lista;
	novo->anterior = NULL;

	if (lista != NULL) {
		lista->anterior = novo;
	}
	return novo;

}

void inserirDepententeEmClienteJaExistente(cliente *listaCliente) {
	int codigoCliente, encontrou = 0;
	puts("Digite o código do cliente que deseja inserir depententes:");
	scanf("%d", &codigoCliente);

	while (listaCliente != NULL) {
		if (listaCliente->codigo == codigoCliente) {
			if (listaCliente->quantidadeDependentes >= 2) {
				puts("O Cliente pode ter no máximo 2 dependentes!!");
				break;
			} else {
				encontrou = 1;
				listaCliente->listaDependentes = inserirDependenteInicio(
						listaCliente->listaDependentes);
				puts("dependente inserido com sucesso!");
			}

		}
		if (listaCliente->proximo != NULL) {
			exibirClienteLista(listaCliente->proximo);
		} else {
			if (encontrou == 0) {
				puts("Cliente não encontrado!");

			}
			break;
		}
	}

}

void cadastrarTipoDependente(char *tipoDependente) {
	char tipo;
	do {
		printf(
				"Digite o tipo do dependente:\n C - Conjuge | F - Filho | E - Enteado \n");
		fflush(stdin);
		scanf(" %c", &tipo);

		if (tipo != 'C' && tipo != 'F' && tipo != 'E') {
			printf("\n Tipo inválido!!!");
		}
	} while (tipo != 'C' && tipo != 'F' && tipo != 'E');

	tipoDependente = tipo;
}

void exibirCliente(cliente *cliente) {
	printf("Nome do Cliente: %s", cliente->nome);
	printf("\nCódigo do Cliente: %d", cliente->codigo);
	printf("\nData de nascimento do Cliente: %s", cliente->dataNascimento);
	printf("\nLimite do Cliente: R$%.2f", cliente->limite);
	printf("\nTipo cartão: %c", cliente->TIPO_CARTAO);
	printf("\nQuantidade de dependente: %i", cliente->quantidadeDependentes);
}

void exibirClienteLista(cliente *listaCliente) {
	int quantidade = 0;
	float media = 0;
	puts("\n\n\nCliente(s)\n");
	while (listaCliente != NULL) {
		exibirCliente(listaCliente);
		media += listaCliente->limite;
		quantidade++;
		if (listaCliente->proximo != NULL) {
			exibirClienteLista(listaCliente->proximo);

		} else {
			media = media / quantidade;
			printf("\n\n A média dos limites é de %.2f", media);
			break;
		}
	}
}

void exibirClientePorCodigo(cliente *listaCliente) {
	int codigo; //TODO: TROCAR PARA CHAR
	puts("\n\n\nCliente(s) por código\n");
	puts("Digite o código desejado:");
	scanf("%d", &codigo);
	while (listaCliente != NULL) {
		if (listaCliente->codigo == codigo) {
			exibirCliente(listaCliente);
		}
		puts("\n");
		if (listaCliente->proximo != NULL) {
			exibirClienteLista(listaCliente->proximo);

		} else {
			break;
		}
	}
}

void exibirClientePorCartao(cliente *listaCliente) {
	char tipoCartao;
	puts("\n\n\nCliente(s) por código\n");
	puts("Digite o código desejado:");
	scanf(" %c", &tipoCartao);
	while (listaCliente != NULL) {
		if (listaCliente->TIPO_CARTAO == tipoCartao) {
			exibirCliente(listaCliente);
		}
		puts("\n");
		if (listaCliente->proximo != NULL) {
			exibirClienteLista(listaCliente->proximo);

		} else {
			break;
		}
	}
}

cliente* excluirCliente(cliente *lista) {
	cliente *tmp = lista, *anterior = NULL;
	int codigoCliente; //TODO: TROCAR PARA CHAR
	puts("\nDigite o código do cliente que deseja excluir:");
	scanf("%d", &codigoCliente);

	while (tmp != NULL) {
		if (tmp->codigo == codigoCliente) {
			if (anterior != NULL) {
				anterior->proximo = tmp->proximo;
			} else {
				lista = lista->proximo;
			}

			free(tmp);
			break;
		} else {
			anterior = tmp;
			tmp = tmp->proximo;
		}
	}
	return lista;

}

dependente* excluirDependente(dependente *listaDependente) {
	dependente *tmp = listaDependente;
	int cod; //TODO: trocar para char

	puts("Digite o código do dependente que deseja excluir:");
	scanf("%d", &cod);

	while (tmp != NULL) {
		if (tmp->codigo == cod) {
			if (tmp->anterior == NULL) {
				if (tmp->proximo != NULL) {
					tmp->proximo->anterior = NULL;
				}

				listaDependente = listaDependente->proximo;

				free(tmp);

				return listaDependente;
			} else {
				tmp->anterior->proximo = tmp->proximo;
				if (tmp->proximo != NULL) {
					tmp->proximo->anterior = tmp->anterior;
				}
				free(tmp);

				return listaDependente;
			}

		} else {
			tmp = tmp->proximo;
		}
	}

	return listaDependente;
}
