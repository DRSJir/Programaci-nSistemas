# Implementación de un autómata de pila
Entrega: 5 de octubre 2024

# Autómata con paréntesis balanceados
Este programa implementa un autómata de pila que acepta las cadenas $L=\{(^n)^n,n \geq 0 \}$

| $q_0$           | $($                     | $)$                 | $\dashv$   |
| --------------- | ----------------------- | ------------------- | ---------- |
| $($             | Push $($<br>Avaza $q_0$ | Pop<br>Avanza $q_0$ | Faltan $)$ |
| $\triangledown$ | Push $($<br>Avaza $q_0$ | Faltan $($          | Avanza     |

## Formato de código en C
En el código en C, el símbolo $\dashv$ será remplazado por un `\0`.

Ejemplo 1:
```
Introduce una cadena: (())()
Cadena aceptada
```
En este caso el símbolo  o `\0` esta implícito en la estructura del código en C, al almacenar en un arreglo de caracteres o cadena.

Ejemplo 2:
```
Introduce una cadena: ()(())
Cadena aceptada
```

Ejemplo 3:
```
Introduce una cadena: ()
Cadena aceptada
```

### Compilar
`gcc pila.c main.c -o pila`

### Ejecutar:
`./pila`
