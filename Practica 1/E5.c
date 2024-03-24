#include <stdio.h>
#define TAM 10
#define TERM 0

int estaEnArr(int num, int arr[TAM]){
	for (int i=0; i < TAM-1 && arr[i] != TERM; i++){
		if(arr[i] == num){
			return 1;
		}
	}
	return 0;
}
	
int esPos(int num){
	return num >= 0;
}

void cargarArrPNR(int arr[TAM]){
	int i=0;
	int aux;
	printf("\nIngrese contenido. O Ingrese 0 (Cero) para terminar la carga: \n");
	scanf("%d", &aux);
	while(aux != TERM && i < TAM - 1){
		if (!estaEnArr(aux, arr) && esPos(aux)){
			arr[i] = aux;
			i++;
		}
		if(i < TAM - 1){
			scanf("%d", &aux);
		}
	}
	arr[i] = TERM;
}

void imprimirArr(int arr[TAM]){
	int i;
	for(i = 0; arr[i] != TERM; i++){
		printf("%d - ", arr[i]);
	}
}
	
int main(){
	int arr[TAM] = {0};
	cargarArrPNR(arr);
	imprimirArr(arr); //para imprimirlo hay que recorrerlo
	return 0;
}
