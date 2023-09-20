// Mariana Nunes Terol = UC22200554

//Questão 4 - Escreva um programa em C que ordene uma matriz bidimensional (uma matriz de inteiros, por exemplo) usando o algoritmo de quicksor.

#include <stdio.h> 
#include <stdlib.h> 


void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}



int partition(int arr[][2], int low, int high) {
    int pivot = arr[high][0];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j][0] < pivot) {
            i++;
            swap(&arr[i][0], &arr[j][0]);
            swap(&arr[i][1], &arr[j][1]);
        }
    }
    swap(&arr[i + 1][0], &arr[high][0]);
    swap(&arr[i + 1][1], &arr[high][1]);
    return (i + 1);
}



void quicksort(int arr[][2], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main(void) {
    
    int n;

    printf("-> Informe a quantidade de pares (x, y) que deseja ordenar: ");
    scanf("%d", &n);

    int arr[n][2];

    printf("-> Informe os pares (x, y) que deseja ordenar:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    quicksort(arr, 0, n - 1);

    printf("--=Valores Ordenados=--\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", arr[i][0], arr[i][1]);
    }

    return 0;
}