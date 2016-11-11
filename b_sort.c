#include <stdio.h>
#include "b_sort.h"

void bsort(void*base, size_t num, size_t size, 
			 int(*compar)(const void*, const void*)){

	if(size == sizeof(int)){
		//se fija si vas a ordenar un arreglo de ints, basandose en el tamaño en bytes de size
		int i, j, aux;
		int* a = base;
		//es necesario pues el apuntador a base es void
		for(i=1; i<num;i++){
			//es el mismo algoritmo de la práctica pasada
			for(j=0;j<num-1;j++){
				if((*compar)(a+j, a+j+1) == 1){
					//llamamos a la función de comparación, en lugar de usar predeterminadamente el >, de los enteros
					aux = *(a+j);
					*(a+j) = *(a+j+1);
					*(a+j+1) = aux;
				}
			}
		}

	}
	else if(size == sizeof(double)){
		//si ordenamos un arreglo de doubles, checamos viendo el tamaño en bytes de size
		int i, j;
		double aux;
		double* a = base;
		//es necesario pues el apuntador a base es void
		for(i=1; i<num;i++){
			//mismo algoritmo que arriba
			for(j=0;j<num-1;j++){
				if((*compar)(a+j, a+j+1) == 1){
					aux = *(a+j);
					*(a+j) = *(a+j+1);
					*(a+j+1) = aux;
				}
			}
		}
	}

}