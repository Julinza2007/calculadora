#include <stdio.h>
#include <math.h>

int ingresarOpcionMenu();

int main(){
	int opcionMenu;
	
	printf("Calculadora:");
	
	do{
	
	printf("\n\n");
	
	opcionMenu = ingresarOpcionMenu();
	
		switch(opcionMenu){
			case 1:
				printf("\n\nHola mundo.\n\n");
			break;
			
			case 2:
				printf("\n\nHola mundo.\n\n");
			break;
			
			case 3:
				printf("\n\nHola mundo.\n\n");
			break;
			
			case 4:
				printf("\n\nHola mundo.\n\n");
			break;
			
			case 0:
				printf("\n\n\nSaliendo...");
			break;
		}
	
	}
	while(opcionMenu != 0);
	

return 0;
}


int ingresarOpcionMenu(){
	int opc;
	
	printf("Ingrese 1. Si quiere realizar operaciones basicas.\n\n");
	printf("Ingrese 2. Si quiere realizar operaciones con vectores de tamanio N.\n\n");
	printf("Ingrese 3. Si quiere realizar operaciones con matrices de tamanio M x N / N x N.\n\n");
	printf("Ingrese 4. Si quiere resolver un sistema de ecuaciones de 2x2 o 3x3.\n\n");
	printf("Ingrese 0. Si quiere salir del programa.\n\n");
	printf("\tIngrese una de esas opciones: > ");
	scanf("%d", &opc);
	while(opc < 0 || opc > 4){
		printf("Opcion no valida.\nPor favor ingrese de nuevo la opcion correspondiente: > ");
		scanf("%d", &opc);
	}
	
	return opc;
}