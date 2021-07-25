#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;


/*std::vector<Servidor> servidores; //<! um vetor com todos os servidores
std::vector<Usuario> usuarios; //<! um vetor com todos os usuários cadastrados
std::map< int, std::pair<std::string, std::string> > usuariosLogados; //<! um vetor contendo os usuários que logaram no sistema*/


/*metodos auxiliares*/
int Sistema::finduser(Usuario targu) {
	int n = (int)usuarios.size();
	for (int ii = 0; ii < n; ii++) {
		if ((usuarios[ii].email == targu.email || targu.email.empty())
			&& (usuarios[ii].senha == targu.senha || targu.senha.empty())
			&& (usuarios[ii].nome == targu.nome || targu.nome.empty()))
			return usuarios[ii].id;
	}			
	return -1;
}

int Sistema::findserver(string nome) {
	int n = (int)servidores.size();
	for (int ii = 0; ii < n; ii++) {
		if (servidores[ii].getnome() == nome)
			return ii;
	}
	return -1;
}

bool Sistema::logado(int id) {
	if (usuariosLogados.find(id) == usuariosLogados.end()) {
		return false;
	}
	else return true;
}

/* COMANDOS */
string Sistema::quit() {
  return "Saindo do Concordo";
}



string Sistema::create_user (const string email, const string senha, const string nome) {
	Usuario tempU;
	tempU.email = email;
	int existe = finduser(tempU);
	if (existe>=0) {
		return "Usuário já existe!";
	}
	tempU.id = usuarios.size();
	tempU.nome=nome;
	tempU.senha=senha;
	usuarios.push_back(tempU);
	return "Usuário criado";
}

string Sistema::login(const string email, const string senha) {
	Usuario check;
	check.email = email;
	check.senha = senha;
	int id = finduser(check);
	if (id>=0) {
		pair<string, string> u;
		usuariosLogados[id] = u;
		return "Logado como "+email;
	}
	return "Senha ou usuário inválidos!";
}

string Sistema::disconnect(int id) {
	if (!logado(id)) {
		return "Não está conectado";
	}
	usuariosLogados.erase(id);
	return "Desconectando usuário "+ usuarios[id].email;
}

string Sistema::create_server(int id, const string nome) {
	if (!logado(id)) {
		return "Não está conectado";
	}
	int existe = findserver(nome);
	if (existe>=0) {
		return "Servidor com esse nome já existe";
	}
	Servidor temp(id, nome);
	servidores.push_back(temp);
	return "Servidor criado";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
	if (!logado(id)) {
		return "Não está conectado";
	}
	int serverid = findserver(nome);
	if (serverid <0) {
		return "Servidor '" +nome+"' não existe";
	}
	if (servidores[serverid].getid() != id) {
		return "Você não pode alterar a descrição de um servidor que não foi criado por você";
	}
	servidores[serverid].setdesc(descricao);
	return "Descrição do servidor '"+nome+"' modificada!";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
	if (!logado(id)) {
		return "Não está conectado";
	}
	int serverid = findserver(nome);
	if (serverid < 0) {
		return "Servidor '" + nome + "' não existe";
	}
	if (servidores[serverid].getid() != id) {
		return "Você não pode alterar o código de convite de um servidor que não foi criado por você";
	}
	servidores[serverid].setconvite(codigo);
	if (codigo.empty()) {
		return "Código de convite do servidor '" + nome + "' removido!";
	}
	else return "Código de convite do servidor '" + nome + "' modificado!";
}

string Sistema::list_servers(int id) {
	if (!logado(id)) {
		return "Não está conectado";
	}
	string out;
	int n = (int)servidores.size();
	for (int ii = 0; ii < n; ii++) {
		if (ii < n - 1)
			out = out + servidores[ii].getnome() + "\n";
		else out = out + servidores[ii].getnome();
	}
	return out;
}

string Sistema::remove_server(int id, const string nome) {
	if (!logado(id)) {
		return "Não está conectado";
	}
	int serverid = findserver(nome);
	if (serverid < 0) {
		return "Servidor '" + nome + "' não encontrado";
	}
	if (servidores[serverid].getid() != id) {
		return "Você não é o dono do servidor "+nome;
	}
	servidores.erase(servidores.begin() + id);
	return "Servidor '"+nome+"' removido";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
  return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server(int id, const string nome) {
  return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants(int id) {
  return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels(int id) {
  return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(int id, const string nome) {
  return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(int id, const string nome) {
  return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel(int id) {
  return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(int id, const string mensagem) {
  return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages(int id) {
  return "list_messages NÃO IMPLEMENTADO";
}




/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
