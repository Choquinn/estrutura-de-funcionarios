#include <stdio.h>
#include <inttypes.h>

#include "console.h"
#include "repositorio.h"
#include "funcionario.h"
#include "validacao.h"

int main(void) {
    configurarConsole();

    Funcionario f = {
        .id = 1,
        .nome = "Ingrid Larissa de Albuquerque Freitas",
        .cpf = "40028922012",

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

    printf("Sistema de Funcionários\n");
    printf("Armazenamento: %s\n\n", nomeRepositorio());

    printf("ID: %d\n", f.id);
    printf("Nome: %s\n", f.nome);
    printf("CPF: %s\n", f.cpf);
    printf("Cargo: %s\n", f.cargo);

    printf(
        "Salário: R$ %" PRId64 ",%02" PRId64 "\n",
        f.salarioCentavos / 100,
        f.salarioCentavos % 100
    );

    printf(
        "Nascimento: %02d/%02d/%04d\n",
        f.dataNascimento.dia,
        f.dataNascimento.mes,
        f.dataNascimento.ano
    );

    printf(
        "Escolaridade: %s %s\n",
        nivelEscolaridadeTexto(f.escolaridade.nivel),
        situacaoEscolaridadeTexto(f.escolaridade.situacao)
    );

    printf(
        "Estado civil: %s\n",
        estadoCivilTexto(f.estadoCivil)
    );

    Data teste1 = {29, 2, 2024};
    Data teste2 = {29, 2, 2025};
    Data teste3 = {31, 4, 2026};
    Data teste4 = {15, 10, 2000};

    printf("\nTestando validação de datas:\n\n");

    printf("29/02/2024: %s\n", dataValida(teste1) ? "Válida" : "Inválida");
    printf("29/02/2025: %s\n", dataValida(teste2) ? "Válida" : "Inválida");
    printf("31/04/2026: %s\n", dataValida(teste3) ? "Válida" : "Inválida");
    printf("15/10/2000: %s\n", dataValida(teste4) ? "Válida" : "Inválida");

    return 0;
}