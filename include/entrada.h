#ifndef ENTRADA_H
#define ENTRADA_H

#include <stdbool.h>
#include <stddef.h>

bool lerLinha(const char *mensagem, char *destino, size_t capacidade);
bool converterInteiro(const char *texto, int *resultado);
bool lerInteiro(const char *mensagem, int *resultado, int minimo, int maximo);
bool lerTextoObrigatorio(const char *mensagem, char *destino, size_t capacidade);

#endif