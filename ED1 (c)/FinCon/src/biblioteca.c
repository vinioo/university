/*
 * biblioteca.c
 *
 *  Created on: 14 de nov de 2019
 *      Author: vinicius
 */

#include "header.h"

void menu() {
	char opcao;
	int opcaoSubMenu;

	do {
		printf("A - Inserir \n B - Excluir \n C - Relatórios \n D - Finalizar ");
		scanf("%c", &opcao);
		switch (opcao) {
			case 'A':
				printf("1 - Efetuar inclusão de cliente \n 2 - Efetuar incusão de dependente");
				scanf("%d", &opcaoSubMenu);
				switch (opcaoSubMenu) {
					case 1:

						break;
					case 2:
						break;
					default:
						printf("Opção inválida!!!");
						break;
				}
				break;
			case 'B':
				printf("1 - Efetuar exclusão de cliente \n 2 - Efetuar exclusão de dependente");
				scanf("%d", &opcaoSubMenu);
				switch (opcaoSubMenu) {
					case 1:

						break;
					case 2:
						break;
					default:
						printf("Opção inválida!!!");
						break;
				}
				break;
			case 'C':
				printf("1  - Listar todos os dados dos clientes cadastrados e exibir a média dos limites \n 2 - Listar todos os dados de um cliente por código \n 3 - Listar clientes por tipo de cartão");
				scanf("%d", &opcaoSubMenu);
				switch (opcaoSubMenu) {
					case 1:

						break;
					case 2:
						break;
					case 3:
						break;
					default:
						printf("Opção inválida!!!");
						break;
				}
				break;
			default:
				printf("Opção inválida!!");
				break;
		}
	} while(opcao != 'D');


}


