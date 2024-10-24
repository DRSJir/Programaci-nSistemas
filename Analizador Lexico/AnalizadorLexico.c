#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

struct nodo_tabla
{
    int posicion;
    char nombre[10];
    int clase;
    struct nodo_tabla *siguiente;
};


//funciones para la lista
void agregar_principio(struct nodo_tabla** cabeza, int posicion, char *nombre, int clase);
void agregar_final(struct nodo_tabla** cabeza, int posicion, char *nombre, int clase);
struct nodo_tabla* buscar_nodo(struct nodo_tabla* cabeza, char *nombre);
int contiene_nodo(struct nodo_tabla* cabeza, char *nombre);
void imprimir_tabla(struct nodo_tabla* cabeza);


//Manejo de archivos
void generar_token(FILE *token, int valor, int clase);
int es_palabra_reservada(char *palabra);
int automata_identificador(char *palabra);
int automata_constante_entera(char *palabra);
int automata_caracter_especial(char *palabra);
int automata_aritmeticos(char *palabra);
int es_op_relacional(char *palabra);
int automata_asignacion(char *palabra);
void vaciar_arreglo(char *palabra);

int generar_numero(char caracter_actual, FILE *codigo_fuente);
void generar_palabra(char caracter_actual ,char *palabra, FILE *codigo_fuente, int *num_linea);
void saltar_comentario(char caracter_actual, FILE *codigo_fuente, int *num);

int main() 
{
    FILE *archivo_tabla_simbolos;
    FILE *codigo_fuente;
    FILE *archivo_token;

    char *palabra = (char*) malloc(15*sizeof(char));
    char caracter_actual;

    int num_linea = 1;
    int *ap_num_linea = &num_linea;
    int constante_entera = 0;
    int posicion = 10;

    struct nodo_tabla* tabla_simbolos = NULL;
    struct nodo_tabla* simbolo = NULL;

    //Crear tabla de símbolos
    archivo_tabla_simbolos = fopen("archivos/tabla_sibolos.txt", "w");
    
    
    //crear_tabla_simbolos(archivo_tabla_simbolos);
    fprintf(archivo_tabla_simbolos, "1,1,Entonces\n");
    agregar_final(&tabla_simbolos, 1, "Entonces", 1);
    fprintf(archivo_tabla_simbolos, "2,1,Escribir\n");
    agregar_final(&tabla_simbolos, 2, "Escribir", 1);
    fprintf(archivo_tabla_simbolos, "3,1,Fin\n");
    agregar_final(&tabla_simbolos, 3, "Fin", 1);
    fprintf(archivo_tabla_simbolos, "4,1,Hacer\n");
    agregar_final(&tabla_simbolos, 4, "Hacer", 1);
    fprintf(archivo_tabla_simbolos, "5,1,Inicio\n");
    agregar_final(&tabla_simbolos, 5, "Inicio", 1);
    fprintf(archivo_tabla_simbolos, "6,1,Leer\n");
    agregar_final(&tabla_simbolos, 6, "Leer", 1);
    fprintf(archivo_tabla_simbolos, "7,1,Mientras\n");
    agregar_final(&tabla_simbolos, 7, "Mientras", 1);
    fprintf(archivo_tabla_simbolos, "8,1,Si\n");
    agregar_final(&tabla_simbolos, 8, "Si", 1);
    fprintf(archivo_tabla_simbolos, "9,1,Sino\n");
    agregar_final(&tabla_simbolos, 9, "Sino", 1);



    //Crear archivo con los tokens
    archivo_token = fopen("archivos/token.txt", "w");

    //Cargar el código fuente
    if ((codigo_fuente = fopen("ArchivosdePrueba/Archivo1.txt", "r")) == NULL)
    {
        printf("No se ecnontró el archivo");
        fclose(codigo_fuente);
        return -1;
    }else if ((codigo_fuente = fopen("ArchivosdePrueba/Archivo1.txt", "r")) != NULL)
    {
        //iterar caracter por caracter e identificarlos
        while ((n = fgetc(codigo_fuente)) != EOF)
        {
            if (caracter_actual == ';')
            {
                //Buscar en la tabla de simbolos ese caracter
                if (contiene_nodo(tabla_simbolos, &caracter_actual) == 1)
                {
                    //Obtener la posición
                    simbolo = buscar_nodo(tabla_simbolos, &caracter_actual);
                    //Generar token
                    fprintf(archivo_token, "4 %d\n",simbolo->posicion);
                }else//sino crearlo en la tabla de símbolos
                {
                    fprintf(archivo_tabla_simbolos, "%d,4,%c\n", posicion, caracter_actual);
                    agregar_final(&tabla_simbolos, posicion, &caracter_actual, 4);
                    posicion ++;
                }
                vaciar_arreglo(palabra);
                
            }else if (caracter_actual == '(')
            {
                //Buscar en la tabla de simbolos ese caracter
                if (contiene_nodo(tabla_simbolos, &caracter_actual) == 1)
                {
                    //Obtener la posición
                    simbolo = buscar_nodo(tabla_simbolos, &caracter_actual);
                    //Generar token
                    fprintf(archivo_token, "4 %d\n",simbolo->posicion);
                }else//sino crearlo en la tabla de símbolos
                {
                    fprintf(archivo_tabla_simbolos, "%d,4,%c\n", posicion, caracter_actual);
                    agregar_final(&tabla_simbolos, posicion, &caracter_actual, 4);
                    posicion ++;
                }
                vaciar_arreglo(palabra);

            }else if (caracter_actual == ')')
            {
                //Buscar en la tabla de simbolos ese caracter
                if (contiene_nodo(tabla_simbolos, &caracter_actual) == 1)
                {
                    //Obtener la posición
                    simbolo = buscar_nodo(tabla_simbolos, &caracter_actual);
                    //Generar token
                    fprintf(archivo_token, "4 %d\n",simbolo->posicion);
                }else//sino crearlo en la tabla de símbolos
                {
                    fprintf(archivo_tabla_simbolos, "%d,4,%c\n", posicion, caracter_actual);
                    agregar_final(&tabla_simbolos, posicion, &caracter_actual, 4);
                    posicion ++;
                }
                vaciar_arreglo(palabra);
            }else if (caracter_actual == ',')
            {
                //Buscar en la tabla de simbolos ese caracter
                if (contiene_nodo(tabla_simbolos, &caracter_actual) == 1)
                {
                    //Obtener la posición
                    simbolo = buscar_nodo(tabla_simbolos, &caracter_actual);
                    //Generar token
                    fprintf(archivo_token, "4 %d\n",simbolo->posicion);
                }else//sino crearlo en la tabla de símbolos
                {
                    fprintf(archivo_tabla_simbolos, "%d,4,%c\n", posicion, caracter_actual);
                    agregar_final(&tabla_simbolos, posicion, &caracter_actual, 4);
                    posicion ++;
                }
                vaciar_arreglo(palabra);
            }else if (caracter_actual == '\t')
            {
                //Buscar en la tabla de simbolos ese caracter
                if (contiene_nodo(tabla_simbolos, &caracter_actual) == 1)
                {
                    //Obtener la posición
                    simbolo = buscar_nodo(tabla_simbolos, &caracter_actual);
                    //Generar token
                    fprintf(archivo_token, "8 %d\n",simbolo->posicion);
                }else//sino crearlo en la tabla de símbolos
                {
                    fprintf(archivo_tabla_simbolos, "%d,8,TAB\n", posicion);
                    agregar_final(&tabla_simbolos, posicion, &caracter_actual, 8);
                    posicion ++;
                }
                vaciar_arreglo(palabra);

            }else if (caracter_actual == '\n')
            {
                num_linea++;
            }else if (caracter_actual == '+')
            {
                //Buscar en la tabla de simbolos ese caracter
                if (contiene_nodo(tabla_simbolos, &caracter_actual) == 1)
                {
                    //Obtener la posición
                    simbolo = buscar_nodo(tabla_simbolos, &caracter_actual);
                    //Generar token
                    fprintf(archivo_token, "5 %d\n",simbolo->posicion);
                }else//sino crearlo en la tabla de símbolos
                {
                    fprintf(archivo_tabla_simbolos, "%d,5,%c\n", posicion, caracter_actual);
                    agregar_final(&tabla_simbolos, posicion, &caracter_actual, 5);
                    posicion ++;
                }
                vaciar_arreglo(palabra);
            }else if (caracter_actual == '-')
            {
                //Buscar en la tabla de simbolos ese caracter
                if (contiene_nodo(tabla_simbolos, &caracter_actual) == 1)
                {
                    //Obtener la posición
                    simbolo = buscar_nodo(tabla_simbolos, &caracter_actual);
                    //Generar token
                    fprintf(archivo_token, "5 %d\n",simbolo->posicion);
                }else//sino crearlo en la tabla de símbolos
                {
                    fprintf(archivo_tabla_simbolos, "%d,5,%c\n", posicion, caracter_actual);
                    agregar_final(&tabla_simbolos, posicion, &caracter_actual, 5);
                    posicion ++;
                }
                vaciar_arreglo(palabra);
            }else if (caracter_actual == '*')
            {
                //Buscar en la tabla de simbolos ese caracter
                if (contiene_nodo(tabla_simbolos, &caracter_actual) == 1)
                {
                    //Obtener la posición
                    simbolo = buscar_nodo(tabla_simbolos, &caracter_actual);
                    //Generar token
                    fprintf(archivo_token, "5 %d\n",simbolo->posicion);
                }else//sino crearlo en la tabla de símbolos
                {
                    fprintf(archivo_tabla_simbolos, "%d,5,%c\n", posicion, caracter_actual);
                    agregar_final(&tabla_simbolos, posicion, &caracter_actual, 5);
                    posicion ++;
                }
                vaciar_arreglo(palabra);
            }else if (caracter_actual == '<')
            {
                //Buscar en la tabla de simbolos ese caracter
                if (contiene_nodo(tabla_simbolos, &caracter_actual) == 1)
                {
                    //Obtener la posición
                    simbolo = buscar_nodo(tabla_simbolos, &caracter_actual);
                    //Generar token
                    fprintf(archivo_token, "6 %d\n",simbolo->posicion);
                }else//sino crearlo en la tabla de símbolos
                {
                    fprintf(archivo_tabla_simbolos, "%d,6,%c\n", posicion, caracter_actual);
                    agregar_final(&tabla_simbolos, posicion, &caracter_actual, 5);
                    posicion ++;
                }
                vaciar_arreglo(palabra);
            }else if (caracter_actual == '>')
            {
                //Buscar en la tabla de simbolos ese caracter
                if (contiene_nodo(tabla_simbolos, &caracter_actual) == 1)
                {
                    //Obtener la posición
                    simbolo = buscar_nodo(tabla_simbolos, &caracter_actual);
                    //Generar token
                    fprintf(archivo_token, "6 %d\n",simbolo->posicion);
                }else//sino crearlo en la tabla de símbolos
                {
                    fprintf(archivo_tabla_simbolos, "%d,5,%c\n", posicion, caracter_actual);
                    agregar_final(&tabla_simbolos, posicion, &caracter_actual, 6);
                    posicion ++;
                }
                vaciar_arreglo(palabra);
            }else if (caracter_actual == '/')
            {
                //Buscar en la tabla de simbolos ese caracter
                if (contiene_nodo(tabla_simbolos, &caracter_actual) == 1)
                {
                    //Obtener la posición
                    simbolo = buscar_nodo(tabla_simbolos, &caracter_actual);
                    //Generar token
                    fprintf(archivo_token, "5 %d\n",simbolo->posicion);
                }else//sino crearlo en la tabla de símbolos
                {
                    fprintf(archivo_tabla_simbolos, "%d,5,%c\n", posicion, caracter_actual);
                    agregar_final(&tabla_simbolos, posicion, &caracter_actual, 5);
                    posicion ++;
                }
                vaciar_arreglo(palabra);
            }else if (isdigit(caracter_actual))
            {
                vaciar_arreglo(palabra);
                constante_entera = generar_numero(caracter_actual, codigo_fuente);
                if (constante_entera < 0 && constante_entera > 65535)
                {
                    printf("Error");
                }else
                {
                    fprintf(archivo_token, "3 %d\n",constante_entera);
                }
                
            }else if (isalpha(caracter_actual))
            {
                generar_palabra(caracter_actual, palabra, codigo_fuente, ap_num_linea);
                if (es_palabra_reservada(palabra) == 1)
                {
                    //Buscar en la tabla de simbolos ese caracter
                    if (contiene_nodo(tabla_simbolos, palabra) == 1)
                    {
                        //Obtener la posición
                        simbolo = buscar_nodo(tabla_simbolos, palabra);
                        //Generar token
                        fprintf(archivo_token, "1 %d\n",simbolo->posicion);
                    }else//sino crearlo en la tabla de símbolos
                    {
                        fprintf(archivo_tabla_simbolos, "%d,1,%s\n", posicion, palabra);
                        agregar_final(&tabla_simbolos, posicion, palabra, 1);
                        posicion ++;
                    }
                }else if (es_op_relacional(palabra) == 1)
                {
                    //Buscar en la tabla de simbolos ese caracter
                    if (contiene_nodo(tabla_simbolos, palabra) == 1)
                    {
                        //Obtener la posición
                        simbolo = buscar_nodo(tabla_simbolos, palabra);
                        //Generar token
                        fprintf(archivo_token, "6 %d\n",simbolo->posicion);
                    }else//sino crearlo en la tabla de símbolos
                    {
                        fprintf(archivo_tabla_simbolos, "%d,6,%s\n", posicion, palabra);
                        agregar_final(&tabla_simbolos, posicion, palabra, 6);
                        posicion ++;
                    }
                }else if (automata_identificador(palabra) == 1)
                {
                    //Buscar en la tabla de simbolos ese caracter
                    if (contiene_nodo(tabla_simbolos, palabra) == 1)
                    {
                        //Obtener la posición
                        simbolo = buscar_nodo(tabla_simbolos, palabra);
                        //Generar token
                        fprintf(archivo_token, "2 %d\n",simbolo->posicion);
                    }else//sino crearlo en la tabla de símbolos
                    {
                        fprintf(archivo_tabla_simbolos, "%d,2,%s\n", posicion, palabra);
                        agregar_final(&tabla_simbolos, posicion, palabra, 2);
                        posicion ++;
                    }
                }
                vaciar_arreglo(palabra);
            }else if (caracter_actual == '{')
            {
                saltar_comentario(caracter_actual, codigo_fuente, ap_num_linea);
            }
            
        }
        
    }
    fclose(codigo_fuente);
    fclose(archivo_tabla_simbolos);
    fclose(archivo_token);
}

/* Lee el código fuente y genera un entero de maximo 6 digitos */
int generar_numero(char caracter_actual, FILE *codigo_fuente)
{
    int valor = 0;
    char *acumuladora = (char*) malloc(6* sizeof(char)); //6 digitos 65535
    int i = 0;
    while (caracter_actual != EOF && isdigit(caracter_actual))
    {
        if (!isdigit(caracter_actual))
        {
            break;
        }
        acumuladora[i] = caracter_actual;
        caracter_actual = fgetc(codigo_fuente);
        i++;
        if (i>6)
        {
            return -1;
        }
        
    }
    valor = atoi(acumuladora);
    return valor;
}

/* Recorre el comentario hasta que se cierre */
void saltar_comentario(char caracter_actual, FILE *codigo_fuente, int *num_linea)
{
    while (caracter_actual != '}' )
    {
        if (caracter_actual == '\n')
        {
            num_linea++;
        }
        if (caracter_actual == EOF)
        {
            return;
        }
        caracter_actual = fgetc(codigo_fuente);
    }
}

/* Lee todo un identificador */
void generar_palabra(char caracter_actual ,char *palabra, FILE *codigo_fuente, int *num_linea)
{
    int i = 0;
    while (isalpha(caracter_actual) || isalnum(caracter_actual) || caracter_actual == '_')
    {   
        palabra[i] = caracter_actual;
        caracter_actual = fgetc(codigo_fuente);
        i++;

        if (i>10)
        {
            printf("Error: mas de 10 cacteres en un solo identificador %s, en la línea %d",palabra, *num_linea);
            return;
        }   
    }
    ungetc(caracter_actual,codigo_fuente);
}

/* Esta función se encarga de iterar sobre el arreglo para poner todos sus elementos 
con el valor '\0' */
void vaciar_arreglo(char *palabra)
{
    for (int i = 0; i < 15; i++)
    {
        palabra[i] = '\0';
    }
       
}

int es_palabra_reservada(char *palabra)
{
    if (strcmp(palabra, "Entonces") == 0 || strcmp(palabra, "Escribir")  == 0 ||
        strcmp(palabra, "Fin")  == 0 || strcmp(palabra, "Hacer")  == 0 ||
        strcmp(palabra, "Inicio")  == 0 || strcmp(palabra, "Leer")  == 0 ||
        strcmp(palabra, "Mientras")  == 0 || strcmp(palabra, "Si")  == 0 ||
        strcmp(palabra, "Sino")  == 0)
    {
        return 1;
    }
    return 0;
}


/******     Expresiones regulares       *****/

/* let( let | dig | _ )* */
int automata_identificador(char *palabra)
{
    if (!isalpha(palabra[0]))
    {
        return 0;
    }
    
    int i=0;
    while (palabra[i] != '\0')
    {
        if (!((palabra[i] > 65 && palabra[i] < 90) || (palabra[i] > 97 && palabra[i] < 122))
            || i>10)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/* dig(dig)* */
int automata_constante_entera(char *palabra)
{
    int i = 0;
    while (!isalpha(palabra[i]))
    {
        return 0;
    }
    return 1;
}

/* ( | ) | , | ; */
int automata_caracter_especial(char *palabra)
{
    int i = 0;
    while (palabra[i] == '(' || palabra[i] == ')' ||
           palabra[i] == ',' || palabra[i] == ';')
    {
        if (i < 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/* + | - | * | / */
int automata_aritmeticos(char *palabra)
{
    int i = 0;
    while (palabra[i] == '+' || palabra[i] == '-' ||
           palabra[i] == '*' || palabra[i] == '/')
    {
        if (i < 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/* > | < | EQ | LE | GE */
int es_op_relacional(char *palabra)
{
    if (strcmp(palabra, "EQ") == 0 || strcmp(palabra, "LE") == 0 || 
        strcmp(palabra, "GE") == 0)
    {
        return 1;
    }
    return 0;
}

/* := */
int automata_asignacion(char *palabra)
{
    if (palabra[0] == ':' && palabra[1] == '=')
    {
        return 1;
    }
    return 0;
}

/* Clase|valor */
void generar_token(FILE *token, int valor, int clase)
{
    fprintf(token, "%d,%c\n",valor,clase);
}


//Funciones para la lista

void agregar_principio(struct nodo_tabla** cabeza, int posicion, char *nombre, int clase)
{
    struct nodo_tabla* nuevo_nodo = (struct nodo_tabla*) malloc(sizeof(struct nodo_tabla));//Pide memoria
    nuevo_nodo->posicion = posicion;
    strcpy(nuevo_nodo->nombre, nombre);
    nuevo_nodo->clase = clase;
    
    nuevo_nodo->siguiente = *cabeza;
    *cabeza = nuevo_nodo;
}

void agregar_final(struct nodo_tabla** cabeza, int posicion, char *nombre, int clase)
{
    struct nodo_tabla* nuevo_nodo = (struct nodo_tabla*) malloc(sizeof(struct nodo_tabla));//Pedir memoria
    nuevo_nodo->posicion = posicion;
    strcpy(nuevo_nodo->nombre, nombre);
    nuevo_nodo->clase = clase;
    
    nuevo_nodo->siguiente = NULL;

    //Si es el único nodo
    if (*cabeza == NULL)
    {
        *cabeza = nuevo_nodo;//Dudas
        return;
    }
    
    // Si hay mas nodos
    struct nodo_tabla* actual = *cabeza;
    while (actual->siguiente != NULL)
    {
        actual = actual->siguiente;
    }
    
    actual->siguiente = nuevo_nodo;
}

//Buscar un nodo con el nombre
struct nodo_tabla* buscar_nodo(struct nodo_tabla* cabeza, char *nombre)
{
    struct nodo_tabla* actual = cabeza;
    
    while (actual != NULL)
    {
        if (strcmp(nombre, actual->nombre) == 0)
        {
            return actual;
        }
        
        actual = actual->siguiente;
    }
    return NULL;   
}

int contiene_nodo(struct nodo_tabla* cabeza, char *nombre)
{
    struct nodo_tabla* actual = cabeza;
    
    while (actual != NULL)
    {
        if (strcmp(nombre, actual->nombre) == 0)
        {
            return 1;
        }
        
        actual = actual->siguiente;
    }
    return 0;
}

void imprimir_tabla(struct nodo_tabla* cabeza)
{
    struct nodo_tabla* actual = cabeza;

    while (actual != NULL) {
        int i=0;
        printf("%d,%s,%d\n", actual->posicion, actual->nombre, actual->clase);
        actual = actual->siguiente;
    }
    printf("\n");
}
