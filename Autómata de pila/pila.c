#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


void push(Nodo** pila, char dato) {
	//Reservar espacio en la memoria
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    
    //Asignar valores
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
}

//Regresa '0' en caso de que la cadena este vacia
char pop(Nodo** pila) {
    if (*pila == NULL) {
        return '0'; // O cualquier valor que indique error
    }

    //Eliminar de la pila
    Nodo* temp = *pila;
    char dato = temp->dato;
    *pila = temp->siguiente;
    free(temp);
    //Regresa el dato eliminado
    return dato;
}