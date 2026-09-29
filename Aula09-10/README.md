# Aula 09-10: Bucket Sort

O programa `bucket_sort.c` ordena números inteiros lidos de um arquivo e informa o tempo de ordenação. Os arquivos de exemplo estão em `entradas/`.

## Compilar

No terminal WSL, a partir da raiz do repositório:

```bash
cd Aula09-10
gcc -Wall -Wextra -O2 bucket_sort.c -o bucket_sort
```

## Executar

Sem argumentos, o programa lê `entradas/pequena.txt`:

```bash
./bucket_sort
```

Para escolher outro arquivo, passe o caminho como argumento:

```bash
./bucket_sort entradas/media.txt
./bucket_sort entradas/grande.txt
```

Os caminhos são relativos à pasta `Aula09-10`, então execute os comandos a partir dela. A execução com `grande.txt` imprime todos os valores ordenados; para guardar essa saída em vez de exibi-la no terminal, use:

```bash
./bucket_sort entradas/grande.txt > output/grande.txt
```

## Formato dos arquivos

A primeira linha contém a quantidade de números a ordenar. Depois dela devem vir exatamente essa quantidade de valores inteiros, separados por espaços ou quebras de linha. Por exemplo:

```text
5
8 3 10 1 5
```

O executável `bucket_sort` é gerado localmente nesta pasta e não precisa ser versionado. Se o GCC não estiver instalado, instale-o no WSL com `sudo apt install build-essential`; para configurar e abrir o repositório no WSL, consulte o [README principal](../README.md).
