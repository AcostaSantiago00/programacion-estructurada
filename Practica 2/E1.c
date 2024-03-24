#include <stdio.h>

struct s_punto {
	int x;
	int y;
};

typedef struct s_punto coord;

int main() {
	coord arr[2];
	
	arr[0].x = 0;
	arr[0].y = 4;
	
	printf("Ingrese una coordenada (x,y): \n");
	scanf("%d", &arr[1].x);
	scanf("%d", &arr[1].y);
	
	if (arr[1].x > arr[0].x) {
		printf("El segundo punto está más a la derecha que el primero.\n");
	} else {
		printf("El segundo punto no está más a la derecha que el primero.\n");
	}
	
	return 0;
}


