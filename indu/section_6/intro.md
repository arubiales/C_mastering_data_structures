# Dinamic allocation

* En C la allocación de memoria debe ser decidida en tiempo de compilación mientras que en C++ puede ser también decidida en tiempo de ejecución
* Heap memory no puede ser accedida directamente, si no indirectamente a través de un puntero.
* Los arrays en Heap pueden ser cambiados de tamaño, pero en el stack no es posible.

# Arrays y compiladores

el código de máquina, almacena los nombres de las variables ya que no se refiere a ellas por el nombre que le damos nosotros. Por lo que el nombre de una variable se almacena en una posición de memoria.

La variable toma nombre, cuando un valor es alocado en una parte de la memoria, y esto sucede **durante la ejecución del programa**.

En C, C++, Python y otros lenguajes, se accede a los indices partiendo de cero, ya que es como empiezan las memorias de los ordenadores, y si no fuese así, tendríamos que restar siempre uno, para ir accediendo a todos lo números, lo que haría que el lenguaje sea más lento. La formula sería así:

```
addres(A[idx]) = id + idx * type
```
Donde
* id: es la primera posición de memoria
* idx: es el indice solicitado
* type: es el tipo de dato y los bytes que ocupa

## 2D array y compiladores

Los arrays 2D son almacenados de forma continua, pero la formula cambia al tener que ver las columnas y las filas. Sería así:

```
addres(A[idx1][idx2]) = idx + [idx1*idx2 +idx2] *type
```
Donde:
* idx es la posición primera de la matriz
* idx1: es el número de filas de la matrix
* idx2: es el número de columnas de la matrix
* type: es el tipo de dato (su espacio en memoria)

Al igual que antes, si hay un lenguaje de programación que empiece con 1 el rpimer indice, sera más lento porque esta formula será más compleja
