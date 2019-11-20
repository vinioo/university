/*
 * listas.h
 *
 *  Created on: 12 de nov de 2019
 *      Author: n231013531
 */

#ifndef LISTAS_H_
#define LISTAS_H_

#define RANDOM_NUMBER rand()
//#define RANDOMICO(x) rand() % y -> valor maximo (y)

	//typedef struct cadastro cadastro;
	//struct cadastro {
	//	int codigo;
	//	cadastro *proximo;
	//};

	typedef struct cadastroStruct cadastroStruct;
	struct cadastroStruct {
		int codigo;
		cadastroStruct *proximo;
	};

cadastroStruct* cadastrarInicioLista(cadastroStruct *lista);
void imprimirLista(cadastroStruct *lista);
cadastroStruct* inserirFimLista(cadastroStruct *lista);

#endif /* LISTAS_H_ */
