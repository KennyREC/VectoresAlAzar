#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int azar() {
    return rand() % 16 + 20;
}

void mostrarVector(int vector[]) {
    printf("Vector: ");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

int contarRepeticiones(int vector[], int numero) {
    int contador = 0;
    for (int i = 0; i < MAX; i++) {
        if (vector[i] == numero) {
            contador++;
        }
    }
    return contador;
}

int main() {
    srand(42); 

    int vector1[MAX];
    int vector2[MAX];
    int unionVector[MAX * 2];
    int interseccion[MAX];
    int diferencia1[MAX];
    int diferencia2[MAX];

    int opcion;

    do {
        printf("\nMenu:\n");
        printf("1. Llenar y mostrar vectores con repeticiones\n");
        printf("2. Llenar y mostrar vectores sin repeticiones\n");
        printf("3. Mostrar union de vectores\n");
        printf("4. Mostrar interseccion de vectores\n");
        printf("5. Mostrar resta (Vector1 - Vector2)\n");
        printf("6. Mostrar resta (Vector2 - Vector1)\n");
        printf("7. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                for (int i = 0; i < MAX; i++) {
                    vector1[i] = azar();
                    vector2[i] = azar();
                }
                mostrarVector(vector1);
                mostrarVector(vector2);
                for (int i = 0; i < MAX; i++) {
                    printf("Repeticiones en vector1[%d]: %d\n", i, contarRepeticiones(vector1, vector1[i]));
                    printf("Repeticiones en vector2[%d]: %d\n", i, contarRepeticiones(vector2, vector2[i]));
                }
                break;
            case 2:
                for (int i = 0; i < MAX; i++) {
                    vector1[i] = azar();
                    int repetido;
                    do {
                        vector2[i] = azar();
                        repetido = 0;
                        for (int j = 0; j < i; j++) {
                            if (vector2[i] == vector2[j]) {
                                repetido = 1;
                                break;
                            }
                        }
                    } while (repetido);
                }
                mostrarVector(vector1);
                mostrarVector(vector2);
                break;
            case 3:
                for (int i = 0; i < MAX; i++) {
                    unionVector[i] = vector1[i];
                    unionVector[i + MAX] = vector2[i];
                }
                mostrarVector(unionVector);
                break;
            case 4:
                for (int i = 0; i < MAX; i++) {
                    for (int j = 0; j < MAX; j++) {
                        if (vector1[i] == vector2[j]) {
                            interseccion[i] = vector1[i];
                        }
                    }
                }
                mostrarVector(interseccion);
                break;
            case 5:
                for (int i = 0; i < MAX; i++) {
                    diferencia1[i] = vector1[i] - vector2[i];
                }
                mostrarVector(diferencia1);
                break;
            case 6:
                for (int i = 0; i < MAX; i++) {
                    diferencia2[i] = vector2[i] - vector1[i];
                }
                mostrarVector(diferencia2);
                break;
            case 7:
                printf("Saliendo del programa\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo\n");
        }
    } while (opcion != 7);

    return 0;
}
