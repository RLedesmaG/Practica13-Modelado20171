#include "arreglos_random.h"
#include <stdlib.h>
#include <time.h>

int* arreglo_int(size_t num, int min, int max){
	//se deja el espacio en memoria del arreglo que vamos a usar, se guarda como apuntador
	int *arreglo = malloc(num * sizeof(int));
	//generador de numeros aleatorios empieza. en realidad son pseudo aleatorios, pues al usar time dependen del segundo en el que se llama(se corre el programa)
	srand(time(NULL));
	for(int i=0;i<num;i++){
		//guardamos el valor aleatorio en el arreglo
		arreglo[i] =(rand() % (max-min))+min;
		//al sacar el módulo y sumarle min, garantizamos que el valor estará en los parametros necesarios. 
		//Esta idea la encontré en internet, así que no estoy 100% seguro que funcione para todos los casos, pues creo que en algun momento se puede salir de los rangos de int
	}
	return arreglo;

}

double* arreglo_double(size_t num, double min, double max){
	double *arreglo = malloc(num*sizeof(double));
	//se deja el espacio en memoria del arreglo, lo guardamos como apuntador
	for(int i=0;i<num;i++){
		arreglo[i] = (((double)rand()/RAND_MAX)*(max-min))+min;
		//lo mismo que para ints, se garantiza que el numero está estrictamente en los rangos especificados
		//tenemos que convertir a double rand() o se quedará como int la división
	}
	return arreglo;
}