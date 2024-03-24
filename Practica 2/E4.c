#include <stdio.h>
#define N 3
#define TAM 20

struct informacion{
	int dni;
	char nombre[TAM];
	char pais[TAM];
};

typedef struct informacion info;

void carga_datos(info datos[N]){
	int i = 0, j = 0;
	int d;
	char c1, c2;
	printf("cargue documento: ");
	scanf("%d", &d);
	while(i < N && d != 0){
		datos[i].dni = d;
		
		printf("Cargue nombre: ");
		fflush(stdin);
		c1 = getchar();
		for(j=0; j<TAM-1 && c1 != '\n'; j++){
			datos[i].nombre[j] = c1;
			if(j<TAM-1){
				c1 = getchar();
			}
		}
		datos[i].nombre[j] = '\0';
		
		printf("Cargue pais: ");
		fflush(stdin);
		c2 = getchar();
		for(j=0; j<TAM-1 && c2 != '\n'; j++){
			datos[i].pais[j] = c2;
			if(j<TAM-1){
				c2 = getchar();
			}
		}
		datos[i].pais[j] = '\0';
		
		printf("\n");
		i++;
		if(i < N){
			printf("cargue documento: ");
			scanf("%d", &d);
		}
	}
	
	printf("\n");
	for(j=0; j<i; j++){
		printf("%d,", datos[j].dni);
		printf("%s,", datos[j].nombre);
		printf("%s\n", datos[j].pais);
	}
}

int main() {
	info datos[N];
	carga_datos(datos);
	return 0;
}
