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
void ingresarFilasColumnas(int *F, int *F1, int *C, int *C1, int opc);
void ingresarMatriz(int *F, int *F1, int *C, int *C1, float matrizA[10][10], float matrizB[10][10], int opc);

//Operaciones
void matrizSuma(int F, int C, float A[10][10], float B[10][10]);
void matrizResta(int F, int C, float A[10][10], float B[10][10]);
void matrizPorEscalar(int F, int C, float A[10][10], float escalar);
void matrizPorMatriz(int F, int F1, int C, int C1, float A[10][10], float B[10][10]);
float matrizDeterminante(int N, float matriz[10][10]);
void submatriz(float origen[10][10], float destino[10][10], int N, int fila, int columna);


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
	printf("\n%f + %f es igual a %2.f", num, num1, resultado);
}

void resta(float num, float num1){
	printf("\n\nResta: \n");
	float resultado = num - num1;
	printf("\n%f - %f es igual a %2.f", num, num1, resultado);
}

void multiplicacion(float num, float num1){
	printf("\n\nMultiplicacion: \n");
	float resultado = num * num1;
	printf("\n%f x %f es igual a %2.f", num, num1, resultado);
}

void division(float num, float num1){
	printf("\n\nDivision: \n");
	float resultado = num / num1;
	if(num1 != 0){
		printf("\n%f / %f es igual a %2.f", num, num1, resultado);
	}
	else{
		printf("\nError matematico.");
	}
	
}

void potencia(float base, float exponente){
	printf("\n\nPotencia: \n");
	float resultado = pow(base, exponente);
	printf("\n%f elevado a %f es igual a %2.f", base, exponente, resultado);
}

void raiz(float radical, float indice){
	printf("\n\nRaiz: \n");
	float resultado = pow(radical, (1.0 / indice));
	if(indice != 0){
		printf("\nLa raiz %f de %f es igual a: %2.f", radical, indice, resultado);
	}
	else{
		printf("\nError matematico.");
	}
}

int ingresarOpciones3(){
	int opcMenu3;
	
	do{	
		printf("\n\n\tIngrese 1. Si quiere realizar operaciones como Suma y Resta de Matrices.");
		printf("\n\n\tIngrese 2. Si quiere realizar Multiplicacion de un Escalar por una Matriz.");
		printf("\n\n\tIngrese 3. Si quiere realizar Multiplicacion de Matrices.");
		printf("\n\n\tIngrese 4. Si quiere realizar el Determinante de una Matriz.");
		printf("\n\n\tIngrese 5. Si quiere realizar la Inversa de una Matriz.");
		printf("\n\n\tIngrese 6. Si quiere realizar una Division entre dos Matrices.");
		printf("\n\n\tIngrese 0. Para volver al Menu principal.");
		printf("\n\n\n\tIngrese una opcion a elegir: > ");
		scanf("%d", &opcMenu3);
		while(opcMenu3 < 0 || opcMenu3 > 6){
			printf("\n\tOpcion no valida.\n\n\tPor favor ingrese de nuevo la opcion correspondiente: > ");
			scanf("%d", &opcMenu3);
		}
		
		return opcMenu3;
	
	}while(opcMenu3 != 0);
	
}

void menuOpciones3(int opc){
	char opcLetra;
	int tamanio, filas, filas1, columnas, columnas1;
	float matrizA[10][10], matrizB[10][10];
	float escalar;
	float resultado;
	
	switch(opc){
		
		case 0:
			printf("\n------------------------------------\n\nVolviendo al menu...\n\n------------------------------------");
		break;
		
		
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
			
			ingresarMatriz(&filas, &filas1, &columnas, &columnas1, matrizA, matrizB, opc);
			
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
			ingresarMatriz(&filas, &filas1, &columnas, &columnas1, matrizA, matrizB, opc);
			printf("\n\nIngrese el valor de un Escalar para multiplicar a la matriz: ");
			scanf("%f", &escalar);
			
			matrizPorEscalar(filas, columnas, matrizA, escalar);			
			
		break;
		
		case 3:
			ingresarMatriz(&filas, &filas1, &columnas, &columnas1, matrizA, matrizB, opc);
			matrizPorMatriz(filas, filas1, columnas, columnas1, matrizA, matrizB);					
		break;
		
		case 4:
			ingresarMatriz(&filas, &filas1, &columnas, &columnas1, matrizA, matrizB, opc);
			tamanio = filas;
			
			resultado = matrizDeterminante(tamanio, matrizA);			
			printf("\n\nEl determinante es: %.2f\n", resultado);

			
		break;
		case 5:
		break;
		case 6:
		break;
	}
}

void ingresarMatriz(int *F, int *F1, int *C, int *C1, float matrizA[10][10], float matrizB[10][10], int opc){
	int i, j;
	
	ingresarFilasColumnas(F, F1, C, C1, opc);
	
	if(opc == 1 || opc == 3){
		printf("\n\nIngrese los valores de la matriz A:\n");
	
		for(i=0; i < *F; i++){
			for(j=0; j < *C; j++){
				printf("\t\tA[%d][%d]: > ", i, j);
				scanf("%f", &matrizA[i][j]);
			}
		}
	
 		printf("\n\nIngrese los valores de la matriz B:\n");
 		
 		if(opc == 1){
 	
 			for(i=0; i < *F; i++){
 				for(j=0; j < *C; j++){
 					printf("\t\tB[%d][%d]: > ", i, j);
 					scanf("%f", &matrizB[i][j]);
			 	}
			}
		}
		else if(opc == 3){
			for(i=0; i < *F1; i++){
				for(j=0; j < *C1; j++){
					printf("\t\tB[%d][%d]: > ", i, j);
 					scanf("%f", &matrizB[i][j]);
				}
			}
		}
		
		
		
	}
	else if(opc == 2){
		printf("\n\nIngrese los valores de la matriz:\n");
		for(i=0; i < *F; i++){
			for(j=0; j < *C; j++){
				printf("\t\tA[%d][%d]: > ", i, j);
				scanf("%f", &matrizA[i][j]);
			}
		}
	}
	else if(opc == 4){
		printf("\n\nIngrese los valores de la matriz cuadrada:\n");
		for(i=0; i < *F; i++){
			for(j=0; j < *F; j++){
				printf("\t\tA[%d][%d]: > ", i, j);
				scanf("%f", &matrizA[i][j]);
			}
		}
	}
	
	
}
	

void ingresarFilasColumnas(int *F, int *F1, int *C, int *C1, int opc){
	
	if(opc == 1 || opc == 2){
		
		printf("\n\nIngrese la cantidad de filas: ");
			scanf("%d", F);
			while(*F < 1 || *F > 10){
				printf("Cantidad no valida, considere entre los valores del 1 al 10: ");
				scanf("%d", F);
			}
	
			printf("Ingrese la cantidad de columnas: ");
			scanf("%d", C);
			while(*C < 1 || *C > 10){
				printf("Cantidad no valida, considere entre los valores del 1 al 10: ");
				scanf("%d", C);
			}				
	}
	
	else if(opc == 3){
				
		do{
    		printf("\n\nIngrese la cantidad de filas de la Primer Matriz: ");
    		scanf("%d", F);
    		while(*F < 1 || *F > 10){
				printf("Cantidad no valida, considere entre los valores del 1 al 10: ");
				scanf("%d", F);
			}
			
    		printf("\nIngrese la cantidad de columnas de la Primer Matriz: ");
    		scanf("%d", C);
    		while(*C < 1 || *C > 10){
				printf("Cantidad no valida, considere entre los valores del 1 al 10: ");
				scanf("%d", C);
			}
			
    		printf("\nIngrese la cantidad de filas de la Segunda Matriz: ");
    		scanf("%d", F1);
    		while(*F1 < 1 || *F1 > 10){
				printf("Cantidad no valida, considere entre los valores del 1 al 10: ");
				scanf("%d", F1);
			}
			
    		printf("\nIngrese la cantidad de columnas de la Segunda Matriz: ");
    		scanf("%d", C1);
    		while(*C1 < 1 || *C1 > 10){
				printf("Cantidad no valida, considere entre los valores del 1 al 10: ");
				scanf("%d", C1);
			}

    		if(*C != *F1){
    	 	   printf("\n\nError: Para multiplicar matrices, la cantidad de columnas de la primera matriz debe ser igual a la cantidad de filas de la segunda.\n");
    		}

		}while(*C != *F1);
	
			
	}
	
	else if(opc == 4){
		
			printf("\n\nIngrese el tamanio la matriz: ");
			scanf("%d", F);
			while(*F < 1 || *F > 10){
				printf("Cantidad no valida, considere entre los valores del 1 al 10: ");
				scanf("%d", F);
			}
	
	}
	
}

void matrizSuma(int F, int C, float A[10][10], float B[10][10]){
	int i, j;
	float resultado[10][10];
	
	for(i=0; i < F; i++){
		for(j=0; j < C; j++){
			resultado[i][j] = A[i][j] + B[i][j];
		}
	}
	
//	printf("\n---------------------------------------"); ACORDATE AGREGAR ESTO JULIAN A TODOS LOS RESULTADOS PARA QUE QUEDE EL PROGRAMA MAS LEGIBLE DESDE LA CONSOLA.
	printf("\n\nLa Matriz Resultante de la Suma entre esas dos matrices es igual a:\n\n");
	
	for(i=0; i < F; i++){
		for(j=0; j < C; j++){
			printf("|%.2f|", resultado[i][j]);
		}
		printf("\n");
	}
//	printf("\n---------------------------------------");
}

void matrizResta(int F, int C, float A[10][10], float B[10][10]){
	int i, j;
	float resultado[10][10];
	
	for(i=0; i < F; i++){
		for(j=0; j < C; j++){
			resultado[i][j] = A[i][j] - B[i][j];
		}
	}
	
	printf("\n\nLa Matriz Resultado de la Resta entre esas dos matrices es igual a:\n\n");
	
	for(i=0; i < F; i++){
		for(j=0; j < C; j++){
			printf("|%.2f|", resultado[i][j]);
		}
		printf("\n");
	}
	
}

void matrizPorEscalar(int F, int C, float A[10][10], float escalar){
	int i, j;
	float resultado[10][10];
	
	for(i=0; i < F; i++){
		for(j=0; j < C; j++){
			resultado[i][j] = A[i][j] * escalar;
		}
	}
	
	printf("\n\nLa Matriz resultante es igual a: \n\n");
	for(i=0; i < F; i++){
		for(j=0; j < C; j++){
			printf("|%.2f|", resultado[i][j]);
		}
		printf("\n");
	}
}


void matrizPorMatriz(int FA, int FB, int CA, int CB, float A[10][10], float B[10][10]){
	int i, j, k;
	float resultado[10][10];
	
	for(i=0; i < CA; i++){
		for(j=0; j < CB; j++){
			resultado[i][j] = 0;
			for(k=0; k < CA; k++){
				resultado[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	
	printf("\n\nLa Matriz resultante es igual a: \n\n");
	for(i=0; i < FA; i++){
		for(j=0; j < CB; j++){
			printf("|%.2f|", resultado[i][j]);
		}
		printf("\n");
	}
	
}

float matrizDeterminante(int N, float matriz[10][10]){
	float resultado, menor[10][10], det=0, signo=1;
	int i, j;
	
	matriz[N][N];

    if(N == 1){
        resultado = matriz[0][0];
	}

    else if(N == 2){
       resultado = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
	}

    else if(N >= 3){
		for(int j=0; j < N; j++) {
        	submatriz(matriz, menor, N, 0, j);
        	resultado += signo * matriz[0][j] * matrizDeterminante(N - 1, menor);
        	signo *= -1;
    	}
	}
	
	return resultado;
	
		
}

void submatriz(float origen[10][10], float destino[10][10], int N, int fila, int columna){
    int i, j, Ni=0, Nj=0;

    for(i=0; i < N; i++){
        if(i != fila){
            Nj = 0;
            for(j=0; j < N; j++){
                if(j != columna){
                    destino[Ni][Nj] = origen[i][j];
                    Nj++;
                }
            }
            Ni++;
        }
    }
}





/*
PARTE MÍA
Multiplicación de matrices → Necesitás 2 matrices compatibles (por ejemplo MxN × NxP).

Determinante de una matriz → Solo 1 matriz cuadrada.

HASTA ACÁ


Inversa de una matriz → Solo 1 matriz cuadrada.

División de matrices → Interpretada como A × (inversa de B) → Requiere 2 matrices, donde la segunda debe ser cuadrada e invertible.

*/