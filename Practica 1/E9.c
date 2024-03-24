#include <stdio.h>
#define F 4
#define C 4

void imprimirMatText(char mat[F][C]){
	for(int f=0 ; f<F; f++){
		for(int c=0; c<C; c++){
			printf("%4c", mat[f][c]);
		}
		printf("\n");
	}
}
	
void ordenarMatText(char mat[F][C]){
	char aux;
	for(int f = 0; f<F-1; f++){
		for(int c = 0; c<C-1; c++){
			for(int f1 = 0; f1<F-1; f1++){
				for(int c1 = 0; c1<C-1; c1++){
					if(mat[f][c] < mat[f1][c1]){
						aux = mat[f][c];
						mat[f][c] = mat[f1][c1];
						mat[f1][c1] = aux;
					}
				}
			}
		}
	}
}

void cargarMatText(char mat[F][C]){
	for(int f = 0; f < F; f++){
		for(int c = 0; c < C-1; c++){ // dejar último car para el nulo
			printf("[%d][%d]: ", f, c);
			mat[f][c] = getchar();
			while(getchar() != '\n'); // Limpia buffer
		}
		mat[f][C - 1] = '\0'; // nulo al final de cada fila
	}
}
	
int main(){
	char mat[F][C] = {0};
	cargarMatText(mat);
	printf("-----------------------------------------\n");
	printf("Matriz cargada: \n");
	imprimirMatText(mat);
	printf("-----------------------------------------\n");
	printf("Matriz ordenada: \n");
	ordenarMatText(mat);
	imprimirMatText(mat);
	return 0;
}
