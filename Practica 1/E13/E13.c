#include <stdio.h>
#include <string.h>
#define F1 5
#define C1 14
#define F2 10
#define C2 7
#define F3 5
#define C3 8

void imprimirMatC(char matC[F2][C2]){
	for(int f=0; f<F2; f++){
		for(int c=0; c<C2 && matC[f][c] != '\0'; c++){
			printf("%c", matC[f][c]);
		}
		if(f == 0){
			printf("          ");
		}else{
			printf("   ");
		}
	}
	printf("\n");
}
	
void ordenarTabla(char matE[F1][C1], int matP[F3][C3], int col, int orden){
	int f, f1, c, auxN;
	char auxC[C1];
	if(orden == 0){
		for(f=0; f<F3-1; f++){
			for(f1= f+1; f1<F3; f1++){
				if(matP[f][col] < matP[f1][col]){
					for(c=0; c<C3; c++){
						auxN = matP[f][c];
						matP[f][c] = matP[f1][c];
						matP[f1][c] =  auxN;
					}
					strcpy(auxC, matE[f]);
					strcpy(matE[f], matE[f1]);
					strcpy(matE[f1], auxC);
				}
			}
		}
	}
	else if(orden == 1){
		for(f=0; f<F3-1; f++){
			for(f1= f+1; f1<F3; f1++){
				if(matP[f][col] > matP[f1][col]){
					for(c=0; c<C3; c++){
						auxN = matP[f][c];
						matP[f][c] = matP[f1][c];
						matP[f1][c] =  auxN;
					}
					strcpy(auxC, matE[f]);
					strcpy(matE[f], matE[f1]);
					strcpy(matE[f1], auxC);
				}
			}
		}
	}
}

void imprimirTabla(char matE[F1][C1], char matC[F2][C2], int matP[F3][C3]){
	imprimirMatC(matC);
	printf("-------------------------------------------------------\n");
	for(int f = 0 ; f<F1; f++){
		printf("%-13s", matE[f]);
		for(int c = 0 ; c<C3; c++){
			printf("%5d", matP[f][c]);
		}
		printf("\n");
	}
}

void cargarMatPuntos(int matP[F3][C3]){
	int r, i = 0;
	FILE * archpuntos;
	archpuntos = fopen("datos.txt", "r");
	
	r = fscanf(archpuntos, "%d,%d,%d,%d,%d,%d,%d,%d", &matP[i][0], &matP[i][1], &matP[i][2], &matP[i][3], &matP[i][4], &matP[i][5], &matP[i][6], &matP[i][7]);
	while(r != EOF){
		i++;
		r = fscanf(archpuntos, "%d,%d,%d,%d,%d,%d,%d,%d", &matP[i][0], &matP[i][1], &matP[i][2], &matP[i][3], &matP[i][4], &matP[i][5], &matP[i][6], &matP[i][7]);
	}
	fclose(archpuntos);
}
	
int cargarMatEquipo(char matE[F1][C1]){
	int f, c, res = 0;
	char car;
	FILE * archequipos;
	archequipos = fopen("items.txt", "r");
	
	if(archequipos != NULL){
		car = fgetc(archequipos);
		while(car != EOF){
			for(f=0; f<F1; f++){
				for(c=0; c<C1-1 && car != '\n'; c++){
					matE[f][c] = car;
					car = fgetc(archequipos);
				}
				matE[f][c] = '\0';
				car = fgetc(archequipos);
			}
			matE[f][0] = '\0';
		}
		fclose(archequipos);
	}
	else{
		res = -1;
	}
	return res;
}

int cargarMatCabecera(char matC[F2][C2]){
	int f, c, res = 0;
	char car;
	FILE * archcabeceras;
	archcabeceras = fopen("cabeceras.txt", "r");
	
	if(archcabeceras != NULL){
		car = fgetc(archcabeceras);
		while(car != EOF){
			for(f=0; f<F2; f++){
				for(c=0; c<C2 && car != '\n'; c++){
					matC[f][c] = car;
					car = fgetc(archcabeceras);
				}
				matC[f][c] = '\0';
				car = fgetc(archcabeceras);
			}
			matC[f][0] = '\0';
		}
		fclose(archcabeceras);
	}else{
		res = -1;
	}
	return res;
}
	
int main(){
	char matE[F1][C1], matC[F2][C2];
	int matP[F3][C3], col, orden;
	cargarMatCabecera(matC);
	cargarMatEquipo(matE);
	cargarMatPuntos(matP);
	printf("Indique el numero de la columna de la matriz de datos a ordenar: ");
	scanf("%d", &col);
	printf("\nIngrese 0 para ordenar de forma ascendente, o 1 de forma descendente: ");
	scanf("%d", &orden);
	printf("\n");
	ordenarTabla(matE, matP, col, orden);
	imprimirTabla(matE, matC, matP);
	return 0;
}
