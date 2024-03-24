#include <stdio.h>
#include <string.h>
#define TAME 15
#define TAMP 8
#define TAM 5
#define TAMC 9

struct s_puntos_equipos{
	char equipos[TAME];
	int puntos[TAMP];
};

typedef struct s_puntos_equipos p_e;

void fun2(p_e estructura[TAME], char cabeceras[]){
	p_e aux;
	char arrC[TAMC][7];
	int c, i = 0, j;
	FILE * archc;
	archc = fopen(cabeceras, "r");
	
	if(archc == NULL){
		return;
	}
	
	if(archc != NULL){
		c = fgetc(archc);
		while(c != EOF){
			for(j=0; c != '\n' && c != EOF; j++){
				arrC[i][j] = c;
				c = fgetc(archc);
			}
			arrC[i][j] = '\0';
			c = fgetc(archc);
			i++;
		}
		fclose(archc);
	}
	
	for(i=0; i<TAM-1 ; i++){
		for(j=i+1; j<TAM ; j++){
			if(estructura[i].puntos[0] < estructura[j].puntos[0]){
				aux = estructura[i];
				estructura[i] = estructura[j];
				estructura[j] = aux;
			}
		}
	}
	
	for(i=0; i<TAMC; i++){
		if(i == 0){
			printf("%-13s", arrC[i]);
		}else{
			printf("%4s", arrC[i]);
		}
	}
	
	printf("\n---------------------------------------------\n");
	for(i=0; i<TAM; i++){
		printf("%-13s", estructura[i].equipos);
		for(j=0; j<TAMP; j++){
			printf("%4d", estructura[i].puntos[j]);
		}
		printf("\n");
	}
}

void fun1(char items[], char datos[], p_e estructura[TAME]){
	int c, i = 0, j, k;
	FILE * arche;
	FILE * archp;
	arche = fopen(items, "r");
	archp = fopen(datos, "r");
	
	if(arche == NULL){
		return;
	}
	
	if(arche != NULL){
		c = fgetc(arche);
		while(c != EOF){
			for(k=0; c != '\n' && c != EOF; k++){
				estructura[i].equipos[k] = c;
				c = fgetc(arche);
			}
			estructura[i].equipos[k] = '\0';
			for(j=0; j<TAMP; j++){
				fscanf(archp,"%d,", &estructura[i].puntos[j]);
			}
			i++;
			c = fgetc(arche);
		}
		fclose(arche);
		fclose(archp);
	}
}
	
int main() {
	p_e estructura[TAME];
	fun1("items.txt", "datos.txt", estructura);
	fun2(estructura, "cabeceras.txt");	
	return 0;
}
