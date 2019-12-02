/*
 * biblioteca.h
 *
 *  Created on: 14 de nov de 2019
 *      Author: vinicius
 */

#ifndef HEADER_H_
#define HEADER_H_

#define RANDOM() rand()



//enum TIPOS_CARTAO { Universitario = 'U', Nacional = 'N', Internacional = 'I'};
//enum TIPOS_DEPENDENTE { Conguge = 'C', Filho = 'F', Enteado = 'E' };



typedef struct cliente cliente;
typedef struct dependente dependente;


struct cliente {
	char *nome[50];
	char codigo;
	char *dataNascimento;
	float limite;
	char TIPO_CARTAO;
	int quantidadeDependentes;
	cliente *proximo;
	dependente *listaDependentes;
};


struct dependente {
	char *nome[50];
	int codigo; /// ??
	char *dataNascimento;
	char TIPOS_DEPENDENTE;
	dependente *anterior;
	dependente *proximo;

};

void cadastrarNome();
cliente* inserirClienteFim(cliente *lista);
char* cadastrarNascimento(int dependenteOk);
void cadastrarLimite(cliente *cliente);
char cadastrarTipo();
void cadastrarQtdeDependente(cliente *cliente);
int obterIdade(char *dataNascimento);
dependente* inserirDependenteInicio(dependente *lista);
void cadastrarTipoDependente(char *tipoDependente);
void exibirClienteLista(cliente *cliente);
dependente* inserirDependenteInicio(dependente *lista);
void inserirDepententeEmClienteJaExistente(cliente *listaCliente);


#endif /* HEADER_H_ */
