#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

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
	Usuario tempU(email);
	int existe = finduser(tempU);
	if (existe>=0) {
		return "Usuário já existe!";
	}
	tempU.id = (int)usuarios.size();
	tempU.nome=nome;
	tempU.senha=senha;
	usuarios.push_back(tempU);
	return "Usuário criado";
}

string Sistema::login(const string email, const string senha) {
	Usuario check(email);
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
	if (servidores[serverid].getdonoid() != id) {
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
	if (servidores[serverid].getdonoid() != id) {
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
		return "Usuário não está logado";
	}
	string out;
	int n = (int)servidores.size();
	for (int ii = 0; ii < n; ii++) {
		cout << servidores[ii].getnome() <<endl;
	}
	return "";
}

string Sistema::remove_server(int id, const string nome) {
	if (!logado(id)) {
		return "Não está conectado";
	}
	int serverid = findserver(nome);
	if (serverid < 0) {
		return "Servidor '" + nome + "' não encontrado";
	}
	if (servidores[serverid].getdonoid() != id) {
		return "Você não é o dono do servidor "+nome;
	}
	servidores[serverid].serverreduc(usuarios);
	for (auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++)
		if (it->second.first == nome) {
			pair<string, string> u;
			it->second = u;
		}
	servidores.erase(servidores.begin() + serverid);
	return "Servidor '"+nome+"' removido";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
	if (!logado(id)) {
		return "Não está conectado";
	}
	int serverid = findserver(nome);
	if (serverid < 0) {
		return "Servidor '" + nome + "' não encontrado";
	}
	pair<string, string> u(nome, "");
	if (servidores[serverid].getdonoid() == id) {
		usuariosLogados[id]=u;
	}
	else if (servidores[serverid].getconvite() == "" || servidores[serverid].getconvite() == codigo) {
		usuariosLogados[id] = u;
	}
	else return "Servidor requer código de convite";
	usuarios[id].servern++;
	servidores[serverid].addparti(id);
	return "Entrou no servidor com sucesso";
}

string Sistema::leave_server(int id, const string nome) {
	if (!logado(id)) {
		return "Não está conectado";
	}
	if (usuarios[id].servern == 0) {
		return "Você não está em qualquer servidor";
	}
	int serverid = findserver(nome);
	if (serverid < 0) {
		return "Servidor '" + nome + "' não encontrado";
	}
	bool check;
	check=servidores[serverid].removeparti(id);
	if (check) {
		if (usuariosLogados[id].first == nome) {
			pair<string, string> u;
			usuariosLogados[id] = u;
		}
		usuarios[id].servern--;
		return "Saindo do servidor " + nome;
	}
	else return "Você não está conectado no servidor";
}

string Sistema::list_participants(int id) {
	if (!logado(id)) {
		return "Não está conectado";
	}
	if (usuariosLogados[id].first == "") {
		return "Usuario não está vizualizando nenhum servidor";
	}
	int serverid = findserver(usuariosLogados[id].first);
	servidores[serverid].printparti(usuarios);
	return "";
}

string Sistema::list_channels(int id) {
	if (!logado(id)) {
		return "Não está conectado";
	}
	if (usuariosLogados[id].first == "") {
		return "Usuario não está vizualizando nenhum servidor";
	}
	int serverid = findserver(usuariosLogados[id].first);
	servidores[serverid].printcanais();
	return"";
}

string Sistema::create_channel(int id, const string nome) {
	if (!logado(id)) {
		return "Não está conectado";
	}
	if (usuariosLogados[id].first == "") {
		return "Usuario não está vizualizando nenhum servidor";
	}
	int serverid = findserver(usuariosLogados[id].first);
	int existe=servidores[serverid].findcanal(nome);
	if (existe>=0) {
		return "Canal de texto '" + nome + "' já existe!";
	}
	CanalTexto ct(nome);
	servidores[serverid].addcanal(ct);
	return "Canal de texto '"+nome+"' criado";
}

string Sistema::enter_channel(int id, const string nome) {
	if (!logado(id)) {
		return "Não está conectado";
	}
	if (usuariosLogados[id].first == "") {
		return "Usuario não está vizualizando nenhum servidor";
	}
	int serverid = findserver(usuariosLogados[id].first);
	int existe = servidores[serverid].findcanal(nome);
	if (existe<0) {
		return "Canal '"+nome+"' não existe";
	}
	usuariosLogados[id].second = nome;
	return "Entrou no canal '"+nome+"'";
}

string Sistema::leave_channel(int id) {
	if (!logado(id)) {
		return "Não está conectado";
	}
	if (usuariosLogados[id].second == "") {
		return "Você não está em nenhum  canal";
	}
	usuariosLogados[id].second = "";
	return "Saindo do canal";
}

string Sistema::send_message(int id, const string mensagem) {
	if (!logado(id)) {
		return "Não está conectado";
	}
	if (usuariosLogados[id].second == "") {
		return "Você não está em nenhum  canal";
	}
	int serverid = findserver(usuariosLogados[id].first);
	string nomecanal = usuariosLogados[id].second;
	servidores[serverid].addmensagems(mensagem, id, nomecanal);
	return "";
}

string Sistema::list_messages(int id) {
	if (!logado(id)) {
		return "Não está conectado";
	}
	if (usuariosLogados[id].second == "") {
		return "Você não está em nenhum  canal";
	}
	int serverid = findserver(usuariosLogados[id].first);
	string nomecanal = usuariosLogados[id].second;
	bool printed=servidores[serverid].printmensagenss(nomecanal, usuarios);
	if (printed) {
		return "";
	}
	else return "Sem mensagens para exibir";
}




/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
