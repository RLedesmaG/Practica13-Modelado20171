/*Incluye las funciones de b_sort.c y arreglos_random.c*/
#include "b_sort.h"
#include "arreglos_random.h"
#include <stdio.h>

/*Declara las funciones que vamos a ocupar*/
// función que compara dos enteros
int cmp_int(const void *a, const void *b);
// función que compara dos doubles
int cmp_double(const void *a, const void *b);
// función que imprime una lista de enteros de tamaño num
void imprime_int(int *arreglo, size_t num);
// función que imprime una lista de doubles de tamaño num
void imprime_double(double *arreglo, size_t num);


int main()
{
    // Se inicializan 2 arreglos, uno de ints y otro de doubles
    int *arr1 = arreglo_int(20, 0, 10);
    double *arr2 = arreglo_double(20, 0, 10);

    // Se imprime ordena e imprime el primer arreglo
    printf("Antes:\n");
    imprime_int(arr1, 20);
    bsort(arr1, 20, sizeof(int), &cmp_int);
    printf("Despues:\n");
    imprime_int(arr1, 20);

    // Se imprime ordena e imprime el segundo arreglo
    printf("Antes:\n");
    imprime_double(arr2, 20);
    bsort(arr2, 20, sizeof(double), &cmp_double);
    printf("Despues:\n");
    imprime_double(arr2, 20);

    // Se libera la memoria que ocupan los arreglos ordenados
    free(arr1);
    free(arr2);

    return 0;
}

int cmp_int(const void *a, const void *b){
    //convertimos a apuntadores de ints, en lugar de voids
    int a1 = *(int*)a;
    int b1 = *(int*)b;
    if(a1>b1)
        return 1;
    else 
        return 0;
}

int cmp_double(const void *a, const void *b){
    //convertimos a apuntadores de double, en lugar de voids
    double a1 = *(double*)a;
    double b1 = *(double*)b;
    if(a1>b1)
        return 1;
    else
        return 0;
}

void imprime_int(int *arreglo, size_t num){
    for(int i=0;i<num;i++){
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

void imprime_double(double *arreglo, size_t num){
    for(int i=0;i<num;i++){
        printf("%f ", arreglo[i]);
    }
    printf("\n");
}