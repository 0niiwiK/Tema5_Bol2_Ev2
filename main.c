#include <stdio.h>
#define TAM 10 // Definimos la dimension del vector

// PROTOTIPOS
void ordenacionSeleccion(int v[], int pos_i, int pos_f); // Ordena un vector de menor a mayor
void rellenaVector(int v[]); // Rellena manualmente un vector
void imprimeVector(int v[]); // Imprime un vector
void insertarOrdenado(int v[]); // Inserta un valor en un vector en su lugar correspondiente

int main() {
    int vector[TAM];
    rellenaVector(vector);
    ordenacionSeleccion(vector,0,TAM-1);
    imprimeVector(vector);
    insertarOrdenado(vector);
    imprimeVector(vector);
    return 0;
}

void ordenacionSeleccion(int v[], int pos_i, int pos_f){
    /* Este procedimiento ordena un vector utilizando el algoritmo de ordenacion por seleccion.
    * Este algoritmo busca el menor valor de un vector y lo situa en la primera posicion.
    * Seguidamente, realiza la misma operacion pero descartando las posiciones ya ordenada */

    int pos_min; // Indica la posicion reservada del vector para el "minimo" valor
    int aux; // Variable auxiliar

    for (int i = pos_i; i < pos_f; i++) {
        // El bucle inicia desde la posicion "pos_i" (posicion inicial) hasta "pos_f" (posicion final).

        pos_min = i;
        // Guardamos la posicion "reservada" del vector, donde se guardara el menor valor encontrado hacia la derecha.
        // Esta ira modificandose con cada instancia del bucle inicial

        for (int j = pos_min + 1; j <= pos_f; j++) {
            // Este bucle busca desde una posicion a la derecha de la posicion reservada hasta el final del vector
            // Buscando un "minimo" para almacenarlo en la posicion reservada

            if (v[j] < v[pos_min]) {
                // Se comprueba si el valor es menor al valor almacenado en la posicion reservada
                // De ser asi:
                aux = v[j]; // Guardamos el valor encontrado en la variable auxiliar
                v[j] = v[pos_min]; // Sobreescribimos en la posicion actual, el valor guardado como "minimo"
                v[pos_min] = aux; // Sobreescribimos en la posicion "reservada" el valor almacenado en la variable auxiliar
            }
        }
    }
} // Ordena un vector de menor a mayor

void rellenaVector(int v[]){
    // Rellena un vector de forma manual

    for (int i = 0; i < TAM; ++i) {
        printf("Introduzca el valor del elemento %d: ",i+1);
        scanf("%d",&v[i]);
        fflush(stdin);
    }
} // Rellena manualmente un vector

void imprimeVector(int v[]){
    // Imprime un vector

    printf("\nVector ordenado:\n|");
    for (int i = 0; i < TAM; i++) {
        printf(" %d |",v[i]);
    }
    printf("\n");
} // Imprime un vector

void insertarOrdenado(int v[]){
    /* Solicita, lee y comprueba un valor en rango del vector y lo inserta en su posicion correspondiente
     * Borrando el ultimo elemento del vector */

    int valor_i=v[0], valor_f=v[TAM-1];
    // Declaramos e inicializamos los valores limites del vector (valor inicial y final)

    int num, pos;
    // Declaramos la variable "num" para almacenar el numero a introducir y su posicion correspondiente del vector

    printf("\nIntroduce el numero a insertar (entre %d y %d): ",valor_i,valor_f);
    scanf("%d",&num);
    fflush(stdin);
    while (num<valor_i || num>valor_f){
        printf("Numero fuera de rango\nIntroduce el numero a insertar (entre %d y %d): ",valor_i,valor_f);
        scanf("%d",&num);
        fflush(stdin);
    }
    // Se comprueba que "num" esta dentro del rango del vector

    int i=0;
    while (v[i]<=num){
        // Buscamos la posicion que le corresponderia a "num" dentro del vector
        i++;
    }
    pos=i; // Guardamos la posicion obtenida
    for (i = TAM-1; i > pos; i--) {
        /* Recorremos el vector desde el final hasta la posicion guardada "pos"
         * Sustituyendo cada valor por su valor anterior
         * (destruyendo el ultimo valor y duplicando el valor de la posicion "pos") */

        v[i]=v[i-1];
    }
    v[pos]=num; // Sustituimos el valor almacenado en "pos" por el numero guardado en "num"
} // Inserta un valor en un vector en su lugar correspondiente