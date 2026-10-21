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

bool lerData(const char *mensagem, Data *resultado) {
    if (resultado == NULL) return false;

    Data data;

    while (true) {
        if (mensagem != NULL) {
            printf("\n%s\n", mensagem);
        }

        if (!lerInteiro("Dia: ", &data.dia, 1, 31)) return false;
        if (!lerInteiro("Mês: ", &data.mes, 1, 12)) return false;
        if (!lerInteiro("Ano: ", &data.ano, 1, 9999)) return false;

        if (dataValida(data)) {
            *resultado = data;
            return true;
        }

        printf("\nData inválida! Tente novamente.\n");
    }
}

bool lerEndereco(Endereco *resultado) {
    if (resultado == NULL) return false;

    Endereco endereco = {0};

    printf("\nEndereço do funcionário\n\n");

    if (!lerTextoObrigatorio(
        "Rua: ", endereco.rua, sizeof(endereco.rua))) return false;

    if (!lerInteiro(
        "Número (0 para S/N): ",
        &endereco.numero, 0, INT_MAX)) return false;

    if (!lerTextoObrigatorio(
        "Bairro: ", endereco.bairro, sizeof(endereco.bairro))) return false;

    while (true) {
        if (lerLinha(
            "Complemento (opcional): ",
            endereco.complemento,
            sizeof(endereco.complemento))) {
            break;
        }

        if (feof(stdin) || ferror(stdin)) return false;

        printf("Complemento muito longo! Tente novamente.\n");
    }

    *resultado = endereco;
    return true;
}

bool lerEscolaridade(Escolaridade *resultado) {
    if (resultado == NULL) return false;

    Escolaridade escolaridade;
    int opcao;

    printf("\nEscolaridade\n\n");
    printf("0 - Analfabeto\n");
    printf("1 - Fundamental\n");
    printf("2 - Médio\n");
    printf("3 - Superior\n");
    printf("4 - Pós-graduação\n\n");

    if (!lerInteiro("Nível: ", &opcao, 0, 4)) return false;

    escolaridade.nivel = (NivelEscolaridade)opcao;

    if (escolaridade.nivel == ANALFABETO) {
        escolaridade.situacao = NAO_APLICAVEL;
    } else {
        printf("\n1 - Incompleto\n");
        printf("2 - Completo\n\n");

        if (!lerInteiro("Situação: ", &opcao, 1, 2)) return false;

        escolaridade.situacao = (SituacaoEscolaridade)opcao;
    }

    *resultado = escolaridade;
    return true;
}

bool lerEstadoCivil(EstadoCivil *resultado) {
    if (resultado == NULL) return false;

    int opcao;

    printf("\nEstado civil\n\n");
    printf("0 - Solteiro\n");
    printf("1 - Casado\n");
    printf("2 - Separado\n");
    printf("3 - Divorciado\n");
    printf("4 - Viúvo\n\n");

    if (!lerInteiro("Opção: ", &opcao, 0, 4)) return false;

    *resultado = (EstadoCivil)opcao;
    return true;
}