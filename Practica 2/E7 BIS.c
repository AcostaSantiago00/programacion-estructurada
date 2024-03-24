#include <stdio.h>
#define NA 5
#define NM 5

typedef struct{
	char nombre[100];
	int legajo, materias[30];
} t_alumno;

typedef struct{
	char nombre[100];
	int codigo;
} t_materia;

typedef struct{
	int legajo_alumno;
	int cod_materia,nota;
} t_nota;

void cargaAlumnos(t_alumno salumnos[NA]);
void cargaMaterias(t_materia smaterias[NM]);
void cargaNotas(t_alumno salumnos[NA], t_materia smaterias[NM]);
void funNotas(t_nota notas);

int main() {
	t_alumno salumnos[NA];
	t_materia smaterias[NM];
	
	cargaAlumnos(salumnos);
	cargaMaterias(smaterias);
	cargaNotas(salumnos, smaterias);
	return 0;
}

void cargaAlumnos(t_alumno salumnos[NA]){
	char c;
	int legajo, i=0, j=0, codmateria, k=0;
	printf("INGRESE LEGAJO DEL ALUMNO (0 para terminar): ");
	scanf("%d", &legajo);
	
	while(legajo != 0 && i < NA-1){
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
			
			printf("INGRESE CODIGOS DE LAS MATERIAS QUE CURSO EL ALUMNO (0 para terminar): ");
			scanf("%d", &codmateria);
			while (codmateria != 0 && k<30-1){
				if(codmateria < 0){
					printf("CODIGO DE MATERIA INVALIDO.");
				}else{
					salumnos[i].materias[k] = codmateria;
					printf("%d", salumnos[i].materias[k]);
				}
				k++;
				printf("INGRESE CODIGOS DE LAS MATERIAS QUE CURSO EL ALUMNO (0 para terminar): ");
				scanf("%d", &codmateria);
			}
			salumnos[i].materias[k] = codmateria;
		}
		k=0;
		i++;
		printf("\nINGRESE LEGAJO DEL ALUMNO (0 para terminar): ");
		scanf("%d", &legajo);
	}
	salumnos[i].legajo = legajo;
	printf("\n-----------------------------------------------------\n");
}
	
void cargaMaterias(t_materia smaterias[NM]){
	int i = 0, j = 0, materia;
	char c;
	printf("INGRESE CODIGO DE LA MATERIA: ");
	scanf("%d", &materia);
	while(i < NM && materia != 0){
		if(materia < 0){
			printf("CODIGO DE MATERIA INVALIDO.");
		}else{
			smaterias[i].codigo = materia;
			
			printf("INGRESE NOMBRE DE LA MATERIA: ");
			fflush(stdin);
			c = getchar();
			for(j=0; j<100-1 && c != '\n' ; j++){
				smaterias[i].nombre[j] = c;
				c = getchar();
			}
			smaterias[i].nombre[j] = '\0';
		}
		i++;
		if(i < NM){
			printf("INGRESE CODIGO DE LA MATERIA: ");
			scanf("%d", &materia);
		}
	}
	smaterias[i].codigo = materia;
	printf("\n-----------------------------------------------------\n");
}

void cargaNotas(t_alumno salumnos[NA], t_materia smaterias[NM]){
	t_nota 
	int i, j;
	for(i=0; i<NA && salumnos[i].legajo != 0; i++){
		for(j=0; j<30-1 && salumnos[i].materias != 0; j++){
			if(salumnos[i].materias[j] == smaterias[i].codigo){
				printf("Ingrese la nota de %s para la materia %s: ", salumnos[i].nombre, smaterias[i].nombre);
				//funNotas(notas);???????????????????
			}
		}
	}
}
