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

#endif