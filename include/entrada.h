#ifndef ENTRADA_H
#define ENTRADA_H

#include <stdbool.h>
#include <stddef.h>
#include "funcionario.h"

bool lerLinha(const char *mensagem, char *destino, size_t capacidade);
bool converterInteiro(const char *texto, int *resultado);
bool lerInteiro(const char *mensagem, int *resultado, int minimo, int maximo);
bool lerTextoObrigatorio(const char *mensagem, char *destino, size_t capacidade);
bool lerData(const char *mensagem, Data *resultado);
bool lerEndereco(Endereco *resultado);
bool lerEscolaridade(Escolaridade *resultado);
bool lerEstadoCivil(EstadoCivil *resultado);
bool lerCpf(char *destino, size_t capacidade);
bool lerSalario(int64_t *resultado);
bool lerFuncionarioDados(Funcionario *resultado, Data hoje);

#endif