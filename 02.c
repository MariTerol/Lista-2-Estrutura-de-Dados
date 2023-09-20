// Mariana Nunes Terol = UC22200554

//Questão 2 - Compare o desempenho do algoritmo de ordenação por bolha com algoritmo de ordenação o quicksort e o mergesort, usando arrays de tamanhos diferentes. Meça o tempo de execução e compare os resultado.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

//Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    srand(time(0));

    printf("Array gerado aleatoriamente:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  
        printf("%d ", arr[i]);
    }

    clock_t start, end;
    double cpu_time_used;

    
    int *arr_bubble = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr_bubble[i] = arr[i];
    }
    start = clock();
    bubbleSort(arr_bubble, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao do Bubble Sort: %f segundos\n", cpu_time_used);

    
    int *arr_quick = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr_quick[i] = arr[i];
    }
    start = clock();
    quickSort(arr_quick, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Quick Sort: %f segundos\n", cpu_time_used);

    
    int *arr_merge = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr_merge[i] = arr[i];
    }
    start = clock();
    mergeSort(arr_merge, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Merge Sort: %f segundos\n", cpu_time_used);

    free(arr);
    free(arr_bubble);
    free(arr_quick);
    free(arr_merge);

    return 0;
}
