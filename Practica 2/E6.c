#include <stdio.h>
#include <string.h>
#define N 3
#define TAM 20

struct informacion{
	int dni;
	char nombre[TAM];
	char pais[TAM];
};

typedef struct informacion info;

int carga_datos(info datos[N]);
void imprimirTabla(info datos[N], int cant_datos_ingresados);
void ordenarTabla(info datos[N], int cant_datos_ingresados);
void menu();
void ordenamiento(info aux, info datos[N], int i, int j);

int main() {
	int cant_datos_ingresados;
	info datos[N];
	cant_datos_ingresados = carga_datos(datos);
	ordenarTabla(datos, cant_datos_ingresados);
	return 0;
}

int carga_datos(info datos[N]){
	int i = 0, j = 0, d;
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

void imprimirTabla(info datos[N], int cant_datos_ingresados){
	int j;
	char d[TAM] = "Documento", n[TAM] = "Nombre", p[TAM] = "pais";
	printf("\n--------------------------------------------------\n");
	printf("\n%-15s%-20s%s", d, n, p);
	printf("\n=============================================\n");
	for(j=0; j<cant_datos_ingresados; j++){
		printf("%-15d%-20s%s\n", datos[j].dni, datos[j].nombre, datos[j].pais);
	}
	printf("\n--------------------------------------------------\n");
}

void ordenarTabla(info datos[N], int cant_datos_ingresados){
	int condicion, i, j;
	info aux;
	menu();
	scanf("%d", &condicion);
	while(condicion != 4){
		if(condicion == 1){
			for(i=0; i<cant_datos_ingresados-1; i++){
				for(j=i+1; j<cant_datos_ingresados; j++){
					if(strcmp(datos[i].nombre, datos[j].nombre) < 0){
						ordenamiento(aux, datos, i, j);
					}
				}
			}
		}
		
		else if(condicion == 2){
			for(i=0; i<cant_datos_ingresados; i++){
				for(j=i+1; j<cant_datos_ingresados; j++){
					if(datos[i].dni < datos[j].dni){
						ordenamiento(aux, datos, i, j);
					}
				}
			}
		}
		
		else if(condicion == 3){
			for(i=0; i<cant_datos_ingresados; i++){
				for(j=i+1; j<cant_datos_ingresados; j++){
					if(strcmp(datos[i].pais, datos[j].pais) < 0){
						ordenamiento(aux, datos, i, j);
					}
				}
			}
		}
		
		imprimirTabla(datos, cant_datos_ingresados);
		menu();
		scanf("%d", &condicion);
	}
}

void menu(){
	printf("\nMenu de opciones:\n");
	printf("1- Ver listado ordenado por nombre.\n");
	printf("2- Ver listado ordenado por documento.\n");
	printf("3- Ver listado ordenado por pais.\n");
	printf("4- Salir del programa\n");
	printf("Ingrese una opcion: ");
}

void ordenamiento(info aux, info datos[N], int i, int j){
	aux = datos[i];
	datos[i] = datos[j];
	datos[j] = aux;
}
