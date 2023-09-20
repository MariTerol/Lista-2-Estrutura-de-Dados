// Mariana Nunes Terol = UC22200554

//Questão 6 - Escreva uma função em C que realize uma busca sequencial em uma matriz bidimensional de inteiros para encontrar um valor específico fornecido pelo usuário. A função deve retornar a posição da primeira ocorrência do valor ou informar que o valor não foi encontrado.


void buscaSequencial(int matriz[][3], int linhas, int colunas, int valor) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == valor) {
                printf("Valor %d encontrado na posicao (%d, %d)\n", valor, i, j);
                return; 
            }
        }
    }
    printf("Valor %d nao foi encontrado na matriz.\n", valor);
}

int main() {
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; //Buscar os valores que estao aqui (Deixei declarado ja)
    int linhas = 3;
    int colunas = 3;
    int valor;

    printf("-> Informe o valor que deseja buscar na matriz: ");
    scanf("%d", &valor);

    buscaSequencial(matriz, linhas, colunas, valor);

    return 0;
}