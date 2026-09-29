#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para o nó da lista encadeada (balde)
struct Node {
    int data;
    struct Node* next;
};

// Função para inserir ordenado no balde (Insertion Sort implícito)
struct Node* insertSorted(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || head->data >= value) {
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

int* readArchive(const char* fileName, int* size) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    int n;
    if (fscanf(file, "%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Formato invalido: o primeiro valor deve ser o tamanho do array.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    int* arr = malloc((size_t)n * sizeof *arr);
    
    if (arr == NULL) {
        perror("Erro ao alocar memoria");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            fprintf(stderr, "Formato invalido: faltou o valor %d de %d.\n", i + 1, n);
            free(arr);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    *size = n;
    return arr;
}

// Função para juntar os baldes de volta ao array principal
void mergeBuckets(struct Node* buckets[], int n, int arr[]) {
    int i, index = 0;
    for (i = 0; i < n; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            struct Node* temp = current;
            current = current->next;
            free(temp); // Liberando memória
        }
    }
}

// Função principal do Bucket Sort
void bucketSort(int arr[], int n) {
    if (n <= 0) return;

    // 1. Encontrar o maior elemento para definir o dimensionamento
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    // 2. Criar os baldes (array de ponteiros)
    struct Node** buckets = (struct Node**)calloc(n, sizeof(struct Node*));

    // 3. Distribuir os elementos nos baldes
    for (int i = 0; i < n; i++) {
        // Cálculo do índice do balde
        // Usa long long para evitar overflow: n * arr[i] pode exceder int.
        int bi = (int)(((long long)n * arr[i]) / ((long long)max + 1));
        buckets[bi] = insertSorted(buckets[bi], arr[i]);
    }

    // 4. Coletar os elementos ordenados
    mergeBuckets(buckets, n, arr);
    
    free(buckets);
}

int main(int argc, char *argv[]) {
    // Caminho relativo: execute o programa a partir da pasta Aula09-10.
    const char* fileName = argc > 1 ? argv[1] : "entradas/pequena.txt";
    int n;
    int *arr = readArchive(fileName, &n);

    struct timespec inicio, fim;

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    bucketSort(arr, n);
    clock_gettime(CLOCK_MONOTONIC, &fim);

    double tempoTotal = (fim.tv_sec - inicio.tv_sec)
                    + (fim.tv_nsec - inicio.tv_nsec) / 1e9;

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d \n", arr[i]);
    }
    printf("\n");
    printf("Tempo de ordenacao: %.6f segundos\n", tempoTotal);

    free(arr);
    return 0;
}
