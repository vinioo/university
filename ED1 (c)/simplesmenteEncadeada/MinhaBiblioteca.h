/*
 * MinhaBiblioteca.h
 *
 *  Created on: 13 de nov de 2019
 *      Author: amanda.oliveira
 */

#ifndef MINHABIBLIOTECA_H_
#define MINHABIBLIOTECA_H_
//Macro
#define RANDOM rand()
#define RANDOMICO(x) rand() % x

//Estrutura e typedef

typedef struct cadastro cadastro;
struct cadastro{
	int codigo;
	cadastro *proximo;
};

//As linhas abaixo fazem a mesma declaração das linhas acima
/*
struct cadastro{
	int codigo;
	struct cadastro *proximo;
};
typedef struct cadastro cadastro;
*/

/*
typedef struct {
	int codigo;
	struct cadastro *proximo;
} cadastro;
*/


//Protótipo
void imprimir(cadastro *listaSimples);
cadastro* inserirInicio(cadastro *lista);
cadastro* inserirFim(cadastro *lista);
cadastro* inserirFimUltimo(cadastro *lista, cadastro **ultimo);
cadastro* excluirElemento (cadastro *lista, int cod);

#endif /* MINHABIBLIOTECA_H_ */
