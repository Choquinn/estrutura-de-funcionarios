#include <stdio.h>
#include <assert.h>

#include "funcionario.h"
#include "validacao.h"

void testarDatas(void) {
    assert(anoBissexto(2024));
    assert(anoBissexto(2000));
    assert(!anoBissexto(1900));
    assert(!anoBissexto(2025));

    assert(dataValida((Data){29, 2, 2024}));
    assert(!dataValida((Data){29, 2, 2025}));
    assert(!dataValida((Data){31, 4, 2026}));
    assert(!dataValida((Data){0, 10, 2026}));
    assert(!dataValida((Data){10, 13, 2026}));
}

void testarTextos(void) {
    char nome[] = "Maria";
    char vazio[] = "";
    char espacos[] = "     ";
    char semTerminador[3] = {'A', 'B', 'C'};

    assert(textoObrigatorioValido(nome, sizeof(nome)));
    assert(!textoObrigatorioValido(vazio, sizeof(vazio)));
    assert(!textoObrigatorioValido(espacos, sizeof(espacos)));
    assert(!textoObrigatorioValido(semTerminador, sizeof(semTerminador)));
}

void testarEndereco(void) {
    assert(numeroEnderecoValido(100));
    assert(numeroEnderecoValido(0));
    assert(!numeroEnderecoValido(-1));
}

void testarCpf(void) {
    assert(cpfValido("12345678909", sizeof("12345678909")));
    assert(!cpfValido("00000000000", sizeof("00000000000")));
    assert(!cpfValido("12345678900", sizeof("12345678900")));
    assert(!cpfValido("1234567890", sizeof("1234567890")));
}

void testarEscolaridade(void) {
    assert(escolaridadeValida((Escolaridade){ANALFABETO, NAO_APLICAVEL}));
    assert(!escolaridadeValida((Escolaridade){ANALFABETO, COMPLETO}));
    assert(escolaridadeValida((Escolaridade){SUPERIOR, INCOMPLETO}));
    assert(!escolaridadeValida((Escolaridade){SUPERIOR, NAO_APLICAVEL}));
}

void testarEstadoCivil(void) {
    assert(estadoCivilValido(SOLTEIRO));
    assert(estadoCivilValido(CASADO));
    assert(!estadoCivilValido((EstadoCivil)99));
}

void testarSalario(void) {
    int64_t resultado = 0;
    bool convertido = converterSalario("1850,75", &resultado);
    assert(convertido);
    assert(resultado == 185075);   
    convertido = converterSalario("1500,999", &resultado);
    assert(!convertido);
    assert(!salarioValido(-100));
    assert(salarioValido(150000));
}

void testarFuncionario(void) {
    Data hoje = {21, 10, 2026};
    Funcionario f = {
        .id = 1,
        .nome = "Ingrid Larissa de Albuquerque Freitas",
        .cpf = "12345678909",

        .endereco = {
            .rua = "Rua Itaquaquecetuba",
            .numero = 69,
            .bairro = "Xinforinfula",
            .complemento = "Perto da Rebimboca da parafuseta"
        },

        .estadoCivil = SOLTEIRO,
        .dataNascimento = {15, 02, 2007},

        .escolaridade = {
            .nivel = SUPERIOR,
            .situacao = INCOMPLETO
        },

        .cargo = "Desenvolvedor de Casamentos no Diário",
        .salarioCentavos = 100099,
        .dataAdmissao = {10, 10, 2026}
    };

    assert(validarFuncionario(&f, hoje) == VALIDACAO_OK);
    f.id = -1;
    assert(validarFuncionario(&f, hoje) == ERRO_ID);
    f.id = 1;
    f.salarioCentavos = -100;
    assert(validarFuncionario(&f, hoje) == ERRO_SALARIO);
    f.salarioCentavos = 250000;
    f.escolaridade.situacao = NAO_APLICAVEL;
    f.escolaridade.situacao = COMPLETO;
    assert(validarFuncionario(&f, hoje) == VALIDACAO_OK);
}

int main(void) {
    testarDatas();
    testarTextos();
    testarEndereco();
    testarCpf();
    testarEscolaridade();
    testarEstadoCivil();
    testarSalario();
    testarFuncionario();

    printf("Todos os testes passaram!\n");

    return 0;
}