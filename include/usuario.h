#ifndef USUARIO_H
#define USUARIO_H
#include <string>

class Usuario{
 public:
	int id;
	std::string nome;
	std::string email;
	std::string senha;

	int servern;

	/**
	 * @brief constroi um usuario dado seu email
	 *		@param email_ email do usuario a ser criado 
	*/
	Usuario(std::string email_);
	
};

#endif
