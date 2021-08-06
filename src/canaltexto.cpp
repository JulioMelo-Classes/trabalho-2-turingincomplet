#include <string>

#include <vector>
#include "canaltexto.h"
using namespace std;

/*std::string nome;
std::vector<Mensagem> mensagens;*/
/*mensagem:
	std::string dataHora;
	int enviadaPor;
	std::string conteudo;*/
CanalTexto::CanalTexto(std::string nome_) {
	nome = nome_;
}
string CanalTexto::getnome() {
	return nome;
}
void CanalTexto::addmensagemc(Mensagem m) {
	mensagens.push_back(m);
}
bool CanalTexto::printmensagensc(std::vector<Usuario>& users) {
	if (mensagens.empty()) {
		return false;
	}
	for (auto it = mensagens.begin(); it != mensagens.end(); it++) {
		cout << users[it->enviadaPor].nome << it->dataHora << ": " << it->conteudo<<endl;
	}
	return true;
}