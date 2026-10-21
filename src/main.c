#include <stdio.h>
#include <time.h>

#include "console.h"
#include "repositorio.h"
#include "funcionario.h"
#include "validacao.h"
#include "entrada.h"

int main(void) {
    configurarConsole();

    time_t agora = time(NULL);

    if (agora == (time_t)-1) {
        printf("Erro ao obter a data atual.\n");
        return 1;
    }

    struct tm *calendario = localtime(&agora);

    if (calendario == NULL) {
        printf("Erro ao obter a data atual.\n");
        return 1;
    }

    Data hoje = {
        calendario->tm_mday,
        calendario->tm_mon + 1,
        calendario->tm_year + 1900
    };

    Funcionario funcionario;

    printf("Sistema de Funcionários\n");
    printf("Armazenamento: %s\n", nomeRepositorio());

    if (!lerFuncionarioDados(&funcionario, hoje)) {
        printf("\nCadastro interrompido.\n");
        return 1;
    }

    funcionario.id = 1;

    ResultadoValidacao resultado = validarFuncionario(&funcionario, hoje);

    if (resultado != VALIDACAO_OK) {
        printf("\n%s\n", mensagemValidacaoFuncionario(resultado));
        return 1;
    }

    printf("\nFuncionário validado com sucesso!\n");
    printf("Nome: %s\n", funcionario.nome);
    printf("CPF: %s\n", funcionario.cpf);
    printf("Cargo: %s\n", funcionario.cargo);

    return 0;
}