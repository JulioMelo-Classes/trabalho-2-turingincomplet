#pragma once
#include <string>
#include <ctime>
#include<sstream>
#include <iomanip>

class Mensagem{
public:
	std::string dataHora;
	int enviadaPor;
	std::string conteudo;

	/**
	 * @brief constroi uma mensagem dado seu conteudo e o id de quem a enviou
	*/
	Mensagem(std::string conteudo_, int enviadaPor_);
};

