#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <string>
#include <vector>
#include <ctime>

#include "canaltexto.h"
#include "usuario.h"

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
	 * @brief constrói um servidor dado seu nome e o id do usuario dono
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
	int getdonoid();

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

	/**
	 * @brief adiciona um id de usuario ao vetor participantesIDs
	 *		@param p id do usuario a ser adicionado
	*/
	void addparti(int p);

	/**
	 * @brief remove um id de usuario do vetor participantesIDs
	 *		@param p id de usuario a ser removido
	 *		@return true se o id de usuario estava presente no vetor participantesIDs ou false se não
	*/
	bool removeparti(int p);

	/**
	 * @brief reduz o contador de servidores entrados dos usuarios presentes em participantesIDs
	 *		@param users vetor de usuarios a ser fornecido
	*/
	void serverreduc(std::vector<Usuario>& users);

	/**
	 * @brief imprime todos os nomes dos usuarios presentes em participantesIDs
	 *		@param users vetor de usuarios a ser fornecido 
	 *		@return uma string com todos os nomes dos usuarios presentes em participantesIDs
	*/
	void printparti(std::vector<Usuario>& users);

	/**
	 * @brief imprime todos os nomes dos canais presentes em canaisTexto
	 * @return 
	*/
	void printcanais();

	/**
	 * @brief adiciona um canaltexto ao vetor canaisTexto
	 *		@param c canaltexto a ser adicionado
	*/
	void addcanal(CanalTexto c);

	/**
	 * @brief retorna o indice de posição de um canaltexto no vetor canaisTexto ou -1 se não encontrado
	 *		@param cname nome do canaltexto
	 *		@return o indice de posição do canaltexto no vetor canaisTexto ou -1 se não encontrado
	*/
	int findcanal(std::string cname);

	/**
	 * @brief adiciona uma mensagem em um canaltexto presente no vetor canaisTexto
	 *		@param conteudo conteudo da mensagem
	 *		@param id id do usuario que mandou a mensagem
	 *		@param cname nome do canaltexto a receber a mensagem
	*/
	void addmensagems(std::string conteudo, int id, std::string cname);

	/**
	 * @brief imprime as mensagems de algum canaltexto presente no vetor canaisTexto
	 *		@param cname nome do canaltexto
	 *		@param users vetor de usuarios que contem os nomes dos usuarios que mandaram mensagens
	 *		@return true se imprimiu alguma mensagem, false caso contrário
	*/
	bool printmensagenss(std::string cname, std::vector<Usuario>& users);
	
};

#endif
