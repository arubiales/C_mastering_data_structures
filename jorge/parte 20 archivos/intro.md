# Parámetos

* r: lectura, el archivo debe existir
* w: escritura, si el archivo no existe se crea, y si existe se sobreescribe
* a: Append, añade al final del documento, si no existe se crea
* rb: read binary, para lectura de binarios
* wb: write binary, para escritura de binarios
* r+: abre para lectura y escritura
* w+: crear para lectura y escritura
* a+: añade o crea un archivo para lectura o escritura
* rb+: abre binario para lectura y escritura
* wb+: Crea binario para lectura y escritura
* ab+: añade binario para lectura y escritura


`fputc(Carater,ApuntadorArchivo)`: función que nos permite escribir un caracter en el archivo, regresae l caracter que se presiono en el caso de que la operación sea realizada con exito o EOF (End Of File) si falló. El apuntado es el que nos brinda la función `fopen`

`fclose(ApuntadorArchivoe)`: guarda los cambios en el archivo, cierra la conexión y libera los recursos usados por el aputador.


# FUnciones de manejo de archivos:
* fopen(): Abre un archivo
* fclose(): cierra un archivo
* fgets(): lee una cádena de un archivo
* fputs(): escribe una cadena en un archivo
* fseek(): busca un byte específico en un archivo
* fprintf(): Escribe una salida con formato en el archivo.
* fscanf(): una entrada con formato desde el archivo
* feof(): Devuelve `True` si se llega al final del archivo
* ferror(): Devuelve `True` se produce un error
* rewind(): coloca el localizador de posición al principio del mismo
* remove(): borra un archivo
* fflush(): vacía un archivo
* fputsc(): Escribe un caracter en la pantalla
