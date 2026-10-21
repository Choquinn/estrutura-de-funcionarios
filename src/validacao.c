#include "validacao.h"
#include "funcionario.h"
#include <ctype.h>
#include <string.h>

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

bool numeroEnderecoValido(int num) {
    return num >= ENDERECO_S_NUM;
}

bool cpfFormatoValido(const char *cpf, size_t capacidade) {
    if (cpf == NULL || capacidade < 12) return false;

    for (int i = 0; i < 11; i++) {
        if (cpf[i] < '0' || cpf[i] > '9') return false;
    }

    return cpf[11] == '\0';
}

bool cpfValido(const char *cpf, size_t capacidade) {
    if (!cpfFormatoValido(cpf, capacidade)) return false;

    bool todosIguais = true;

    for (int i = 0; i < 11; i++) { 
        if (cpf[i] != cpf[0]) {
            todosIguais = false;
            break;
        }
    }

    if (todosIguais) return false;

    int soma = 0;

    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }

    int resto = soma % 11;
    int primeiroDigito = resto < 2 ? 0 : 11 - resto;

    if (primeiroDigito != cpf[9] - '0') return false;

    soma = 0;

    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }

    resto = soma % 11;
    int segundoDigito = resto < 2 ? 0 : 11 - resto;

    return segundoDigito == cpf[10] - '0';
}

bool escolaridadeValida(Escolaridade escolaridade) {
    if (escolaridade.nivel < ANALFABETO || escolaridade.nivel > POSGRADUACAO) return false;
    if (escolaridade.situacao < NAO_APLICAVEL || escolaridade.situacao > COMPLETO) return false;
    if (escolaridade.nivel == ANALFABETO) return escolaridade.situacao == NAO_APLICAVEL;
    return escolaridade.situacao == INCOMPLETO || escolaridade.situacao == COMPLETO;
}

bool estadoCivilValido(EstadoCivil estado) {
    switch (estado) {
        case SOLTEIRO:
        case CASADO:
        case SEPARADO:
        case DIVORCIADO:
        case VIUVO:
            return true;
        default:
            return false;
    }
}

bool salarioValido(int64_t salarioCentavos) {
    return salarioCentavos >= 0;
}

bool converterSalario(const char *texto, int64_t *resultado) {
    if (texto == NULL || resultado == NULL) {
        return false;
    }

    if (*texto < '0' || *texto > '9') {
        return false;
    }

    int64_t reais = 0;
    int64_t centavos = 0;

    while (*texto >= '0' && *texto <= '9') {
        int digito = *texto - '0';
        if (reais > (INT64_MAX - digito) / 10) {
            return false;
        }
        reais = reais * 10 + digito;
        texto++;
    }

    if (*texto == ',' || *texto == '.') {
        texto++;

        if (*texto < '0' || *texto > '9') return false;
        centavos = (*texto - '0') * 10;
        texto++;

        if (*texto >= '0' && *texto <= '9') {
            centavos += *texto - '0';
            texto++;
        }
    }

    if (*texto != '\0') {
        return false;
    }

    if (reais > (INT64_MAX - centavos) / 100) return false;

    *resultado = reais * 100 + centavos;

    return true;
}

int compararDatas(Data a, Data b) {
    if (a.ano < b.ano) return -1;
    if (a.ano > b.ano) return 1;
    
    if (a.mes < b.mes) return -1;
    if (a.mes > b.mes) return 1;

    if (a.dia < b.dia) return -1;
    if (a.dia < b.dia) return 1;

    return 0;
}

bool datasFuncionarioValidas(Data nascimento, Data admissao, Data hoje) {
    if (!dataValida(nascimento) || !dataValida(admissao) || !dataValida(hoje)) return false;
    if (compararDatas(nascimento, admissao) > 0) return false;
    if (compararDatas(admissao, hoje) > 0) return false;

    return true;
}

ResultadoValidacao validarFuncionario(const Funcionario *f, Data hoje) {
    if (f == NULL) return ERRO_FUNCIONARIO_NULO;
    if (f->id <= 0) return ERRO_ID;
    if (!textoObrigatorioValido(f->nome, sizeof(f->nome))) return ERRO_NOME;
    if (!cpfValido(f->cpf, sizeof(f->cpf))) return ERRO_CPF;
    if (!textoObrigatorioValido(f->endereco.rua, sizeof(f->endereco.rua))) return ERRO_RUA;
    if (!textoObrigatorioValido(f->endereco.bairro, sizeof(f->endereco.bairro))) return ERRO_BAIRRO;
    if (memchr(f->endereco.complemento, '\0', sizeof(f->endereco.complemento)) == NULL) return ERRO_COMPLEMENTO;
    if (!numeroEnderecoValido(f->endereco.numero)) return ERRO_NUMERO;
    if (!estadoCivilValido(f->estadoCivil)) return ERRO_ESTADO_CIVIL;
    if (!escolaridadeValida(f->escolaridade)) return ERRO_ESCOLARIDADE;
    if (!textoObrigatorioValido(f->cargo, sizeof(f->cargo))) return ERRO_CARGO;
    if (!salarioValido(f->salarioCentavos)) return ERRO_SALARIO;
    if (!datasFuncionarioValidas(f->dataNascimento, f->dataAdmissao, hoje)) return ERRO_DATAS;

    return VALIDACAO_OK;
}

bool funcionarioValido(const Funcionario *f, Data hoje) {
    return validarFuncionario(f, hoje) == VALIDACAO_OK;
}

const char *mensagemValidacaoFuncionario(ResultadoValidacao resultado) {
    switch (resultado) {
        case VALIDACAO_OK:
            return "Funcionário válido.";
        
        case ERRO_FUNCIONARIO_NULO:
            return "Funcionário não informado.";

        case ERRO_ID:
            return "ID inválido";
        
        case ERRO_NOME:
            return "Nome inválido.";

        case ERRO_CPF:
            return "CPF inválido.";

        case ERRO_RUA:
            return "Rua inválida.";

        case ERRO_BAIRRO:
            return "Bairro inválido.";

        case ERRO_COMPLEMENTO:
            return "Complemento inválido.";

        case ERRO_NUMERO:
            return "Número do endereço inválido.";

        case ERRO_ESTADO_CIVIL:
            return "Estado civil inválido";

        case ERRO_ESCOLARIDADE:
            return "Escolaridade inválida.";

        case ERRO_CARGO:
            return "Cargo inválido";

        case ERRO_SALARIO:
            return "Salário inválido";

        case ERRO_DATAS:
            return "Datas de nascimento ou admissão inválidas";

        default:
            return "Erro de validação desconhecido.";
    }
}

