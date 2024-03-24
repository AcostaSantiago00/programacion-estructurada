#include <stdio.h>
#define F 4
#define C 11

void imprimirMat(char mat[F][C]){
	int f = 0, c = 0;
	for(f=0; f<F; f++){
		for(c=0; c<C && mat[f][c] != '\0' ; c++){
			printf("%4c", mat[f][c]);
		}
		printf("\n");
	}
}

int main(){
	char mat[F][C] = {0};
	int car = 0; // donde se guardan caracteres
	int res = 0;
	int f = 0, c = 0;
	
	FILE* arch;
	arch = fopen("equipos.txt", "r");
	
	if(arch != NULL){
		car = fgetc(arch);
		while(car != EOF){
			for(f=0; f<F; f++){
				for(c=0; c<C && car != '\n'; c++){
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
		printf("Error al abrir el archivo.\n");
		res = -1;
	}
	imprimirMat(mat);
	return res;
}
