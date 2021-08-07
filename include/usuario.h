#ifndef USUARIO_H
#define USUARIO_H
#include <string>

class Usuario{
 public:
	int id; //<! id do usuario 
	std::string nome; //<! nome do usuario
	std::string email; //<! email do usuario
	std::string senha; //<! senha do usuario

	int servern; //<! contador de servidores entrados

	/**
	 * @brief constroi um usuario dado seu email
	 *		@param email_ email do usuario a ser criado 
	*/
	Usuario(std::string email_);
	
};

#endif
