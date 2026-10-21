#include "entrada.h"
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