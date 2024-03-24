#include <stdio.h>

void operacion(int n1, int n2, char car){
	float resultado;
	
	if (car == '+'){
		resultado = n1 + n2;
	}
	else if(car == '-'){
		resultado = n1 - n2;
	}
	else if(car == '*'){
		resultado = n1 * n2;
	}
	else if (car == '/'){
		if (n2 != 0){
			resultado = (float)n1 / (float)n2;
		}
		else{
			printf("No se puede dividir por '0'\n");
			return; // caso no valido
		}
	}
	else {
		printf("Operación no válida\n");
		return; // caso error
	}
	
	//resultado
	printf("%d %c %d = %.1f\n", n1, car, n2, resultado);
}
	
int main() {
	int n1;
	int n2;
	char car;
		
	printf("Ingrese el 1er numero: ");
	scanf("%d", &n1);
	printf("Ingrese el 2do numero: ");
	scanf("%d", &n2);
		
	// Limpieza buffer de entrada
	while(getchar() != '\n'); 
	printf("Ingrese la operacion[+ - * /]: ");
	car = getchar();
		
	operacion(n1, n2, car);
		
	return 0;
}
	
