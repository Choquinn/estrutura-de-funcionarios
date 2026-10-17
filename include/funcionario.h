#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char rua[81];
    int numero;
    char bairro[61];
    char complemento[81];
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

#endif