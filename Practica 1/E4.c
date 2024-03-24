#include <stdio.h>
#define TAM 10
#define TERM 0

void cargarArr(int arr[TAM]){
	int i=0;
	printf("\nIngrese contenido. O ingrese 0 (cero) para finalizar carga:\n");
	while(i < TAM-1 && scanf("%d", &arr[i]) && arr[i] != TERM){
		i++;
	}
	if (i < TAM) {
		arr[i] = TERM; //TERM al final del arreglo
	}
}
	
int largoArr(int arr[]){
	/**cant de nums que contiene un arreglo de enteros*/
	int i;
	for (i=0; i < TAM-1 && arr[i] != TERM; i++);
	return i;
}

void invertirArr(int arr[TAM]){
	int i, j;
	int aux;
	int lenArr = largoArr(arr);
	j = lenArr - 1; //inicializado en la ult pos del arr
	for(i=0; i < lenArr/2 ; i++) {
		//intercambio;
		aux = arr[i];
		arr[i] = arr[j];
		arr[j] = aux;
		j--; //decrementa en cada pasada
	}
}

void imprimirArr(int arr[TAM], char n){ //SI O SI recorriendo un ciclo se imprime
	int i;
	printf("\nArreglo %c invertido:\n", n);
	for(i = 0; arr[i] != TERM; i++){
		printf("%d - ", arr[i]);
	}
}

int main() {
	int arr1[TAM] = {TERM};
	int arr2[TAM] = {TERM};
	char a = '1';
	char b = '2';
	cargarArr(arr1);
	printf("------------------------------------");
	invertirArr(arr1);
	imprimirArr(arr1, a);
	printf("\n------------------------------------\n");
	cargarArr(arr2);
	printf("------------------------------------");
	invertirArr(arr2);
	imprimirArr(arr2, b);
	printf("\n------------------------------------\n");
	return 0;
}
