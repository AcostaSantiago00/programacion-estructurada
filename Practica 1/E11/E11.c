#include <stdio.h>
#include <string.h>
#define N 25
#define F 4

void imprimirMat(char mat[F][N]){
	for(int f=0; f<F; f++){
		for(int c=0; c<N && mat[f][c] != '\0' ; c++){
			printf("%4c", mat[f][c]);
		}
		printf("\n");
	}
}

void ordenarTexto(char mat[F][N]){
	char aux[N];
	for(int i = 0; i < F-1; i++){
		for(int j = i+1; j < F; j++){
			if(strcmp(mat[i], mat[j]) > 0){ // si son == da 0, mat[i] > mat[j] da > 0, mat[i] < mat[j] da < 0,
				strcpy(aux, mat[i]);
				strcpy(mat[i], mat[j]); 
				strcpy(mat[j], aux); 
			}
		}
	}
}

int main() {
	int car = 0; // donde se guardan caracteres
	int res = 0;
	int f = 0, c = 0;
	char mat[F][N];
	FILE* arch;
	arch = fopen("equipos.txt", "r");
	if(arch != NULL){
		car = fgetc(arch);
		while(car != EOF){
			for(f=0; f<F; f++){
				for(c=0; c<N && car != '\n'; c++){
					mat[f][c] = car;
					car = fgetc(arch);
				}
				mat[f][c] = '\0';
				car = fgetc(arch);
			}
			mat[f][0] = '\0';
		}
		fclose(arch);
	}
	else{
		res = -1;
	}
	imprimirMat(mat);
	printf("\n---------------------------------------\n");
	ordenarTexto(mat);
	printf("Ordenada de forma ascendente: \n");
	imprimirMat(mat);
	return res;
}
