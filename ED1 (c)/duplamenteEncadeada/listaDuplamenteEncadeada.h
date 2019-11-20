/*
 * listaDuplamenteEncadeada.h
 *
 *  Created on: 20 de nov de 2019
 *      Author: n231013531
 */

#ifndef LISTADUPLAMENTEENCADEADA_H_
#define LISTADUPLAMENTEENCADEADA_H_

#define RANDOM_NUMBER rand()

typedef struct codigos codigos;
struct codigos{
	int codigo;
	codigos *anterior;
	codigos *proximo;
};

codigos* inserirInicio(codigos *lista);
codigos* inserirFimLista(codigos *lista);
#endif /* LISTADUPLAMENTEENCADEADA_H_ */
