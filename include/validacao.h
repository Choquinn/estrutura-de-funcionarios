#ifndef VALIDACAO_H
#define VALIDACAO_H

#include <stdbool.h>
#include <stddef.h>
#include "funcionario.h"

bool anoBissexto(int ano);
bool dataValida(Data data);
bool textoObrigatorioValido(const char *texto, size_t capacidade);

#endif