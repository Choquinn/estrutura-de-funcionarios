#include "entrada.h"
#include "validacao.h"
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

bool lerInteiro(const char *mensagem, int *resultado, int minimo, int maximo) {
    if (resultado == NULL || minimo > maximo) {
        return false;
    }

    char entrada[64];
    int numero;

    while (true) {
        if (!lerLinha(mensagem, entrada, sizeof(entrada))) {
            if (feof(stdin) || ferror(stdin)) {
                return false;
            }

            printf("Entrada muito longa! Tente novamente.\n\n");
            continue;
        }

        if (!converterInteiro(entrada, &numero)) {
            printf("Entrada inválida! Digite um número inteiro.\n\n");
            continue;
        }

        if (numero < minimo || numero > maximo) {
            printf(
                "O número deve estar entre %d e %d.\n\n",
                minimo,
                maximo
            );
            continue;
        }

        *resultado = numero;

        return true;
    }
}

bool lerTextoObrigatorio(const char *mensagem, char *destino, size_t capacidade) {
    if (destino == NULL || capacidade < 2) {
        return false;
    }

    while (true) {
        if (!lerLinha(mensagem, destino, capacidade)) {
            if (feof(stdin) || ferror(stdin)) {
                return false;
            }

            printf("Texto muito longo! Tente novamente.\n\n");
            continue;
        }

        if (!textoObrigatorioValido(destino, capacidade)) {
            printf("Campo obrigatório! Digite um texto válido.\n\n");
            continue;
        }

        return true;
    }
}