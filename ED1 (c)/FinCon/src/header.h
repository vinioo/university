/*
 * biblioteca.h
 *
 *  Created on: 14 de nov de 2019
 *      Author: vinicius
 */

#ifndef HEADER_H_
#define HEADER_H_

#define GERAR_CODIGO rand()

enum TIPOS_CARTAO { Universitario = 'U', Nacional = 'N', Internacional = 'I'};



typedef struct dadosCliente;
typedef struct dadosDependente;

struct {

} dadosDependente;

struct {
	char *nome[50];
	char GERAR_CODIGO;
	char *dataNascimento[8];
	float limite;
	enum TIPO_CARTAO;
	int quantidadeDependentes;
	dadosDependente *listaDependentes;

} dadosCliente;

#endif /* HEADER_H_ */
