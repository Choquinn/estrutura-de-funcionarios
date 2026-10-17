#include "console.h"
#include <windows.h>

void configurarConsole(void) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}