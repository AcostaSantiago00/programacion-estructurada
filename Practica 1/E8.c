#include <stdio.h>
#define F 3
#define C 3

void trasponer(int mat[F][C]){
	int aux;
	for(int f=0; f<F; f++){
		for(int c = f; c<C; c++){ //en la primera pasada ya se intercambia la 1er y 2do fila por las 1ras 3 por eso c=f
			aux = mat[f][c];
			mat[f][c] = mat[c][f];
			mat[c][f] = aux;
		}
	}	
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
		for(int c=0; c<C ; c++){
			printf("[%d][%d]: ", f, c);
			scanf("%d", &mat[f][c]);
		}
	}
}
	
int main() {
	int mat[F][C]= {0};
	cargarMat(mat);
	printf("----------------\n");
	imprimirMat(mat);
	printf("----------------\n");
	printf("su traspuesta es: \n\n");
	trasponer(mat),
	imprimirMat(mat);
	
	return 0;
}

