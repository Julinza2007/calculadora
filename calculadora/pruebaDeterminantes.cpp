#include <stdio.h>

// Genera la submatriz menor al eliminar la fila 'fila' y la columna 'col'
void submatriz(float origen[10][10], float destino[10][10], int N, int fila, int columna) {
    int i, j, Ni = 0, Nj;

    for (i=0; i < N; i++) {
        if (i != fila) {
            Nj = 0;
            for (j=0; j < N; j++) {
                if (j != columna) {
                    destino[Ni][Nj] = origen[i][j];
                    Nj++;
                }
            }
            Ni++;
        }
    }
}

// Función recursiva que calcula el determinante por cofactores
float determinante(float matriz[10][10], int N) {
    float det = 0, signo = 1, menor[10][10];

    if (N == 1)
        return matriz[0][0];

    if (N == 2)
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];

    for (int j=0; j < N; j++) {
        submatriz(matriz, menor, N, 0, j);
        det += signo * matriz[0][j] * determinante(menor, N - 1);
        signo *= -1;
    }

    return det;
}

int main() {
    float matriz[10][10];
    int N;

    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d", &N);
	while(N < 1 || N > 10){
		printf("Cantidad no valida, considere entre los valores del 1 al 10: ");
		scanf("%d", &N);
	}

    printf("Ingrese los elementos de la matriz:\n");
    for(int i=0; i < N; i++){
			for(int j=0; j < N; j++){
				printf("\t\tA[%d][%d]: > ", i, j);
				scanf("%f", &matriz[i][j]);
			}
		}

    float resultado = determinante(matriz, N);
    printf("El determinante es: %.2f\n", resultado);

    return 0;
}
