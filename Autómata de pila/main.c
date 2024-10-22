#include<stdio.h>
#include<stdlib.h>
#include "pila.h"

int main(int argc, char const *argv[])
{
	int i, verificacion;
	char cadena[100];
	Nodo* pila = NULL;

	printf("Introduce una cadena: ");
	scanf(" %99s",cadena);

	i=0;
	if (cadena[i] != '(')
	{
		if (cadena[i] == '\0')
		{
			printf("Cadena aceptada\n");
			return 0;
		}else{
			printf("Error: cadena debe de empezar con '('\n");
			return -1;
		}
	}

	while(cadena[i] != '\0')
	{
		if (cadena[i] == '(')
		{
			push(&pila, cadena[i]);
		}else if (cadena[i] == ')')
		{
			verificacion = pop(&pila);
			if (verificacion == '0')
			{
				printf("Error: Faltan '('\n");
				return -1;
			}
		}else{
			printf("Error: Caracter no valido: %c\n",cadena[i]);
			return -1;
		}
		
		i++;
	}

	verificacion = pop(&pila);
	if (verificacion == ')')
	{
		printf("Error: Faltan '('\n");
	}else if (verificacion == '(')
	{
		printf("Error: Faltan ')'\n");
	}else{
		printf("Cadena aceptada\n");
	}

	return 0;
}