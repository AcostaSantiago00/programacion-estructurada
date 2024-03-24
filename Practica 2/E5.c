#include <stdio.h>
#define N 3
#define TAM 20

struct informacion{
	int dni;
	char nombre[TAM];
	char pais[TAM];
};

typedef struct informacion info;

void imprimirTabla(info datos[N], int cant_datos_ingresados){
	int j;
	char d[TAM] = "Documento", n[TAM] = "Nombre", p[TAM] = "pais";
	printf("\n%-15s%-20s%s", d, n, p);
	printf("\n=============================================\n");
	for(j=0; j<cant_datos_ingresados; j++){
		printf("%-15d%-20s%s\n", datos[j].dni, datos[j].nombre, datos[j].pais);
	}
}
	
int carga_datos(info datos[N]){
	int i = 0, j = 0;
	int d;
	char c1, c2;
	printf("Cargue documento: ");
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
			printf("Cargue documento: ");
			scanf("%d", &d);
		}
	}
	return i;
	printf("\n");
}
	
int main() {
	int cant_datos_ingresados;
	info datos[N];
	cant_datos_ingresados = carga_datos(datos);
	imprimirTabla(datos, cant_datos_ingresados);
	return 0;
}
