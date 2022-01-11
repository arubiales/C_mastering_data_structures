# Data
## Data Structure
Es como son estructurados los datos en la RAM para ser visitados rápidamente

## DataBase
Es como son guardados los datos en el disco duro, para ser visitados cuando sea necesario

## Data Warehouse
Es como almacenamos datos, historicos, de clientes, documentos, etc. Para ser consultados cuando sea necesario

# Stack vs Heap
Cada celda de memoria es un bit, y un conjunto de bits es llamado segmento

* Un programa es un archivo alojado en el disco duro, por lo que cuando lo lanzamos pasa a la memoria RAM, a la **sección de código**
* Las variables que crea este programa para funcionar, son alojadas en el **stack**

Se llama **Stack** porque las variables son creadas en orden de declaración es decir de principio a fin, y son eliminadas cuando no van a ser más usadas es decir de fin a principio, este es el funcionamiento de un Stack y por eso su nombre. 

Cuando un programa declara un tipo de variable, reserva el espacio para esa variable, esto es llamado lenguaje estático

## Heap memmory
1. Heap memmory no está ordenada
2. Es tratada como un recurso. Es decir mientras lo que está ahí es usado, no puede ser usado por otro programa, hasta que el que lo está usando lo libere
3. Un programa  no puede acceder directamente a la memoría Heap, solo se puede acceder usando punteros

CUando quieres guardar arrays en el Heap tienes que usar new en C++ o malloc en C. Siempre hay que borrar en el Heap para que se borrar con Delete o P = null

# Physical Data Structures vs Logical Data Structure
* Las estructuras físicas definen como los elementos deben de ser guardados en memoria, por ejemplo, un array que guarda los datos de forma secuencial
* Las estructura lógicas son los conceptos de como se crean estructuras de datos como queues, stack, trees, hastables que son implementadas con al estructurás de datos array o linked list


# ADT (Abstract DataType)

1. Es la representación de los datos, como es hecha
2. Se llama "abstract" porque cada tipo de dato lleva consigo apareada unas operaciones que están permitidas, estos detalles están ocultos al programador. De esta forma se pueden agregar, remover items, etc. De una lista o array

# BIG O

Es la complejidad máxima que puede alcanzar un programa. Por ejemplo imaginemos que tenemos un Array de *n* elementos.

* Si iteramos por cada elemento la complejidad sería O(n)
* Si iteramos dos veces por cada elemento (una matriz) la complejidad sería O(n^2) (hay dos bucles)
* Si cogemos el número de elementos *n* y vamos dividiendo *n* hasta que quede uno (divide y venceras) la complejidad sería O(log(n)) (esto es un arbol que divide cada dos)
* Si iteramos por dos arrays a la vez la complejidad sería O(m+n)

# Recursion
La recursión siempre necesita de una condición para que finalice

La recursión puede ser de dos formas:
* Antes de la operación en ese caso se devolverá el primer caso el primero
* Después de la operación en ese caso de devolverá el último caso el primero
* Puede haber una combinación de ambos, que una operación sea ejecutada en el momento de la llamada y otra en el momento del retorno

Este último ejemplo sería así:

```
void fun(int n){
    i n>0{
        op1     //Es llamada antes
        fun(n-1)
        op2     //Es llamada después
    }
}
```

Los procesos recursivos son almacenados en el stack, y se crean n funciónes donde "n" es el número de llamadas a la función 3
