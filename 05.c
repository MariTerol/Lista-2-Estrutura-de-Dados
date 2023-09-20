// Mariana Nunes Terol = UC22200554

//Questão 5 - Escreva um programa em C que ordene uma matriz bidimensional (uma matriz de inteiros, por exemplo) usando o algoritmo de ordenação por inserção.

void insertionSort(int matriz[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 1; j < colunas; j++) {
            int chave = matriz[i][j];
            int k = j - 1;
            while (k >= 0 && matriz[i][k] > chave) {
                matriz[i][k + 1] = matriz[i][k];
                k = k - 1;
            }
            matriz[i][k + 1] = chave;
        }
    }
}

int main(void) {
    
    int linhas, colunas;

    printf("-> Informe o numero de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("-> Informe o numero de colunas da matriz: ");
    scanf("%d", &colunas);

    int matriz[100][100];

    printf("-> Informe os elementos da matriz:\n");

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    insertionSort(matriz, linhas, colunas);

    printf("--=Matriz ordenada:=--\n");

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}