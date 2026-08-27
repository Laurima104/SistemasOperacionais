# Sistemas Operacionais

Atividades práticas da disciplina de Sistemas Operacionais.

## Executar os programas em C (Windows + WSL)

Este repositório foi configurado para compilar no **WSL (Debian/Ubuntu)** usando o GCC do Linux. Todos os integrantes do grupo devem usar esse mesmo ambiente para evitar diferenças entre Windows, MSYS2 e Linux.

> Não use `C:\\msys64\\...\\gcc.exe` nas configurações deste projeto enquanto ele estiver aberto pelo WSL.

### 1. Preparar o computador (somente na primeira vez)

1. Instale o [WSL](https://learn.microsoft.com/windows/wsl/install) no Windows e uma distribuição Debian ou Ubuntu.
2. Abra o terminal da distribuição instalada e execute:

   ```bash
   sudo apt update
   sudo apt install build-essential gdb git
   ```

3. Confirme que o compilador está disponível:

   ```bash
   gcc --version
   ```

4. Instale o Visual Studio Code no Windows e a extensão **WSL** (Microsoft). A extensão **C/C++** deve ser instalada quando o VS Code estiver conectado ao WSL.

### 2. Obter ou atualizar o repositório

No terminal WSL, entre na pasta onde o repositório será salvo e clone-o. Substitua a URL pela URL do repositório do grupo:

```bash
git clone URL_DO_REPOSITORIO
cd SistemasOperacionais
```

Em computadores que já possuem o projeto, atualize antes de começar a trabalhar:

```bash
git pull
```

### 3. Abrir corretamente no VS Code

Ainda no terminal WSL, na pasta raiz do repositório, execute:

```bash
code .
```

No canto inferior esquerdo do VS Code deve aparecer algo como **WSL: Debian** ou **WSL: Ubuntu**. Se não aparecer, feche a janela e use o comando acima novamente. Abrir a pasta diretamente pelo Explorador do Windows pode fazer o VS Code procurar compiladores do Windows e causar o erro “The specified compiler was not found”.

### 4. Configuração da extensão C/C++

Para a atividade `Aula05-06`, o arquivo `.vscode/c_cpp_properties.json` deve usar o GCC do WSL:

```json
{
  "configurations": [
    {
      "name": "Linux",
      "includePath": ["${workspaceFolder}/**"],
      "compilerPath": "/usr/bin/gcc",
      "intelliSenseMode": "linux-gcc-x64",
      "cStandard": "c17"
    }
  ],
  "version": 4
}
```

O arquivo `.vscode/tasks.json` também precisa compilar para Linux: o comando deve ser `/usr/bin/gcc`, e o nome de saída deve usar `/` e não `\\`, por exemplo:

```json
"command": "/usr/bin/gcc",
"args": ["-g", "${file}", "-o", "${fileDirname}/${fileBasenameNoExtension}"]
```

### 5. Compilar e executar `fork.c`

No terminal integrado do VS Code, entre na pasta da aula e execute:

```bash
cd Aula05-06
gcc -Wall -Wextra -g fork.c -o fork
./fork
```

Para compilar pelo VS Code, abra `fork.c` e pressione `Ctrl+Shift+B`; em seguida, no terminal, execute:

```bash
./fork
```

O executável `fork` é criado apenas localmente. Não é necessário enviá-lo ao Git; envie somente os arquivos `.c` e as configurações que o grupo decidir versionar.

### Solução rápida de problemas

- **`The specified compiler was not found`**: confira se o VS Code mostra **WSL: Debian/Ubuntu** no canto inferior esquerdo e se `compilerPath` é `/usr/bin/gcc`.
- **`gcc: command not found`**: execute `sudo apt install build-essential` no terminal WSL.
- **O VS Code continua mostrando o caminho antigo do Windows**: use `Ctrl+Shift+P` → **Developer: Reload Window** e depois **C/C++: Reset IntelliSense Database**.
- **Permissão negada ao executar `./fork`**: compile novamente com `gcc fork.c -o fork`; esse comando já cria o executável com a permissão necessária.
