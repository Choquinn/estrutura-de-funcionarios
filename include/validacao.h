#ifndef VALIDACAO_H
#define VALIDACAO_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "funcionario.h"

bool anoBissexto(int ano);
bool dataValida(Data data);
bool textoObrigatorioValido(const char *texto, size_t capacidade);
bool numeroEnderecoValido(int num);
bool cpfFormatoValido(const char *cpf, size_t capacidade);
bool cpfValido(const char *cpf, size_t capacidade);
bool escolaridadeValida(Escolaridade escolaridade);
bool estadoCivilValido(EstadoCivil estado);
bool salarioValido(int64_t salarioCentavos);
bool converterSalario(const char *texto, int64_t *resultado);
int compararDatas(Data a, Data b);
bool datasFuncionarioValidas(Data nascimento, Data admissao, Data hoje);

typedef enum {
    VALIDACAO_OK,
    ERRO_FUNCIONARIO_NULO,
    ERRO_ID,
    ERRO_NOME,
    ERRO_CPF,
    ERRO_RUA,
    ERRO_BAIRRO,
    ERRO_COMPLEMENTO,
    ERRO_NUMERO,
    ERRO_ESTADO_CIVIL,
    ERRO_ESCOLARIDADE,
    ERRO_CARGO,
    ERRO_SALARIO,
    ERRO_DATAS
} ResultadoValidacao;

ResultadoValidacao validarFuncionario(const Funcionario *f, Data hoje);
bool funcionarioValido(const Funcionario *f, Data hoje);
const char *mensagemValidacaoFuncionario(ResultadoValidacao resultado);

#endif