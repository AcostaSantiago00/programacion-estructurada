#include <stdio.h>
#include <math.h>
#define TAM 10

struct c_punto{
	int x;
	int y;
};

typedef struct c_punto coordenada;

void leerPuntos(coordenada c[TAM]);
void fun1(coordenada c[TAM]);
void fun2(coordenada c[TAM]);

int main(){
	coordenada c[TAM];
	leerPuntos(c);
	fun1(c);
	fun2(c);
	
	return 0;
}

void leerPuntos(coordenada c[TAM]){
	int r;
	int i = 0;
	
	FILE * arch;
	arch = fopen("puntos.txt", "r");
	
	if(arch == NULL){
		printf("No se pudo leer el archivo");
		return;
	}
	
	r = fscanf(arch, "%d,%d,", &c[i].x, &c[i].y);
	while(r != EOF && i<TAM){
		i++;
		r = fscanf(arch, "%d,%d,", &c[i].x, &c[i].y);
	}
	fclose(arch);
}

void fun1(coordenada c[TAM]){
	int i;
	float d;
	int p1x, p1y, p2x, p2y;
	for(i=0; i<TAM-1; i++){
		d = pow(pow(c[i+1].x - c[i].x, 2) + pow(c[i+1].y - c[i].y, 2), 0.5);
		p1x = c[i].x;
		p1y = c[i].y;
		p2x = c[i+1].x;
		p2y = c[i+1].y;
		printf("distancia minima entre (%d,%d) y (%d,%d) = %.2f\n", p1x, p1y, p2x, p2y, d);
	}
}

void fun2(coordenada c[TAM]){
	int i, j, bandera = 0;
	float d, min;
	int p1x, p1y, p2x, p2y;
	for(i=0; i<TAM-1; i++){
		for(j=i+1; j<TAM; j++){
			d = pow(pow(c[j].x - c[i].x, 2) + pow(c[j].y - c[i].y, 2), 0.5);
			if(bandera == 0){
				min = d;
				bandera = 1;
			}
			if(d <= min){
				min = d;
				p1x = c[i].x;
				p1y = c[i].y;
				p2x = c[j].x;
				p2y = c[j].y;
			}
		}
	}
	printf("\nmínima distancia entre dos puntos cualesquiera: (%d,%d) y (%d,%d) = %.2f", p1x, p1y, p2x, p2y, min);
}
