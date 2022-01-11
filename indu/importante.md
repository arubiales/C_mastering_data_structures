# Array vs List

* Array puede ser creado en stack, lista tiene que ser creado en heap
* El array al ser posiciones consecutivas no puede ampliarse, necesita crearse de nuevo. La lista, solo tienes que crear más nodos.
* Las listas necesitan punteros, por lo que ocuparán más espacio
* Los arrays pueden ser accedidos directamente, las listas ha de iterarse sobre los nodos
* En las listas los datos no se mueven, en los arrays sí. Por tanto cuando existen movimientos de datos, las listas son mucho más rápidas, porque solo cambian punteros
* Las búsquedas son iguales en velocidad.

# Hashing

Hay varios métodos de hashing

## Chainning
Se basa en crear una lista FIFO en la que se entran los códigos de hash collision. Todo dependerá de nuestra función hash para que haya las menos colisiones posibles.

## Linear Probing
Se refiere a que cuando hay hash collision se va descendiendo de manera lineal al resto de huecos, para tratar de almacenar el dato.

* Uno de los problemas de este método es que se forman clusterings de datos en la búsqueda, por lo que al haber colisiones vas descendiendo y tardas mucho en buscar
* Borrar claves es complicado, ya que debes hacer rehashing, es decir, coger todas las claves de nuevo e insertarlas. Por ello en este método no se borran los datos, puedes poner una bandera, para decir si el dato ha sido borrado o no.

## Quadratic Probing
Es igual que Linear Probing lo único que en vez de aumentar linealmente cuando hay una colisión lo hace cuadráticamente, es decir se eleva al cuadrado.

## Double Hashing
Tenemos dos funciones hash, y si hay una colisión la segunda entra en acción.

Tiene dos propiedades:
1. Nunca hay un hash con resultado cero.
2. Se cubren todos lo indices, usando los números primos.

Al entrar la segunda función en acción, siempre nos da resultados distintos cuando hay una colisión


# Grafos

* Nodo: Un punto concreto
* Vertice: las lineas que unen los nodos

Hay muchos tipos de grafo, según lo nodos, aristas, dirección, etc.

En un problema de grafos la "V" representa el número de nodos y la "E" el número de aristas

**Lazo:** Cuando un nodo se dirige a el mismo.

El grado de un grafo, es la **cantidad de vertices que tiene**. También se puede indicar el grado de un nodo


Los grafos pueden ser *Dirigidos* o *NO dirigidos* si sus vertices no son flechas que indican la dirección


**Grafos adyacentes:** Dos grafos son adyacentes si tienen un mismo vertice en común. 
**Nodos adyacentes:** Dos nodos son adyacentes si tienen una arista que los une. (adyacente=conectado=unido)

**A un grafo sin ciclos se le llama árbol**

Un grafo es **regular** si todos sus nodos tienen el mismo grado

Si todos los nodos de un grafo tienen al menos un camino que los une se llama **grafo conexo**.

