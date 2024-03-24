#include <stdio.h>
#define TAM 100

void leer(char texto[TAM]){
	int i = 0;
	char aux;
	printf("Ingrese contenido: ");
	char term = '\n';
	
	if(i < TAM-1)
		aux = getchar(); //input()
	while(aux != term && i < TAM-1){ //term refiere a != de enter
		texto[i] = aux;
		i++;
		if(i < TAM-1)
			aux = getchar(); //input
	}
	texto[i] = '\0'; //strings contienen car '\0' como elemento terminador indicando fin de datos utiles del arreglo
}

void reemplazar(char texto[TAM]){
	char quitar, agregar;
	printf("Ingrese caracter a reemplazar: ");
	quitar = getchar();
	while(getchar() != '\n'); // Limpieza buffer
	
	printf("Ingrese caracter de reemplazo: ");
	agregar = getchar();
	printf("--------------------------------\n");
	
	for(int i=0; texto[i] != '\0'; i++){
		if(texto[i] == quitar){
			texto[i] = agregar;
		}
	}
}
	
int main() {
	char texto[TAM] = {0};
	leer(texto);
	printf("Texto cargado: %s", texto);
	printf("\n--------------------------------\n");
	reemplazar(texto);
	printf("Resultado: %s", texto);
	printf("\n--------------------------------\n");
		
	return 0;
	}
