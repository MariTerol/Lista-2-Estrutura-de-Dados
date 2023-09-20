// Mariana Nunes Terol = UC22200554

//Questão 1 - Escreva um programa em C que ordena um array de inteiros usando o algoritmo de ordenacao por bolha.

#include <stdio.h> 
#include <stdlib.h> 

void bubble_sort(int vetor[], int n){

    int k,j,aux;

    for(k=1;k<n;k++){
        for (j=0;j<n-k;j++){
           if(vetor[j]>vetor[j+1]){
                aux=vetor[j];
                vetor[j]=vetor[j+1];
                vetor[j+1]=aux;
           }
        }
    }
}

int main(void){

    int i,n;

    printf("-> Informe a quantidade de numeros que deseja ordenar: ");
    scanf("%d", &n);

    int vetor[n];

    printf("-> Informe os numeros que deseja ordenar: ");
    for(i=0;i<n;i++){
    scanf("%d", &vetor[i]);
    }

    bubble_sort(vetor,n);

    printf("--=Valores Ordenados=--\n");
    for(i=0;i<n;i++){
        printf(" %d", vetor[i]);
    }

    return 0;
}