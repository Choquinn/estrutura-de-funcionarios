#include "funcionario.h"

const char *nivelEscolaridadeTexto(NivelEscolaridade nivel) {
    switch (nivel) {
        case ANALFABETO:
            return "Analfabeto";
        break;
        case FUNDAMENTAL:
            return "Fundamental";
        break;
        case MEDIO:
            return "Ensino Médio";
        break;
        case SUPERIOR:
            return "Ensino Superior";
        break;
        case POSGRADUACAO:
            return "Pós-Graduação";
        break;
        default:
            return "Desconhecido";
    }
}

const char *situacaoEscolaridadeTexto(SituacaoEscolaridade situacao) {
    switch (situacao) {
        case NAO_APLICAVEL:
            return "Não Aplicável";
        break;
        case INCOMPLETO:
            return "Incompleto";
        break;
        case COMPLETO:
            return "Completo";
        break;
        default:
            return "Desconhecido";
    }
}

const char *estadoCivilTexto(EstadoCivil estado) {
    switch (estado) {
        case SOLTEIRO:
            return "Solteiro";
        break;
        case CASADO:
            return "Casado";
        break;
        case SEPARADO:
            return "Separado";
        break;
        case DIVORCIADO:
            return "Divorciado";
        break;
        case VIUVO:
            return "Viuvo";
        break;
        default:
            return "Desconhecido";
    }
}