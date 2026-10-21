#include "entrada.h"
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

bool lerLinha(const char *mensagem, char *destino, size_t capacidade) {
    if (destino == NULL || capacidade < 2) return false;
    if (mensagem != NULL) {
        printf("%s", mensagem);
        fflush(stdout);
    }
    if (fgets(destino, capacidade, stdin) == NULL) {
        destino[0] = '\0';
        return false;
    }
    char *quebraLinha = strchr(destino, '\n');
    if (quebraLinha != NULL) {
        *quebraLinha = '\0';
        return true;
    }
    int caractere = getchar();
    if (caractere == '\n' || caractere == EOF) {
        return true;
    }
    while (caractere != '\n' && caractere != EOF) {
        caractere = getchar();
    }
    destino[0] = '\0';
    return false;
}

bool converterInteiro(const char *texto, int *resultado) {
    if (texto == NULL || resultado == NULL || *texto == '\0') return false;
    char *fim;
    errno = 0;
    long numero = strtol(texto, &fim, 10);
    if (fim == texto || *fim != '\0' || errno == ERANGE) return false;
    if (numero < INT_MIN || numero > INT_MAX) return false;
    *resultado = (int)numero;
    return true;
}