LoginData.txt: Información que fué ingresada para el armado de la base de datos de usuarios, los datos no presentes fueron generados pseudoaletoriamente o inicializados en 0. (Nombre, apellido, sexo y si es profesor o estudiante.

usuarios.txt: Información de la base de datos de los usuarios, al momento de generado el mismo archivo.

usuarios.bin: Archivo binario donde se guardan los 100 usuarios pedidos, tiene su versión de backup, en caso de que por algún error sea borrado, usuarios_backup.bin.
En el mismo se guardan los siguientes datos del usuario (nombres de acuerdo al correspondiente struct):
	-name: Nombre del usuario, cadena tipo c de hasta 30 caracteres.
	-surname: Apellido, cadena tipo c de hasta 30 caracteres.
	-id: Identificador de usuario, corresponde a legajo, número entero.
	-password: Contraseña de ingreso, número entero.
	-sex: Sexo del usuario, char ‘M’ o ‘F’.
	-teacher: Indica si es profesor, 1 para profesor, 0 para estudiantes, booleano.
	-last_access: Hora de último acceso a la sesión.

palabrasX.txt: Los archivos de cada una de las letras del abecedario se irán guardando en la carpeta a medida que se indique en el programa. En los archivos no se distinguen entre mayúsculas y minúsculas, es decir que si se ingresa “a” o “A”, el archivo generado será el mismo. Por otro lado, a la hora de extraer las palabras del texto, sólo tuvimos en cuenta palabras que no contengan caracteres especiales entre medio, es decir que para términos como “ex-presidente", se separarían en “ex” y “presidente”.

frecuencia.txt: En este archivo de texto, es guardada la tabla de frecuencia creada en la opción I: “Estadísticas a nivel caracteres”, en la cual se encuentran los caracteres encontrados en el texto a procesar y a su derecha la cantidad de veces que aparecen los mismos.Como caracteres solamente contamos las letras aparecidas en este archivo, despreciando el resto de expresiones.
