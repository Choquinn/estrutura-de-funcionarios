#include <stdio.h>
#include <inttypes.h>

#include "console.h"
#include "repositorio.h"
#include "funcionario.h"
#include "validacao.h"
#include "entrada.h"

int main(void) {
    configurarConsole();

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

    printf("\nTestando validação de textos:\n\n");

    printf(
        "Nome: %s\n",
        textoObrigatorioValido(f.nome, sizeof(f.nome))
            ? "Válido" : "Inválido"
    );

    printf(
        "Cargo: %s\n",
        textoObrigatorioValido(f.cargo, sizeof(f.cargo))
            ? "Válido" : "Inválido"
    );

    char nomeVazio[] = "";
    char nomeEspacos[] = "     ";

    printf(
        "Nome vazio: %s\n",
        textoObrigatorioValido(nomeVazio, sizeof(nomeVazio))
            ? "Válido" : "Inválido"
    );

    printf(
        "Nome com espaços: %s\n",
        textoObrigatorioValido(nomeEspacos, sizeof(nomeEspacos))
            ? "Válido" : "Inválido"
    );

    char textoSemTerminador[5] = {'T', 'e', 's', 't', 'e'};

    printf(
        "Texto sem terminador: %s\n",
        textoObrigatorioValido(
            textoSemTerminador,
            sizeof(textoSemTerminador)
        ) ? "Válido" : "Inválido"
    );

    printf("Número da casa válido: %s\n", numeroEnderecoValido(f.endereco.numero) ? "Válido" : "Inválido");

    printf("\nTestando validação de CPF:\n\n");

    char cpfs[][20] = {
        "12345678909",
        "12345678900",
        "00000000000",
        "1234567890",
        "1234567890A"
    };

    for (int i = 0; i < 5; i++) {
        printf(
            "CPF %s: %s\n",
            cpfs[i],
            cpfValido(cpfs[i], sizeof(cpfs[i]))
                ? "Válido" : "Inválido"
        );
    }

    printf("\nTestando validação de escolaridade:\n\n");

    Escolaridade testes[] = {
        {ANALFABETO, NAO_APLICAVEL},
        {ANALFABETO, COMPLETO},
        {FUNDAMENTAL, INCOMPLETO},
        {MEDIO, COMPLETO},
        {SUPERIOR, NAO_APLICAVEL},
        {POSGRADUACAO, COMPLETO},
        {(NivelEscolaridade)99, COMPLETO}
    };

    int quantidade = sizeof(testes) / sizeof(testes[0]);

    for (int i = 0; i < quantidade; i++) {
        printf(
            "%s - %s: %s\n",
            nivelEscolaridadeTexto(testes[i].nivel),
            situacaoEscolaridadeTexto(testes[i].situacao),
            escolaridadeValida(testes[i]) ? "Válido" : "Inválido"
        );
    }

    printf("\nTestando validação de estado civil:\n\n");

    EstadoCivil testesEstado[] = {
        SOLTEIRO,
        CASADO,
        SEPARADO,
        DIVORCIADO,
        VIUVO,
        (EstadoCivil)99
    };

    size_t quantidadeEstados = sizeof(testesEstado) / sizeof(testesEstado[0]);

    for (size_t i = 0; i < quantidadeEstados; i++) {
        printf(
            "%s: %s\n",
            estadoCivilTexto(testesEstado[i]),
            estadoCivilValido(testesEstado[i])
                ? "Válido" : "Inválido"
        );
    }

    printf("\nTestando validação de salários:\n\n");

    const char *salarios[] = {
        "1850,75",
        "1000",
        "99,9",
        "0,05",
        "-1500,00",
        "1500,999",
        "abc",
        "92233720368547758,08"
    };

    size_t quantidadeSalarios = sizeof(salarios) / sizeof(salarios[0]);

    for (size_t i = 0; i < quantidadeSalarios; i++) {
        int64_t valor;

        if (converterSalario(salarios[i], &valor)) {
            printf(
                "%s -> %" PRId64 " centavos\n",
                salarios[i],
                valor
            );
        } else {
            printf("%s -> Inválido\n", salarios[i]);
        }
    }

    Data hoje = {19, 10, 2026};

    printf("\nTestando datas do funcionário:\n\n");

    printf(
        "Nascimento e admissão: %s\n",
        datasFuncionarioValidas(
            f.dataNascimento,
            f.dataAdmissao,
            hoje
        ) ? "Válidas" : "Inválidas"
    );

    Data nascimento = {15, 2, 2007};

    Data admissaoValida = {10, 10, 2026};
    Data admissaoFutura = {20, 10, 2026};
    Data admissaoAntesNascimento = {1, 1, 2000};
    Data admissaoInexistente = {31, 2, 2026};

    printf("\nTestando situações inválidas:\n\n");

    printf(
        "Admissão válida: %s\n",
        datasFuncionarioValidas(nascimento, admissaoValida, hoje)
            ? "Válido" : "Inválido"
    );

    printf(
        "Admissão futura: %s\n",
        datasFuncionarioValidas(nascimento, admissaoFutura, hoje)
            ? "Válido" : "Inválido"
    );

    printf(
        "Admissão antes do nascimento: %s\n",
        datasFuncionarioValidas(nascimento, admissaoAntesNascimento, hoje)
            ? "Válido" : "Inválido"
    );

    printf(
        "Admissão inexistente: %s\n",
        datasFuncionarioValidas(nascimento, admissaoInexistente, hoje)
            ? "Válido" : "Inválido"
    );

    printf("\nValidação completa do funcionário:\n\n");

    ResultadoValidacao resultado = validarFuncionario(&f, hoje);

    printf("%s\n", mensagemValidacaoFuncionario(resultado));

    printf(
        "Funcionário válido? %s\n",
        funcionarioValido(&f, hoje) ? "Sim" : "Não"
    );

    char nomeDigitado[100];
    printf("\nTestando entrada de dados:\n\n");
    if (lerLinha("Digite seu nome: ", nomeDigitado, sizeof(nomeDigitado))) {
        if (textoObrigatorioValido(nomeDigitado, sizeof(nomeDigitado))) printf("Nome informado: %s\n", nomeDigitado);
        else printf("O nome não pode estar vazio!\n");
    } else {
        printf("Não foi possível ler o nome ou a entrada excedeu o limite.\n");
    }

    printf("\nTestando conversão de inteiros:\n\n");
    const char *entradas[] = {
        "25",
        "0",
        "-15",
        "123abc",
        "abc",
        "",
        "9999999999999999999999999"
    };

    size_t quantidadeEntradas = sizeof(entradas) / sizeof(entradas[0]);

    for (size_t i = 0; i < quantidadeEntradas; i++) {
        int numero;

        if (converterInteiro(entradas[i], &numero)) printf("\"%s\" -> %d\n", entradas[i], numero);
        else printf("\"%s\" -> Inválido\n", entradas[i]);
    }

    char entrada[50];
    int numero;

    if (lerLinha("Digite um número: ", entrada, sizeof(entrada))) {
        if (converterInteiro(entrada, &numero)) {
            printf("Número informado: %d\n", numero);
        } else {
            printf("Número inválido!\n");
        }
    } else {
        printf("Erro ao ler o número.\n");
    }

    int opcao;

    printf("\nTestando leitura de inteiros:\n\n");

    if (lerInteiro("Digite uma opção (0 a 5): ", &opcao, 0, 5)) {
        printf("Opção selecionada: %d\n", opcao);
    } else {
        printf("Leitura encerrada.\n");
    }

    char nomeObrigatorio[100];
    char cargoObrigatorio[80];

    printf("\nTestando textos obrigatórios:\n\n");

    if (!lerTextoObrigatorio(
            "Nome do funcionário: ",
            nomeObrigatorio,
            sizeof(nomeObrigatorio))) {
        printf("Leitura encerrada.\n");
        return 1;
    }

    if (!lerTextoObrigatorio(
            "Cargo do funcionário: ",
            cargoObrigatorio,
            sizeof(cargoObrigatorio))) {
        printf("Leitura encerrada.\n");
        return 1;
    }

    printf("\nDados informados:\n");
    printf("Nome: %s\n", nomeObrigatorio);
    printf("Cargo: %s\n", cargoObrigatorio);

    Data data;
    Endereco endereco;
    Escolaridade escolaridade;
    EstadoCivil estadoCivil;

    if (!lerData("Data de nascimento:", &data)) return 1;
    if (!lerEndereco(&endereco)) return 1;
    if (!lerEscolaridade(&escolaridade)) return 1;
    if (!lerEstadoCivil(&estadoCivil)) return 1;

    printf("\nDados informados:\n\n");

    printf(
        "Nascimento: %02d/%02d/%04d\n",
        data.dia, data.mes, data.ano
    );

    printf("Rua: %s\n", endereco.rua);

    if (endereco.numero == ENDERECO_S_NUM) {
        printf("Número: S/N\n");
    } else {
        printf("Número: %d\n", endereco.numero);
    }

    printf("Bairro: %s\n", endereco.bairro);
    printf("Complemento: %s\n", endereco.complemento);

    printf(
        "Escolaridade: %s - %s\n",
        nivelEscolaridadeTexto(escolaridade.nivel),
        situacaoEscolaridadeTexto(escolaridade.situacao)
    );

    printf("Estado civil: %s\n", estadoCivilTexto(estadoCivil));

    return 0;
}