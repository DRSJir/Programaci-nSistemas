#include <stdio.h>
#include<string.h>

int automata(char cadena[], int tam);

int main()
{
    char cadena[80];
    int condicion = 0;

    printf("Introduce una cadena valida por el automata: ");
    scanf("%s", cadena);
    condicion = automata(cadena, strlen(cadena));

    if(condicion == 1) 
    {
        printf("\nHaleluya sí es una cedena valida");
    }else
    {
        printf("\n¡No le sabes!");
    }

    return 0;
}

// 0 es falso
// 1 verdadero 
int automata(char cadena[], int tam)
{
    if (cadena[0] == 'x' && tam==1)
    {
        return 1;
    }
    
    if (cadena[0] == 'x' && tam > 0 && tam%2 != 0)
    {
        for (int i = 1; i < tam; i++)
        {
            if (i%2 != 0)
            {
                if (!(cadena[i] == 'x' || cadena[i] == 'y'))
                {
                    printf("caso impar\n");
                    printf("iteracion: %d\n", i);
                    printf("i mod 2: %d\n", i%2);
                    printf("cadena: %c\n", cadena[i]);
                    return 0;
                }
            } else if (i%2 == 0)
            {
                if (cadena[i] != 'y')
                {
                    printf("caso par\n");
                    printf("iteracion: %d\n", i);
                    printf("cadena: %c\n", cadena[i]);
                    printf("i: %d\n", i);
                    printf("cadena: %c\n", cadena[i]);
                    return 0;
                }
            }
        }
        return 1;
    } else {
        return 0;
    }
}

/**
 * 
 */
