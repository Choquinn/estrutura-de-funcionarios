#include <stdio.h>
#include <inttypes.h>

#include "console.h"
#include "repositorio.h"
#include "funcionario.h"

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

    return 0;
}