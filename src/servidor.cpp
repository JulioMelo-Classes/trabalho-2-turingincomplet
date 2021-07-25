#include <string>
#include <vector>
#include "servidor.h"
using namespace std;

Servidor::Servidor(int usuarioDonoId_, string nome_) {
	usuarioDonoId = usuarioDonoId_;
	nome = nome_;
}
string Servidor::getnome() {
	return nome;
}
int  Servidor::getid() {
	return usuarioDonoId;
}
string Servidor::getdesc() {
	return descricao;
}
void Servidor::setdesc(string desc) {
	descricao = desc;
}
string Servidor::getconvite() {
	return codigoConvite;
}

void Servidor::setconvite(std::string convitecode) {
	codigoConvite = convitecode;
}

