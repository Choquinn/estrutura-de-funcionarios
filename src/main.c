#include <stdio.h>
#include "console.h"
#include "repositorio.h"
#include "funcionario.h"

int main(void) {
    configurarConsole();

    Data dataNasc = {15, 2, 2007};
    Endereco endereco = {
        .rua = "Rua Itaquaquecetuba",
        .numero = 69,
        .bairro = "Xinforinfula",
        .complemento = "Perto da Rebimboca da parafuseta"
    };
    Escolaridade escolaridade = {
        .nivel = SUPERIOR,
        .situacao = INCOMPLETO
    };

    printf("Sistema de funcionários\n");
    printf("Armazenamento: %s\n", nomeRepositorio());
    
    printf("Data de nascimento: %02d/%02d/%04d\n", dataNasc.dia, dataNasc.mes, dataNasc.ano);
    printf("\nEndereço do funcionário:\n");
    printf("Rua: %s\n", endereco.rua);
    printf("Número: %d\n", endereco.numero);
    printf("Bairro: %s\n", endereco.bairro);
    printf("Complemento: %s\n", endereco.complemento);

    printf("\nEscolaridade:\n");

    if (escolaridade.nivel == SUPERIOR) {
        printf("Nível: Superior\n");
    }

    if (escolaridade.situacao == COMPLETO) {
        printf("Situação: Completo\n");
    } else if (escolaridade.situacao == INCOMPLETO) {
        printf("Situação: Incompleto\n");
    } else {
        printf("Situação: Não aplicável\n");
    }

    return 0;
}