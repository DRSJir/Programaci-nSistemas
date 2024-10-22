#ifndef PILA_H
#define PILA_H

struct Nodo {
    char dato;
    struct Nodo *siguiente;
};
typedef struct Nodo Nodo;

void push(Nodo** pila, char dato);
char pop(Nodo** pila);

#endif