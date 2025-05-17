#include <stdio.h>
#include <math.h>
#include <ctype.h>
//Opcion menu
int ingresarOpcionMenu();

//Opcion 1.
int ingresarOpciones1();
void menuOpciones1(int opc);
//Operaciones
void ingresarNumeros(float *num, float *num1, int opc, char letra);
void suma(float num, float num1);
void resta(float num, float num1);
void multiplicacion(float num, float num1);
void division(float num, float num1);
void potencia(float base, float exponente);
void raiz(float indice, float radicando);

//Opcion 3
int ingresarOpciones3();
void menuOpciones3(int opc);
void ingresarFilasColumnas(int *F, int *F1, int *C, int *C1, int *N, int opc);
void ingresarMatriz(int *F, int *F1, int *C, int *C1, int *N, float matrizA[10][10], float matrizB[10][10], int opc);

//Operaciones
void matrizSuma(int F, int C, float A[10][10], float B[10][10]);
void matrizResta(int F, int C, float A[10][10], float B[10][10]);
void matrizPorEscalar(int F, int C, float A[10][10], float escalar);
void matrizPorMatriz(int F, int F1, int C, int C1, float A[10][10], float B[10][10], int opc);
void matrizDeterminante(int N, float matriz[10][10]);
void matrizInversa(int N, float matriz[10][10], int opc);
void divisionMatrices(int FA, int CA, int N, float A[10][10], float inv[10][10], int opc);

int main(){
	int opcionMenu, opcion1, opcion3;
	
	printf("Calculadora:");
	
	do{
	
	printf("\n\n");
	
	opcionMenu = ingresarOpcionMenu();
	
		switch(opcionMenu){
			case 1:
				opcion1 = ingresarOpciones1();
				menuOpciones1(opcion1);			
				
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
	
	}while(opcionMenu != 0);
	

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

void menuOpciones1(int opc){
	char opcLetra;
	switch(opc){
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
			ingresarNumeros(&num, &num1, opc, opcLetra);
						
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
					ingresarNumeros(&base, &exponente, opc, opcLetra);
					potencia(base, exponente);
				break;
				
				case 'R':
					ingresarNumeros(&radical, &indice, opc, opcLetra);
					raiz(radical, indice);
				break;
			}
			
		break;
	}
}

void ingresarNumeros(float *num, float *num1, int opc, char letra){
	if(opc == 1){
	printf("\n\nIngrese el primer numero: ");
	scanf("%f", num);
	printf("Ingrese el segundo numero: ");
	scanf("%f", num1);
	}
	else if(opc == 2){
		if(letra == 'P'){
			printf("\n\nIngrese la base: ");
			scanf("%f", num);
			printf("Ingrese el exponente: ");
			scanf("%f", num1);
		}
		else if(letra == 'R'){
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
	printf("\n%.2f + %.2f es igual a %.2f", num, num1, resultado);
}

void resta(float num, float num1){
	printf("\n\nResta: \n");
	float resultado = num - num1;
	printf("\n%.2f - %.2f es igual a %.2f", num, num1, resultado);
}

void multiplicacion(float num, float num1){
	printf("\n\nMultiplicacion: \n");
	float resultado = num * num1;
	printf("\n%.2f x %.2f es igual a %.2f", num, num1, resultado);
}

void division(float num, float num1){
	printf("\n\nDivision: \n");
	float resultado = num / num1;
	if(num1 != 0){
		printf("\n%.2f / %.2f es igual a %.2f", num, num1, resultado);
	}
	else{
		printf("\nError matematico.\n\n");
	}
}

void potencia(float base, float exponente){
	printf("\n\nPotencia: \n");
	float resultado = pow(base, exponente);
	printf("\n%2.f elevado a %.2f es igual a %.2f", base, exponente, resultado);
}

void raiz(float radical, float indice){
	int indiceEntero = indice;
	printf("\n\nRaiz: \n");
	float resultado = pow(radical, (1.0 / indice));
	
	if(indice == 0){
		printf("\nError matematico.");
	}
	else if(radical < 0 && (indiceEntero == indice) && (indiceEntero % 2 == 0)){
			printf("\nError matematico.");
	}
	else{
		printf("\nLa raiz %.2f de %.2f es igual a: %.2f", indice, radical, resultado);
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
	int filas, filas1, columnas, columnas1, N;
	float matrizA[10][10], matrizB[10][10];
	float escalar;
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
			
			ingresarMatriz(&filas, &filas1, &columnas, &columnas1, &N, matrizA, matrizB, opc);
			
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
			ingresarMatriz(&filas, &filas1, &columnas, &columnas1, &N, matrizA, matrizB, opc);
			printf("\n\nIngrese el valor de un Escalar para multiplicar a la matriz: ");
			scanf("%f", &escalar);
			
			matrizPorEscalar(filas, columnas, matrizA, escalar);			
			
		break;
		
		case 3:
			ingresarMatriz(&filas, &filas1, &columnas, &columnas1, &N, matrizA, matrizB, opc);
			matrizPorMatriz(filas, filas1, columnas, columnas1, matrizA, matrizB, opc);					
		break;
		
		case 4:
			ingresarMatriz(&filas, &filas1, &columnas, &columnas1, &N, matrizA, matrizB, opc);
			matrizDeterminante(N, matrizA);
			
		break;
		case 5:
			ingresarMatriz(&filas, &filas1, &columnas, &columnas1, &N, matrizA, matrizB, opc);
			matrizInversa(N, matrizA, opc);
		break;
		case 6:
			ingresarMatriz(&filas, &filas1, &columnas, &columnas1, &N, matrizA, matrizB, opc);
			divisionMatrices(filas, columnas, N, matrizA, matrizB, opc);
		break;
	}
}

void ingresarMatriz(int *F, int *F1, int *C, int *C1, int *N, float matrizA[10][10], float matrizB[10][10], int opc){
	int i, j;
	
	ingresarFilasColumnas(F, F1, C, C1, N, opc);
	
	if(opc == 1 || opc == 3 || opc == 6){
		printf("\n\nIngrese los valores de la matriz A:\n");
	
		for(i=0; i < *F; i++){
			for(j=0; j < *C; j++){
				printf("\t\tA[%d][%d]: > ", i, j);
				scanf("%f", &matrizA[i][j]);
			}
		}
	
 		
 		if(opc == 1){
 		printf("\n\nIngrese los valores de la matriz B:\n");
 			
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
		else if (opc == 6){
			printf("\n\nIngrese los valores de la matriz B:\n");
			for(i=0; i < *N; i++){
				for(j=0; j < *N; j++){
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
	else if(opc == 4 || opc == 5){
		printf("\n\nIngrese los valores de la matriz cuadrada:\n");
		for(i=0; i < *N; i++){
			for(j=0; j < *N; j++){
				printf("\t\tA[%d][%d]: > ", i, j);
				scanf("%f", &matrizA[i][j]);
			}
		}
	}
	
	
}
	

void ingresarFilasColumnas(int *F, int *F1, int *C, int *C1, int *N, int opc){
	
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
	
	else if(opc == 4  || opc == 5){
		
			printf("\n\nIngrese el tamanio la matriz: ");
			scanf("%d", N);
			while(*N < 1 || *N > 10){
				printf("Cantidad no valida, considere entre los valores del 1 al 10: ");
				scanf("%d", N);
			}
	
	}
	else if(opc == 6){
		do{
			printf("\n\nIngrese las filas de la primer matriz: ");
			scanf("%d", F);
			while(*F < 1 || *F > 10){
				printf("Cantidad no valida, considere entre los valores del 1 al 10: ");
				scanf("%d", F);
			}
			
			printf("Ingrese las columnas de la primer matriz: ");
			scanf("%d", C);
			while(*C < 1 || *C > 10){
				printf("Cantidad no valida, considere entre los valores del 1 al 10: ");
				scanf("%d", C);
			}
		
		
			printf("\n\nIngrese el tamanio la segunda matriz: ");
			scanf("%d", N);
			while(*N < 1 || *N > 10){
				printf("Cantidad no valida, considere entre los valores del 1 al 10: ");
				scanf("%d", N);
			}
			
			if(*C != *N){
    			   printf("\n\nError: Para dividir matrices, la cantidad de columnas de la primera matriz debe ser igual al tamanio de la segunda matriz.\n");
    		}
    	}while(*C != *N);	
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


void matrizPorMatriz(int FA, int FB, int CA, int CB, float A[10][10], float B[10][10], int opc){
	int i, j, k;
	float resultado[10][10];
	
	for(i=0; i < FA; i++){
		for(j=0; j < CB; j++){
			resultado[i][j] = 0;
			for(k=0; k < CA; k++){
				resultado[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	
	if(opc != 6){
		printf("\n\nLa Matriz resultante de la multiplicacion es igual a: \n\n");
		for(i=0; i < FA; i++){
			for(j=0; j < CB; j++){
				printf("|%.2f|", resultado[i][j]);
			}
			printf("\n");
		}
	}
	
	else{
		printf("\n\nLa Matriz resultante de la division de matrices es igual a: \n\n");
		for(i=0; i < FA; i++){
			for(j=0; j < CB; j++){
				printf("|%.5f|", resultado[i][j]);
			}
			printf("\n");
	}
}
	
	
	
}

void matrizDeterminante(int N, float matriz[10][10]){
	
	
	
	
}

void matrizInversa(int N, float matriz[10][10], int opc){
    int i, j, k;
    float identidad[10][10];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == j) {
                identidad[i][j] = 1.0;
            } else {
                identidad[i][j] = 0.0;
            }
        }
    }
    for (i = 0; i < N; i++) {
        float pivote = matriz[i][i];
        for (j = 0; j < N; j++) {
            matriz[i][j] = matriz[i][j] / pivote;
            identidad[i][j] = identidad[i][j] / pivote;
        }

        for (k = 0; k < N; k++) {
            if (k != i) {
                float factor = matriz[k][i];
                for (j = 0; j < N; j++) {
                    matriz[k][j] = matriz[k][j] - factor * matriz[i][j]; 
                    identidad[k][j] = identidad[k][j] - factor * identidad[i][j];
                }
            }
        }
    }
    
    	for(i = 0; i < N; i++) {
        	for (j = 0; j < N; j++) {
            	matriz[i][j] = identidad[i][j];
        	}
    	}
    
    
    if(opc != 6){
		printf("La matriz inversa es: \n");
    	for (i = 0; i < N; i++) {
        	for (j = 0; j < N; j++) {
            	printf("%f ", identidad[i][j]);
        	}
        	printf("\n");
    	}
	}
}

void divisionMatrices(int FA, int CA, int N, float A[10][10], float inv[10][10], int opc){
	int i, j;
	
	matrizInversa(N, inv, opc);
	
	matrizPorMatriz(FA, N, CA, N, A, inv, opc);
	
}