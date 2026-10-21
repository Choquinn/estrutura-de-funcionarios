@echo off

echo Compilando testes...

gcc -std=c11 -Wall -Wextra -Wpedantic -Iinclude tests/test_validacao.c src/validacao.c -o teste_validacao.exe

if errorlevel 1 (
    echo Erro na compilacao dos testes!
    exit /b 1
)

echo Executando testes...

.\teste_validacao.exe

if errorlevel 1 (
    echo Os testes falharam!
    exit /b 1
)

echo Testes finalizados com sucesso!