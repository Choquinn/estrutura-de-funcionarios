@echo off

for %%V in (arquivo estatica encadeada) do (
    echo Compilando sistema_%%V...

    gcc -std=c11 -Wall -Wextra -Wpedantic -fexec-charset=UTF-8 -Iinclude src/main.c src/console.c src/funcionario.c src/repo/%%V.c -o sistema_%%V.exe

    if errorlevel 1 (
        echo Erro na compilacao!
        exit /b 1
    )
)

echo Todos os sistemas compilados!