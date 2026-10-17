#include <stdio.h>
#include "console.h"
#include "repositorio.h"
#include "funcionario.h"

int main(void) {
    configurarConsole();

    data dataNasc = {15, 2, 2007};

    printf("Sistema de funcionários\n");
    printf("Armazenamento: %s\n", nomeRepositorio());
    
    printf("Data de nascimento: %02d/%02d/%04d\n", dataNasc.dia, dataNasc.mes, dataNasc.ano);

    return 0;
}