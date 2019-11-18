/*
 * biblioteca.h
 *
 *  Created on: 14 de nov de 2019
 *      Author: vinicius
 */

#ifndef HEADER_H_
#define HEADER_H_

#define RANDOM() rand()

enum TIPOS_CARTAO { Universitario = 'U', Nacional = 'N', Internacional = 'I'};
enum TIPOS_DEPENDENTE { Conguge = 'C', Filho = 'F', Enteado = 'E' };



typedef struct dadosCliente;
typedef struct dependente;

struct dependente {
	char *nome[50];
	int codigo; /// ??
	char *dataNascimento[8];
	enum TIPOS_DEPENDENTE;
};

struct dadosCliente {
	char *nome[50];
	char RANDOM;
	char *dataNascimento[8];
	float limite;
	enum TIPO_CARTAO;
	int quantidadeDependentes;
//	dependente  *listaDependentes; // ??

};



#endif /* HEADER_H_ */
