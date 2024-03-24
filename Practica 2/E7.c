#include <stdio.h>
#define NA 5
#define NM 5

typedef struct{
	char nombre[100];
	int legajo, materias[30];
} t_alumno;

typedef struct
{
	char nombre[100];
	int codigo;
} t_materia;

typedef struct{
	int legajo_alumno;
	int cod_materia,nota;
} t_nota;

int cargaAlumnos(t_alumno salumnos[NA], t_materia smaterias[NM]);
void cargaMaterias(t_alumno salumnos[NA], t_materia smaterias[NM],int i);

int main() {
	int cant_alumnos_cargados;
	t_alumno salumnos[NA];
	t_materia smaterias[NM];
	cant_alumnos_cargados = cargaAlumnos(salumnos, smaterias);

	return 0;
}

int cargaAlumnos(t_alumno salumnos[NA], t_materia smaterias[NM]){
	char c;
	int legajo, i=0, j=0;
	printf("INGRESE LEGAJO DEL ALUMNO: ");
	scanf("%d", &legajo);
	
	while(legajo != 0 && i < NA){
		if(legajo < 0){
			printf("NUMERO INVALIDO. ");
		}else{
			salumnos[i].legajo = legajo;
			fflush(stdin);
			printf("INGRESE NOMBRE DEL ALUMNO: ");
			c = getchar();
			for(j=0; j<100-1 && c != '\n'; j++){
				salumnos[i].nombre[j] =  c;
				c = getchar();
			}
			salumnos[i].nombre[j] = '\0';
			cargaMaterias(salumnos, smaterias, i);
		}
		i++;
		printf("\nINGRESE LEGAJO DEL ALUMNO: ");
		scanf("%d", &legajo);
	}
	return i;
}

void cargaMaterias(t_alumno salumnos[NA], t_materia smaterias[NM],int i){
	int j = 0, k = 0, materia;
	char c;
	printf("INGRESE CODIGO DE LA MATERIA: ");
	scanf("%d", &materia);
	while(j < NM && materia != 0){
		if(materia < 0){
			printf("CODIGO DE MATERIA INVALIDO.");
		}else{
			salumnos[i].materias[j] = materia;
			smaterias[j].codigo = materia;
			
			printf("INGRESE NOMBRE DE LA MATERIA: ");
			fflush(stdin);
			c = getchar();
			for(k=0; k<100-1 && c != '\n' ;k++){
				smaterias[j].nombre[k] = c;
				c = getchar();
			}
			smaterias[j].nombre[k] = '\0';
		}
		printf("%d\n", smaterias[j].codigo);
		printf("%s\n", smaterias[j].nombre);
		j++;
		printf("INGRESE CODIGO DE LA MATERIA: ");
		scanf("%d", &materia);
	}
}
