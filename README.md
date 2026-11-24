# Prácticas de programación C avanzado

Repositorio de ejercicios, practicas y parciales de programacion en C, organizado como una coleccion de proyectos independientes.

Contiene mas de 220 directorios, 464 archivos fuente y 219 proyectos de Code::Blocks. Los ejercicios avanzan desde los fundamentos del lenguaje hasta estructuras de datos dinamicas, manejo de archivos y resolucion de parciales.

## Contenido

- [Stack tecnologico](#stack-tecnologico)
- [Areas practicadas](#areas-practicadas)
- [Funcionalidades y ejercicios destacados](#funcionalidades-y-ejercicios-destacados)
- [Estructura del repositorio](#estructura-del-repositorio)
- [Cómo ejecutar un ejercicio](#cómo-ejecutar-un-ejercicio)
- [Practicas incluidas](#practicas-incluidas)
- [Convenciones del repositorio](#convenciones-del-repositorio)
- [Autor](#autor)

## Stack tecnologico

| Tecnologia | Uso |
| --- | --- |
| C | Lenguaje principal de todos los ejercicios |
| GCC | Compilador utilizado en los proyectos |
| Code::Blocks | Entorno principal y generador de los archivos `.cbp` |
| Headers `.h` | Declaraciones, tipos, constantes y contratos de cada practica |
| Archivos binarios y texto | Persistencia, conversiones, lotes y merge de datos |
| Memoria dinamica | Creacion y administracion de nodos y estructuras enlazadas |

Los proyectos incluyen opciones de compilacion para las configuraciones `Debug` y `Release`, con banderas como `-Wall`, `-g` y `-O2`.

Muchos programas estan orientados al entorno Windows, por lo que pueden utilizar funciones como `getch()`, `conio.h` o `setlocale(LC_CTYPE, "Spanish")`. En Linux pueden requerir ajustes menores de portabilidad.

## Areas practicadas

### Fundamentos del lenguaje

- Modificadores de tipo y mascaras de bits
- Conversiones y casteo
- Operadores ternarios, incremento y decremento
- `typedef`, enumeraciones y estructuras
- Campos de bits
- Alcance de variables y variables globales o externas
- Preprocesador y compilacion condicional
- Macros simples y multilinea

### Funciones, punteros y memoria

- Paso de parametros por valor y por referencia
- Aritmetica de punteros
- Punteros a funciones
- Indireccion multiple
- Funciones recursivas e iterativas
- Memoria estatica y dinamica
- Uso de `malloc`, `free` y asignacion de nodos
- Ordenamientos con `bsearch` y `qsort`

### Arrays, matrices y cadenas

- Carga, recorrido y ordenamiento de vectores
- Insercion y eliminacion de elementos
- Operaciones con matrices
- Matrices identidad y simetricas
- Transpuesta y producto matricial
- Vecinos de una posicion
- Implementaciones y simulacros de funciones de `string.h`
- Normalizacion de nombres y procesamiento de cadenas

### Archivos

- Archivos binarios
- Archivos de texto con longitud fija y longitud variable
- Conversion entre archivo binario y texto
- Posicionamiento del puntero con `fseek`
- Correccion y depuracion de registros
- Lotes de prueba con registros hardcodeados
- Generacion de datos pseudoaleatorios
- Merge de archivos maestro y novedades
- Operaciones entre archivos: union, interseccion y diferencias

### Estructuras de datos

- Pilas estaticas y dinamicas
- Pilas circulares
- Colas estaticas y dinamicas
- Colas circulares
- Listas simplemente enlazadas
- Listas doblemente enlazadas
- Listas circulares
- Arboles binarios de busqueda
- Arboles de expresion
- Recorridos preorden, inorden y posorden
- Indices estaticos y sus operaciones

### Aplicaciones practicas

- Juegos de dados y cartas
- Calculadora de operandos binarios
- Fechas, calendarios y calculos de edad
- Aproximaciones numericas
- Series de Fibonacci
- Palindromos y cadenas numericas
- Gestion de empleados y calificaciones
- Movimientos bancarios
- Gestion de productos y proveedores
- Torneos deportivos
- Colas de espera

## Funcionalidades y ejercicios destacados

### Implementacion de TDA

Las carpetas de primitivas separan responsabilidades entre el dato, las declaraciones y las operaciones:

- `dato.h`: estructura o tipo almacenado
- `primitivas_*.h`: interfaz publica del TDA
- `primitivas_*.c`: implementacion de las operaciones
- `main.c`: demostracion o menu de uso
- `header.h`: inclusiones y declaraciones comunes

Ejemplos disponibles:

- [Pilas estaticas y dinamicas](./PRIMITIVAS%20DE%20PILA%20Y%20COLA)
- [Listas enlazadas y circulares](./PRIMITIVAS%20DE%20LISTAS)
- [Arbol binario](./PRIMITIVAS%20DE%20%C3%81RBOL)
- [Indice estatico](./PRIMITIVAS%20DE%20%C3%8DNDICE)

### Archivos e integracion

Ejercicios como el `merge de archivos` trabajan con archivos maestros, archivos de novedades, registros de error y archivos actualizados.

Las practicas de archivos binarios implementan distintos formatos de registro y muestran como convertir datos entre representaciones binarias y textuales.

### Recorridos y resolucion de problemas

Las practicas de arboles permiten cargar estructuras, recorrerlas en distintos ordenes y exportar los resultados a archivos binarios y de texto.

Los parciales integran varias tecnicas al mismo tiempo: archivos, listas, colas, pilas, indices, matrices, cadenas y arboles.

## Estructura del repositorio

```text
.
|-- PRIMITIVAS DE PILA Y COLA/
|-- PRIMITIVAS DE LISTAS/
|-- PRIMITIVAS DE ÁRBOL/
|-- PRIMITIVAS DE ÍNDICE/
|-- clase 01 (...)/
|-- clase 02 (...)/
|-- ...
|-- parcial 1 (...)/
|-- parcial 2 (...)/
`-- practicas independientes/
```

Cada ejercicio suele ser un proyecto autocontenible. Los nombres descriptivos indican el tema y pueden incluir variantes como:

- Estatica y dinamica
- Iterativa y recursiva
- Con subindices y aritmética de punteros
- Implementacion con cola o con variable global
- Versiones nuevas y antiguas de una misma practica
- Ejercicios de repaso

## Cómo ejecutar un ejercicio

### Con Code::Blocks

1. Abrir el archivo `.cbp` ubicado dentro de la carpeta del ejercicio.
2. Seleccionar la configuracion `Debug` o `Release`.
3. Compilar con `Build`.
4. Ejecutar con `Run`.

### Desde la terminal con GCC

Cada proyecto puede tener un conjunto distinto de archivos fuente. Desde la carpeta de una practica simple puede utilizarse:

```bash
cd "factorial"
gcc -Wall -g main.c funciones.c -o factorial
./factorial
```

Si el ejercicio esta dividido en varios modulos, incluir todos los archivos `.c` necesarios:

```bash
cd "clase 11 (primitivas de pila dinámica)"
gcc -Wall -g main.c functions.c primitivas_pila_dinámica.c -o pila
./pila
```

Los nombres de archivo pueden contener espacios o caracteres no ASCII. Es recomendable abrir el `.cbp` o escribir las rutas entre comillas.

## Practicas incluidas

La progresion del repositorio cubre, entre otros temas:

- Introduccion a C y depuracion
- Tipos, operadores, estructuras y macros
- Arrays y matrices
- Cadena de caracteres y biblioteca `string`
- Archivos binarios y texto
- Memoria dinamica
- Ordenamiento y busqueda
- Pilas, colas y listas
- Recursion
- Arboles binarios
- Indices
- Parciales integradores

Los proyectos son material educativo y conservan variantes personales de las soluciones: pueden existir varias implementaciones para el mismo concepto.

## Convenciones del repositorio

- Cada ejercicio ocupa su propia carpeta.
- Los nombres de carpetas describen el tema o el enunciado.
- Las funciones y tipos suelen separarse en archivos `.c` y `.h`.
- Las estructuras de datos siguen el patron de declarar el TDA en un header y ocultar su implementacion en su modulo `.c`.
- Los archivos binarios y de prueba forman parte de varios ejercicios y pueden ser necesarios para ejecutarlos.
- Los proyectos de Code::Blocks incluyen salidas generadas en las carpetas `bin/` y `obj/`.

## Autor

Fabián Norberto Escobar
