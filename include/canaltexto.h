#ifndef CANALTEXTO_H
#define CANALTEXTO_H
#include <string>
#include <iostream>
#include <vector>

#include "mensagem.h"
#include "usuario.h"

class CanalTexto{
private:
	std::string nome; //<! nome do canaltexto
	std::vector<Mensagem> mensagens; //<! mensagems do canaltexto

public:
	/**
	 * @brief constroi um CanalTexto dado seu nome
	 *		@param nome_ o nome do CanalTexto a ser construido
	*/
	CanalTexto(std::string nome_);

	/**
	 * @brief retorna o nome do CanalTexto
	 *		@return o nome do CanalTexto
	*/
	std::string getnome();

	/**
	 * @brief adiciona uma mensagem ao vetor mensagems
	 *		@param m mensagem a ser adicionada
	*/
	void addmensagemc(Mensagem m);

	/**
	 * @brief imprime todas as mensagems do canaltexto
	 *		@param users vetor de usuarios que contem os nomes dos usuarios que mandaram mensagens no canaltexto
	 *		@return true se imprimiu alguma mensagem, false caso contrário
	*/
	bool printmensagensc(std::vector<Usuario>& users);
};

#endif
