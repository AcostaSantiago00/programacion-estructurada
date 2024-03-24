#include <stdio.h>
#define F 3 // FILAS
#define C 3 // COLUMNAS

float promMat(int mat[F][C]){
	int acum = 0;
	for(int f=0; f<F; f++){
		for(int c=0; c<C; c++){
			acum += mat[f][c];
		}
	}
	return (float)acum / (F*C);
}
	
void imprimirMat(int mat[F][C]){
	for(int f=0; f<F; f++){
		for(int c=0; c<C; c++){
			printf("%4d", mat[f][c]);
		}
		printf("\n");
	}
}

void cargarMat(int mat[F][C]){
	for(int f=0; f<F; f++){
		for(int c=0; c<C; c++){
			printf("[%d][%d]: ", f, c);
			scanf("%d", &mat[f][c]);
		}
	}
}
	
int main(){
	int mat[F][C] = {0};
	cargarMat(mat);
	printf("---------------------\n");
	imprimirMat(mat);
	printf("---------------------\n");
	printf("Promedio de matriz: %.2f", promMat(mat));
	
	return 0;
}
