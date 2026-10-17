#include <stdio.h>
#include "console.h"
#include "repositorio.h"

int main(void) {
    configurarConsole();

    printf("Sistema de funcionários\n");
    printf("Armazenamento: %s\n", nomeRepositorio());
    return 0;
}