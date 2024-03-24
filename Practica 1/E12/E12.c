#include <stdio.h>
#include <stdlib.h>
#define F 5
#define C 8

void imprimirMatNum(int mat[F][C]){
	for(int f=0; f<F; f++){
		for(int c=0; c<C; c++){
			printf("%4d", mat[f][c]);
		}
		printf("\n");
	}
}
	
void cargarMatNum(int mat[F][C]){
	int r;
	int i = 0;
	
	FILE * arch;
	arch = fopen("puntos.txt", "r");
	
	r = fscanf(arch, "%d,%d,%d,%d,%d,%d,%d,%d\n", &mat[i][0], &mat[i][1], &mat[i][2], &mat[i][3], &mat[i][4], &mat[i][5], &mat[i][6], &mat[i][7]);
	while(r != EOF){
		i++;
		r = fscanf(arch, "%d,%d,%d,%d,%d,%d,%d,%d\n", &mat[i][0], &mat[i][1], &mat[i][2], &mat[i][3], &mat[i][4], &mat[i][5], &mat[i][6], &mat[i][7]);
	}
	fclose(arch);
}


int main(){
	int mat[F][C];
	cargarMatNum(mat);
	imprimirMatNum(mat);
	return 0;
}
