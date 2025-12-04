#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	int x, y, z;

	if (argc < 4){
		printf("Se necesitan tres argumentos\n");
		return 0;
	}
	x = strtol(argv[1], NULL, 10);
	y = strtol(argv[2], NULL, 10);
	z = strtol(argv[3], NULL, 10);

	if((x <= 0) || (y <= 0) || (z <= 0)){
		printf("Ningún parámetro puede ser <=0\n");
		return 0;
	}else if((x > 127) || (y > 127) || (z  > 127)){
		printf("Valor fuera de rango para char\n");
		return 0;
	}

	if(x+y+z>127){
		printf("Suma fuera de rango\n");
		return 0;
	}else if(x+y+z != 0){
		signed char res = (signed char)(x+y+z);
		printf("%d + %d + %d = %d .... si fuera cero...\n", x, y, z, res);
	}else{
		printf("Area privada\n");
	}
}
