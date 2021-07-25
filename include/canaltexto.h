#ifndef CANALTEXTO_H
#define CANALTEXTO_H
#include <string>
#include <vector>

#include "mensagem.h"

class CanalTexto{
private:
	std::string nome;
	std::vector<Mensagem> mensagens;
};

#endif
