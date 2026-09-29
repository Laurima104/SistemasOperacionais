# Sistemas Operacionais

Atividades e códigos desenvolvidos para a disciplina de Sistemas Operacionais. Os programas em C devem ser compilados e executados em um ambiente Linux; no Windows, use o **WSL** com Debian ou Ubuntu.

## Preparar o ambiente WSL

1. Instale o [WSL](https://learn.microsoft.com/windows/wsl/install) e uma distribuição Debian ou Ubuntu.
2. Abra o terminal da distribuição e instale as ferramentas necessárias:

   ```bash
   sudo apt update
   sudo apt install build-essential git
   ```

3. Instale o Visual Studio Code no Windows e a extensão **WSL** da Microsoft. A extensão **C/C++** pode ser instalada quando o VS Code estiver conectado ao WSL.

## Clonar e abrir o repositório

Prefira manter o repositório no sistema de arquivos Linux do WSL (por exemplo, dentro de `~/projetos`), em vez de trabalhar em `/mnt/c` ou em uma pasta sincronizada pelo Windows. Isso evita misturar ferramentas e caminhos Linux e Windows.

No terminal WSL, clone o repositório e entre na pasta criada. Substitua a URL e o nome da pasta pelos dados do repositório:

```bash
mkdir -p ~/projetos
cd ~/projetos
git clone URL_DO_REPOSITORIO
cd NOME_DA_PASTA_CLONADA
```

Para atualizar uma cópia já clonada, execute `git pull` dentro da pasta do repositório. Para abri-la no VS Code conectado ao WSL, também dentro da pasta, execute:

```bash
code .
```

Confirme que o canto inferior esquerdo do VS Code indica **WSL: Debian** ou **WSL: Ubuntu**. Abrir a pasta pelo Explorador do Windows pode conectar o VS Code ao ambiente Windows, que não usa o GCC instalado no WSL.

## Atividades

- [Aula 05-06](Aula05-06/README.md): criação e sincronização de processos com `fork`.
- [Aula 09-10](Aula09-10/README.md): criação e junção de threads tematizado com ordenação por baldes (Bucket Sort) com arquivos de entrada(serial e paralelizado).

Cada README de aula contém os comandos de compilação e execução próprios daquela atividade. Os executáveis gerados são locais e não precisam ser enviados ao repositório.
