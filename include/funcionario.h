#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#define ENDERECO_S_NUM 0
#include <stdint.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char rua[80];
    int numero;
    char bairro[60];
    char complemento[80];
} Endereco;

typedef enum {
    ANALFABETO,
    FUNDAMENTAL,
    MEDIO,
    SUPERIOR,
    POSGRADUACAO
} NivelEscolaridade;

typedef enum {
    NAO_APLICAVEL,
    INCOMPLETO,
    COMPLETO
} SituacaoEscolaridade;

typedef struct {
    NivelEscolaridade nivel;
    SituacaoEscolaridade situacao;
} Escolaridade;

typedef enum {
    SOLTEIRO,
    CASADO,
    SEPARADO,
    DIVORCIADO,
    VIUVO
} EstadoCivil;

typedef struct {
    int id;
    char nome[100];
    char cpf[12];
    Endereco endereco;
    EstadoCivil estadoCivil;
    Data dataNascimento;
    Escolaridade escolaridade;
    char cargo[80];
    int64_t salarioCentavos;
    Data dataAdmissao;
} Funcionario;

const char *nivelEscolaridadeTexto(NivelEscolaridade nivel);
const char *situacaoEscolaridadeTexto(SituacaoEscolaridade situacao);
const char *estadoCivilTexto(EstadoCivil estado);

#endif