#include <stdio.h>
#include <locale.h>
#ifdef _WIN32
    #include <windows.h>
#endif

int main(void) {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif
    
    setlocale(LC_ALL, "");

    printf("Sistema de funcionários\n");
    printf("Cadastro, edição e exclusão\n");
    printf("Endereço e salário\n");

    return 0;
}