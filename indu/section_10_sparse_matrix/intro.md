# Sparse mátrix

Hay dos formas de representarlas

## 3-column Representation
se crean tres columnas, con fila, columna y el valor. Es como si fueran las coordenadas de un punto. Por ejemplo una matrix 3x3:


Fila | Columna | Elemento

  1        2         4
  2        0         3
  2        2         7


## Compressed sparse rows
1. Se crea una lista de elementos que no son 0.
2. Se almacena la suma acumulativa de elementos por fila en otro array
3. En otro array se almacena la columna en la que se encuentra.
