cmake_minimum_required(VERSION 3.5)
project(concordo VERSION 0.1 LANGUAGES CXX )


### Executável
# Diretório contendo os .hpp
include_directories( include )

# Cria um executável com nome "concordo", adiciona neste executável os arquivos src/concordo.cpp src/sistema.cpp src/executor.cpp src/canaltexto.cpp src/mensagem.cpp src/servidor.cpp src/usuario.cpp
add_executable( concordo
                src/concordo.cpp
                src/sistema.cpp
		src/canaltexto.cpp
		src/mensagem.cpp
		src/servidor.cpp
		src/usuario.cpp
								src/executor.cpp )

# The end
