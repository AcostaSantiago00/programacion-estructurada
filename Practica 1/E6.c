#include <stdio.h>
#define TAM 100

int largoArrC(char texto[]){
	int i;
	for (i=0; i < TAM-1 && texto[i] != '\0'; i++);
	return i;
}

void normalizar(char texto[TAM]){
	int i, j;
	int largo = largoArrC(texto);
	
	// Elimina espacios al inicio
	for(i=0; texto[i] == ' '; i++); //encuentra primer carácter no-espacio
	if(i > 0){ //si es mayor que 0, hay espacios para eliminar
		for(j = 0; texto[i] != '\0'; j++, i++){
			texto[j] = texto[i]; //desplaza cada carácter hacia la izquierda
		}
		texto[j] = '\0';
	}
	
	// Elimina espacios intermedios y del final
	for(i = 0; texto[i] != '\0'; i++){
		if(texto[i] == ' ' && texto[i + 1] == ' '){
			for(j = i; texto[j] != '\0'; j++){
				texto[j] = texto[j + 1];
			}
			i--;
		}
	}
	
	// Convierte la primera letra a mayúscula
	if(texto[0] >= 'a' && texto[0] <= 'z'){
		texto[0] = texto[0] - ('a' - 'A'); //sacado de internet / diferencia de los valores ASCII
	}
	
	// Asegura que termine con punto
	largo = largoArrC(texto) - 1;
	if(texto[largo] != '.'){
		texto[largo + 1] = '.';
		texto[largo + 2] = '\0';
	}
}

void imprimirText(char texto[TAM]){
	printf("%s", texto); //no hace falta ciclos para imprimir arreglos de strings
	printf("\n---------------------------------\n");
}
	
void cargarText(char texto[TAM]){
	int i = 0;
	char aux;
	printf("Ingrese contenido: ");
	while((aux = getchar()) != '\n' && i < TAM-1){
		texto[i] = aux;
		i++;
	}
	texto[i] = '\0';
	printf("\n---------------------------------\n");
}

int main() {
	char texto[100] = {0};
	cargarText(texto);
	imprimirText(texto);
	normalizar(texto);
	imprimirText(texto);
	
	return 0;
}	
