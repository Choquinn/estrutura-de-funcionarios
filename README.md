
# Sistema de Gerenciamento de Funcionários

Sistema desenvolvido em linguagem C para gerenciar funcionários utilizando três diferentes estratégias de armazenamento.

## Versões

1. **Arquivo CSV:** manipulação direta dos registros em arquivo.
2. **Lista estática:** armazenamento em vetor de tamanho fixo.
3. **Lista encadeada:** armazenamento com ponteiros e alocação dinâmica.

## Funcionalidades previstas

- Cadastrar funcionários
- Listar funcionários
- Buscar funcionários por ID
- Editar informações
- Excluir funcionários
- Salvar e carregar dados

## Tecnologias

- Linguagem C (padrão C11)
- GCC
- Arquivos CSV

## Estrutura do projeto

- `include/` — Arquivos de cabeçalho
- `src/` — Implementação do sistema
- `src/repositorios/` — Estratégias de armazenamento
- `dados/` — Arquivos CSV
- `tests/` — Testes do programa

## Compilação

Execute os comandos na raiz do projeto.

### Sistema convencional

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic -fexec-charset=UTF-8 -Iinclude src/main.c src/console.c src/repositorios/arquivo.c -o sistema_arquivo.exe
```

### Lista estática

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic -fexec-charset=UTF-8 -Iinclude src/main.c src/console.c src/repositorios/estatica.c -o sistema_estatica.exe
```

### Lista encadeada

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic -fexec-charset=UTF-8 -Iinclude src/main.c src/console.c src/repositorios/encadeada.c -o sistema_encadeada.exe
```

## Estado do projeto

Em desenvolvimento. As funcionalidades serão implementadas progressivamente.
