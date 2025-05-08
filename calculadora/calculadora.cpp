#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
//Opcion menu
int ingresarOpcionMenu();

//Opcion 1.
int ingresarOpciones1();
void menuOpciones1(int *opc);
//Operaciones
void ingresarNumeros(float *num, float *num1, int *opc, char *letra);
void suma(float num, float num1);
void resta(float num, float num1);
void multiplicacion(float num, float num1);
void division(float num, float num1);
void potencia(float base, float exponente);
void raiz(float indice, float radicando);

//Opcion 2
void vector ();
void suma_vect(int* vector1, int* vector2, int n);
void resta_vect(int* vector1, int* vector2, int n);
void multi_esc_vect(int* vector1, int* vector2, int n);
void prod_escalar(int* vector1, int* vector2, int n);
void prod_vectorial(int* vector1, int* vector2, int n);


//opcion 4
void obtenerCoeficientes();
int resolverSistema2x2(float a1, float b1, float c1, float a2, float b2, float c2, float *x, float *y);
int resolverSistema3x3(float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float a3, float b3, float c3, float d3, float *x, float *y, float *z);
int main(){
	int opcionMenu, opcion1;
	
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
				vector ();
			break;
			
			case 3:
				printf("\n\nHola mundo.\n\n");
			break;
			
			case 4:
			    obtenerCoeficientes();
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

// Opcion 2

void vector (){
    int opcion_vect = 0;
     do {
         int n;
         printf ("\n\nIngrese la longitud del vector: ");
         scanf ("%d", &n);
         int vector1 [n];
         int vector2 [n];
         
         printf("\n\n");
         for (int i=0;i<n;i++){
             printf ("Ingrese del vector 1 en la posicion %d: ", i);
             scanf ("%d", &vector1[i]);
         }
         printf("\n \n");
         for (int i=0;i<n;i++){
             printf ("Ingrese del vector 2 en la posicion %d: ", i);
             scanf ("%d", &vector2[i]);
         }
         
         printf ("\n\nIngrese que accion quiere realizar con el vector: \n");
         printf ("| opcion 1 = suma | \t");
         printf ("| opcion 2 = resta | \t");
         printf ("| opcion 3 = multiplicacion escalar | \n");
         printf ("| opcion 4 = producto escalar | \t");
         printf ("| opcion 5 = producto vectorial | \t");
         printf ("| opcion 0 = VOLVER AL MENU | \t\n");
         printf ("\t> ");
         scanf ("%d", &opcion_vect);
         while(opcion_vect < 0 || opcion_vect > 5){
         	printf("\tOpcion no valida.\n\n\tPor favor ingrese de nuevo la opcion correspondiente: > ");
		 	scanf ("%d", &opcion_vect);
		 }
         
         switch (opcion_vect){
         case 0:
            printf("\n\nVolviendo al menu...\n\n");
            break;
            
         case 1:
              suma_vect(vector1, vector2, n);
              break;
         
         case 2:
              resta_vect(vector1, vector2, n);
              break;
         
         case 3:
              multi_esc_vect(vector1, vector2, n);
              break;
         
         case 4:
              prod_escalar(vector1, vector2, n);
              break;
         
         case 5:
              if (n == 3){
                 prod_vectorial(vector1, vector2, n);
              }
              else {
                   printf ("no se puede hacer el producto vectorial porque no tiene 3 dimensiones");
              }
         break;
         }
     }while (opcion_vect !=0);     
}
void suma_vect(int* vector1, int* vector2, int n){
    int posi_suma [n];
    int total_suma = 0;
    for (int i=0;i<n;i++){
        posi_suma [i] = vector1[i] + vector2[i];
    }
    for (int i=0;i<n;i++){
        printf ("\nLa suma de la posicion %d es: %d", i, posi_suma[i]);
        total_suma = total_suma + posi_suma[i];
    }
    printf ("\n\nEl resultado total de la suma de todas las posiciones es de: %d", total_suma);
}
void resta_vect(int* vector1, int* vector2, int n){
    int posi_resta [n];
    int total_resta = 0;
    for (int i=0;i<n;i++){
        posi_resta [i] = vector1[i] - vector2[i];
    }
    for (int i=0;i<n;i++){
        printf ("\nLa suma de la posicion %d es: %d", i, posi_resta[i]);
        if (i != n - 1)
        total_resta = total_resta + (posi_resta[i] - posi_resta[i+ 1]);
    }
    printf ("\n\nEl resultado total de la suma de todas las posiciones es de: %d", total_resta);
}
void multi_esc_vect(int* vector1, int* vector2, int n){
    int escalar = 1;
    printf ("ingrese el escalar");
    scanf ("%d", &escalar);
    int resultado_escalar1[n];
    int resultado_escalar2[n];
    for (int i=0;i<n;i++){
        resultado_escalar1[i] = vector1[i] * escalar;
    }
    for (int i=0;i<n;i++){
        resultado_escalar2[i] = vector2[i] * escalar;
    }
    for (int i=0;i<n;i++){
        printf ("La multiplicacion escalar del vector 1 en la posicion %d es igual a %d \t ", i, resultado_escalar1[i]);
    }
    printf ("\n");
    for (int i=0;i<n;i++){
        printf ("La multiplicacion escalar del vector 2 en la posicion %d es igual a %d \t ", i, resultado_escalar2[i]);
    }
}
void prod_escalar(int* vector1, int* vector2, int n){
    int producto_escalar[n];
    int res_prod_esc;
    for (int i=0;i<n;i++){
        producto_escalar[i]= vector1[i] * vector2[i];
    }
    for (int i=0;i<n;i++){ 
        res_prod_esc = res_prod_esc + producto_escalar[i];
    }
    printf ("El resultado total del producto escalar es: %d ", res_prod_esc);
}
void prod_vectorial(int* vector1, int* vector2, int n){
    if (n == 3){
        int vector_x;
        int vector_y;
        int vector_z;
        vector_x = (vector1[1] * vector2[2]) - (vector1[2] * vector2 [1]); 
        vector_y = (vector1[0] * vector2[2]) - (vector1[2] * vector2 [0]); 
        vector_z = (vector1[0] * vector2[1]) - (vector1[1] * vector2 [0]); 
        
        printf ("el producto vectorial da X=%d - Y=%d - Z=%d", vector_x, vector_y, vector_z);
    }
    else{
        printf ("No se puede llevar a cabo el producto vectorial ya que la longitud del vector no es de 3");
    }
}

// opcion 4

void obtenerCoeficientes() {
	
	int opcion;
	
	printf("Ingrese 1 para resolver un sistema 2x2 \n");
	printf("Ingrese 2 para resolver un sistema 3x3 \n");
	scanf("%d", &opcion);
	
	while(opcion != 1 && opcion != 2){
		printf("Opcion invalida. Ingrese 1 para 2x2 o 2 para 3x3 \n");
		scanf("%d", &opcion);
	}
	
	
	 if (opcion == 1) {
        float a1, b1, c1, a2, b2, c2; // coeficientes
        float x, y; // soluciones

        printf("\nIngrese los coeficientes para la primera ecuacion x, y, su resultado: \n");
        while (scanf("%f %f %f", &a1, &b1, &c1) != 3) {  
            printf("Entrada invalida. Intente de nuevo: \n");
            while (getchar() != '\n');
        }

        printf("Ingrese los coeficientes para la segunda ecuacion x, y, su resultado: \n");
        while (scanf("%f %f %f", &a2, &b2, &c2) != 3) {  
            printf("Entrada invalida. Intente de nuevo: \n");
            while (getchar() != '\n');
        }

        int resultado = resolverSistema2x2(a1, b1, c1, a2, b2, c2, &x, &y);
        if (resultado == 0) {
            printf("\nResultado:\n");
            printf("X = %f\n", x);
            printf("Y = %f\n", y);
        } else {
            printf("\nNo se puede resolver el sistema.\n");
        }
    } 
    else if (opcion == 2) {
    
        float a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;
        float x, y, z;
        
        
        
        
        printf("Ingrese los coeficientes de la primera ecuacion");
         while (scanf("%f %f %f %f", &a1, &b1, &c1, &d1) != 4) {
            while (getchar() != '\n'); 
        printf("Entrada inválida. Intenta de nuevo:\n");
}
        
        
        printf("Ingrese los coeficientes de la segunda ecuacion");
       while (scanf("%f %f %f %f", &a2, &b2, &c2, &d2) != 4) {
        while (getchar() != '\n');
         printf("Entrada inválida. Intenta de nuevo:\n");
    }
        
        printf("Ingrese los coeficientes de la tercera ecuacion");
       while (scanf("%f %f %f %f", &a3, &b3, &c3, &d3) != 4) {
         while (getchar() != '\n'); 
        printf("Entrada inválida. Intenta de nuevo:\n");
}
        int resultado = resolverSistema3x3(a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3, &x, &y, &z);
        
        printf("X: %f \n", x);
        printf("Y: %f \n", y);
        printf("Z: %f \n", z);
        
        
    }
}

int resolverSistema2x2(float a1, float b1, float c1, float a2, float b2, float c2, float *x, float *y){
    
    if(a1 == 0){
        printf("No se puede resolver porque a1 es 0 \n");
        return 1;
    }
    
    
    float A = (-a2 * b1 / a1) +b2;
    float B = c2 - (a2 *c1 / a1);
    
    
    
    if (A == 0){
        printf("No se puede resolver el sistema por que se esta dividiendo por 0 \n");
        return 1;
    }
    
    *y = B / A;
    *x = (c1-b1 * (*y)) / a1;
    
    return 0;
}

int resolverSistema3x3(float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float a3, float b3, float c3, float d3, float *x, float *y, float *z){
    int i;
    float matriz[3][4] = {
        {a1, b1, c1, d1},
        {a2, b2, c2, d2},
        {a3, b3, c3, d3}
    };
    
    
    for(int i = 0 ; i< 3; i++){
        if(matriz[i][i] == 0){
            printf("No se puede resolver por que tiene 0");
            return 1;
        }
    }
    
    
    float pivote = matriz[i][i];
    for(int j = 0 ; j < 3; j++){
        matriz[i][j] /= pivote;
    }
    
    
    for(int k = 0; k < 3; k++){
        if(k != i){
            float factor = matriz[k][i];
            for(int j = 0; j<4 ; j++){
                matriz[k][i] -= factor * matriz[i][j];
            }
        }
    }
    
    
    *x = matriz[0][3];
    *y = matriz[1][3];
    *z = matriz[2][3];
    

    return 0;

    
    
    
} 
