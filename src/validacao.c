#include "validacao.h"
#include <ctype.h>

bool anoBissexto(int ano) {
    return ano > 0 && ((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0));
}

bool dataValida(Data data) {
    if (data.ano < 1 || data.ano > 9999 ||
        data.mes < 1 || data.mes > 12 ||
        data.dia < 1) {
            return false;
    }

    const int diasMes[12] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    int maxDias = diasMes[data.mes - 1];

    if (data.mes == 2 && anoBissexto(data.ano)) {
        maxDias = 29;
    }

    return data.dia <= maxDias;
}

bool textoObrigatorioValido(const char *texto, size_t capacidade) {
    if (texto == NULL || capacidade == 0) return false;

    size_t tamanho = 0;
    bool possuiConteudo = false;

    while (tamanho < capacidade && texto[tamanho] != '\0') {
        if (!isspace((unsigned char)texto[tamanho])) possuiConteudo = true;
        tamanho++;
    }

    return tamanho > 0 && tamanho < capacidade && possuiConteudo;
}