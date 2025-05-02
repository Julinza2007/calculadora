#include <stdio.h>
#include <math.h>
#include <ctype.h>
//Opcion menu
int ingresarOpcionMenu();

//Opcion 1.
int ingresarOpciones1();
void menuOpciones1(int *opc);
void ingresarNumeros(float *num, float *num1, int *opc, char *letra);
//Operaciones
void suma(float num, float num1);
void resta(float num, float num1);
void multiplicacion(float num, float num1);
void division(float num, float num1);
void potencia(float base, float exponente);
void raiz(float indice, float radicando);

//Opcion 3
int ingresarOpciones3();
void menuOpciones3(int opc);
void ingresarMatrizAyB(int *F, int *C, int matrizA[10][10], int matrizB[10][10]);
//Operaciones
void matrizSuma(int F, int C, int A[10][10], int B[10][10]);
void matrizResta(int F, int C, int A[10][10], int B[10][10]);



int main(){
	int opcionMenu, opcion1, opcion3;
	
	printf("Calculadora:");
	
	do{
	
	printf("\n\n");
	
	opcionMenu = ingresarOpcionMenu();
	
		switch(opcionMenu){
			case 1:
				opcion1 = ingresarOpciones1();
				menuOpciones1(&opcion1);
				
				
			break;
			
			case 2:
				printf("\n\nHola mundo.\n\n");
			break;
			
			case 3:
				opcion3 = ingresarOpciones3();
				menuOpciones3(opcion3);
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
		printf("\nOpcion no valida.\n\nPor favor ingrese de nuevo la opcion correspondiente: > ");
		scanf("%d", &opc);
	}
	
	return opc;
}

int ingresarOpciones1(){
	int opcMenu1;
	printf("\n\n\tIngrese 1. Si quiere realizar operaciones como Suma, Resta, Multiplicacion o Division.");
	printf("\n\n\tIngrese 2. Si quiere realizar operaciones como Potencias o Raices.");
	printf("\n\n\n\tIngrese una opcion a elegir: > ");
	scanf("%d", &opcMenu1);
	while(opcMenu1 != 1 && opcMenu1 != 2){
		printf("\n\tOpcion no valida.\n\n\tPor favor ingrese de nuevo la opcion correspondiente: > ");
		scanf("%d", &opcMenu1);
	}
	return opcMenu1;
}

void menuOpciones1(int *opc){
	char opcLetra;
	switch(*opc){
		case 1:
			printf("\n\n\tIngrese S. Para realizar una Suma.\n");
			printf("\tIngrese R. Para realizar una Resta.\n");
			printf("\tIngrese M. Para realizar una Multiplicacion.\n");
			printf("\tIngrese D. para realizar una Division.\n\n");
			printf("\tIngrese una opcion: > ");
			scanf(" %c", &opcLetra);			
			opcLetra = toupper(opcLetra);
			
			while(opcLetra != 'S' && opcLetra != 'R' && opcLetra != 'M' && opcLetra != 'D'){
				printf("\n\tOpcion no valida.\n\n\tPor favor ingrese de nuevo la opcion correspondiente: > ");
				scanf(" %c", &opcLetra);
			}
			
			float num, num1;
			ingresarNumeros(&num, &num1, opc, &opcLetra);
						
			switch(opcLetra){
				case 'S':
					suma(num, num1);
				break;
				
				case 'R':
					resta(num, num1);	
				break;
				
				case 'M':
					multiplicacion(num, num1);
				break;
				
				case 'D':
					division(num, num1);
				break;
				
			}
			
		break;
		
		case 2:
			float base, exponente, radical, indice;
			printf("\n\n\tIngrese P. Para realizar Potencia.\n");
			printf("\tIngrese R. Para realizar Raiz.\n\n");
			printf("\tIngrese una opcion: > ");
			scanf(" %c", &opcLetra);
			opcLetra = toupper(opcLetra);
			
			while(opcLetra != 'P' && opcLetra != 'R'){
				printf("\tOpcion no valida.\n\n\tPor favor ingrese de nuevo la opcion correspondiente: > ");
				scanf(" %c", &opcLetra);
			}
			
			
			switch(opcLetra){
				case 'P':
					ingresarNumeros(&base, &exponente, opc, &opcLetra);
					potencia(base, exponente);
				break;
				
				case 'R':
					ingresarNumeros(&radical, &indice, opc, &opcLetra);
					raiz(radical, indice);
				break;
			}
			
		break;
	}
}

void ingresarNumeros(float *num, float *num1, int *opc, char *letra){
	if(*opc == 1){
	printf("\n\nIngrese el primer numero: ");
	scanf("%f", num);
	printf("Ingrese el segundo numero: ");
	scanf("%f", num1);
	}
	else if(*opc == 2){
		if(*letra == 'P'){
			printf("\n\nIngrese la base: ");
			scanf("%f", num);
			printf("Ingrese el exponente: ");
			scanf("%f", num1);
		}
		else if(*letra == 'R'){
			printf("\n\nIngrese el radical: ");
			scanf("%f", num);
			printf("Ingrese el indice: ");
			scanf("%f", num1);
		}
	}
}

void suma(float num, float num1){
	
	printf("\n\nSuma: \n");
	float resultado = num + num1;
	printf("\n%f + %f es igual a %f", num, num1, resultado);
}

void resta(float num, float num1){
	printf("\n\nResta: \n");
	float resultado = num - num1;
	printf("\n%f - %f es igual a %f", num, num1, resultado);
}

void multiplicacion(float num, float num1){
	printf("\n\nMultiplicacion: \n");
	float resultado = num * num1;
	printf("\n%f x %f es igual a %f", num, num1, resultado);
}

void division(float num, float num1){
	printf("\n\nDivision: \n");
	float resultado = num / num1;
	printf("\n%f / %f es igual a %f", num, num1, resultado);
}

void potencia(float base, float exponente){
	printf("\n\nPotencia: \n");
	float resultado = pow(base, exponente);
	printf("\n%f elevado a %f es igual a %f", base, exponente, resultado);
}

void raiz(float radical, float indice){
	printf("\n\nRaiz: \n");
	float resultado = pow(radical, (1 / indice));
	printf("\nLa raiz %f de %f es igual a: %f", radical, indice, resultado);
}

int ingresarOpciones3(){
	int opcMenu3;
	
	printf("\n\n\tIngrese 1. Si quiere realizar operaciones como Suma y Resta de Matrices.");
	printf("\n\n\tIngrese 2. Si quiere realizar Multiplicacion de un Escalar por una Matriz.");
	printf("\n\n\tIngrese 3. Si quiere realizar Multiplicacion de Matrices.");
	printf("\n\n\tIngrese 4. Si quiere realizar el Determinante de una Matriz.");
	printf("\n\n\tIngrese 5. Si quiere realizar la Inversa de una Matriz.");
	printf("\n\n\tIngrese 6. Si quiere realizar una Division entre dos Matrices.");	
	printf("\n\n\n\tIngrese una opcion a elegir: > ");
	scanf("%d", &opcMenu3);
	while(opcMenu3 < 1 || opcMenu3 > 6){
		printf("\n\tOpcion no valida.\n\n\tPor favor ingrese de nuevo la opcion correspondiente: > ");
		scanf("%d", &opcMenu3);
	}	
	return opcMenu3;
}

void menuOpciones3(int opc){
	char opcLetra;
	int filas, columnas, matrizA[10][10], matrizB[10][10];
	
	switch(opc){
		
		case 1:
			printf("\n\n\tIngrese S. Para realizar una Suma entre Matrices.\n");
			printf("\tIngrese R. Para realizar una Resta entre Matrices.\n\n");
			printf("\tIngrese una opcion: > ");
			scanf(" %c", &opcLetra);
			opcLetra = toupper(opcLetra);
			
			while(opcLetra != 'S' && opcLetra != 'R'){
				printf("\n\tOpcion no valida.\n\n\tPor favor ingrese de nuevo la opcion correspondiente: > ");
				scanf(" %c", &opcLetra);
			}
			
			ingresarMatrizAyB(&filas, &columnas, matrizA, matrizB);
			
			switch(opcLetra){
				case 'S':
					matrizSuma(filas, columnas, matrizA, matrizB);	
				break;
				
				case 'R':
					matrizResta(filas, columnas, matrizA, matrizB);	
				break;
			}
			
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
		break;
		case 5:
		break;
		case 6:
		break;
	}
}

void ingresarMatrizAyB(int *F, int *C, int matrizA[10][10], int matrizB[10][10]){
	int i, j;
	
	printf("\n\n\tIngrese la cantidad de filas: ");
	scanf("%d", F);
	while(*F < 1 || *F > 10){
		printf("Cantidad no valida, considere entre los valores del 1 al 10: ");
		scanf("%d", F);
	}
	
	printf("\tIngrese la cantidad de columnas: ");
	scanf("%d", C);
	while(*C < 1 || *C > 10){
		printf("Cantidad no valida, considere entre los valores del 1 al 10: ");
		scanf("%d", C);
	}
	
	printf("\n\n\tIngrese los valores de la matriz A:\n");
	
	for(i=0; i < *F; i++){
		for(j=0; j < *C; j++){
			printf("\t\tA[%d][%d]: > ", i, j);
			scanf("%d", &matrizA[i][j]);
		}
	}
	
 	printf("\n\n\tIngrese los valores de la matriz B:\n");
 	
 	for(i=0; i < *F; i++){
 		for(j=0; j < *C; j++){
 			printf("\t\tB[%d][%d]: > ", i, j);
 			scanf("%d", &matrizB[i][j]);
		 }
	 }
		
}

void matrizSuma(int F, int C, int A[10][10], int B[10][10]){
	int i, j, resultado[10][10];
	
	for(i=0; i < F; i++){
		for(j=0; j < C; j++){
			resultado[i][j] = A[i][j] + B[i][j];
		}
	}
	
	printf("\n\nLa Matriz Resultado de la Suma entre esas dos matrices es igual a:\n\n");
	
	for(i=0; i < F; i++){
		for(j=0; j < C; j++){
			printf("|%d|", resultado[i][j]);
		}
		printf("\n");
	}
}

void matrizResta(int F, int C, int A[10][10], int B[10][10]){
	int i, j, resultado[10][10];
	
	for(i=0; i < F; i++){
		for(j=0; j < C; j++){
			resultado[i][j] = A[i][j] - B[i][j];
		}
	}
	
	printf("\n\nLa Matriz Resultado de la Resta entre esas dos matrices es igual a:\n\n");
	
	for(i=0; i < F; i++){
		for(j=0; j < C; j++){
			printf("|%d|", resultado[i][j]);
		}
		printf("\n");
	}
	
}