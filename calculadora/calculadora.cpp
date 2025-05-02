#include <stdio.h>
#include <math.h>
#include <ctype.h>
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

// Opcion 2

void vector (){
    int opcion_vect = 0;
     do {
         int n;
         printf ("ingrese la longitud del vector");
         scanf ("%d", &n);
         int* vector1 = new int[n];
         int* vector2 = new int[n];
         for (int i=0;i<n;i++){
             printf ("ingrese la posicion %d del vector 1", i);
             scanf ("%d", &vector2 [i]);
             printf ("ingrese la posicion %d del vector 2", i);
             scanf ("%d", &vector2 [i]);
         }
         printf ("ingrese que accion quiere realizar con el vector: \n");
         printf ("| opcion 1 = suma | \t");
         printf ("| opcion 2 = resta | \t");
         printf ("| opcion 3 = multiplicacion escalar | \n");
         printf ("| opcion 4 = producto escalar | \t");
         printf ("| opcion 5 = producto vectorial | \t");
         printf ("\n");
         scanf ("%d", &opcion_vect);
         switch (opcion_vect){
         case 0:
            printf("saliendo del programa");
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
        posi_suma [i] = posi_suma [i] + vector1[i] + vector2[i];
    }
    for (int i=0;i<n;i++){
        printf ("la suma de la posicion %d es: %d \n", i, posi_suma[i]);
        total_suma = total_suma + posi_suma[i];
    }
    printf ("el resultado total de la suma es: %d", total_suma);
}
void resta_vect(int* vector1, int* vector2, int n){}
void multi_esc_vect(int* vector1, int* vector2, int n){}
void prod_escalar(int* vector1, int* vector2, int n){}
void prod_vectorial(int* vector1, int* vector2, int n){}
