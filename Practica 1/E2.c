#include <stdio.h>

int redondeo(float n){
	int base = (int)n;
	if(n - base >= 0.5){
		return base + 1;
	}else{
		return base;
	}
}
int piso(float n){
	return (int)n;
}
int techo(float n){
	int base = (int)n;
	if(n > base){
		return base + 1;
	}else{
		return base;
	}
}
int main() {
	float num;
	printf("Ingrese un numero real: ");
	scanf("%f", &num);
	printf("Redondeo: %d",redondeo(num));
	printf("\nPiso: %d",piso(num));
	printf("\nTecho: %d",techo(num));
	
	return 0;
}

