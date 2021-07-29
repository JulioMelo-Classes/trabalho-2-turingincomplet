#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <string>
#include <vector>

#include "canaltexto.h"

/*
CP1 classe servidor ok
*/
class Servidor{
private: 
	int usuarioDonoId;
	std::string nome;
	std::string descricao;
	std::string codigoConvite;
	std::vector<CanalTexto> canaisTexto;
	std::vector<int> participantesIDs;

public: 
	/**
	 * @brief constrói um servidor dado seu nome e o id do dono
	 *		@param usuarioDonoId_ id do usuario dono
	 *		@param nome_ nome do servidor
	*/
	Servidor(int usuarioDonoId_, std::string nome_);

	/**
	 * @brief retorna o nome do servidor
	 *		@return nome do servidor
	*/
	std::string getnome();

	/**
	 * @brief retorna o id do usuario dono
	 *		@return id do usuario dono
	*/
	int getid();

	/**
	 * @brief retorna a descricao do servidor
	 *		@return a descricao do servidor
	*/
	std::string getdesc();

	/**
	 * @brief seta a descricao do servidor
	 *		@param desc descricao a ser setada
	*/
	void setdesc(std::string desc);

	/**
	 * @brief retorna o codigoConvite do servidor
	 *		@return codigoConvite do servidor
	*/
	std::string getconvite();

	/**
	 * @brief seta o codigoConvite do servidor
	 *		@param convitecode codigoConvite a ser setado
	*/
	void setconvite(std::string convitecode);
};

#endif
