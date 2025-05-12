# Spotifind – Buscador de Canciones

## Descripción

**Spotifind** es una aplicación en lenguaje C que permite gestionar y buscar canciones a partir de un archivo CSV. Los usuarios pueden importar una base de datos de canciones y filtrarlas por género, artista o tempo (BPM). El objetivo principal es ofrecer una herramienta sencilla y eficiente para explorar colecciones musicales desde la terminal.

Este proyecto utiliza listas dinámicas para manejar múltiples canciones y artistas por canción, y facilita la navegación mediante menús interactivos y búsqueda flexible sin distinción entre mayúsculas o minúsculas.

## Cómo compilar y ejecutar

El programa ha sido desarrollado en **C** y puede ejecutarse en entornos como **Visual Studio Code**, usando extensiones de soporte para C/C++.

### Requisitos previos:

- Tener instalado [Visual Studio Code](https://code.visualstudio.com/).
- Instalar la extensión **C/C++** de Microsoft.
- Tener un compilador C como **gcc** (en Windows se recomienda [MinGW](https://www.mingw-w64.org/) o usar [WSL](https://learn.microsoft.com/en-us/windows/wsl/)).

### Pasos para compilar y ejecutar:

1. **Descarga el proyecto y descomprímelo** en una carpeta.
2. **Abre la carpeta en Visual Studio Code**:
    - `Archivo > Abrir carpeta...`
3. **Compila el programa**:
    - Abre una terminal (`Terminal > Nueva terminal`)
    - Ejecuta:
      ```bash
      gcc *.c -o spotifind
      ```
4. **Ejecuta el programa**:
    ```bash
    ./spotifind
    ```

> ⚠️ Asegúrate de tener implementadas las funciones auxiliares como `leer_linea_csv`, `split_string`, `list_create`, etc., y los archivos `.h` correspondientes dentro de una carpeta `tdas/`.

## Funcionalidades

### Actualmente disponibles:

- **Leer canciones desde un archivo CSV**
  - Se extraen datos como ID, título, artistas, álbum, género y tempo.
- **Buscar canciones por género**
  - Permite filtrar canciones que coincidan parcial o totalmente con un género ingresado.
- **Buscar canciones por artista**
  - Filtra las canciones donde el nombre del artista coincida con el texto ingresado.
- **Buscar canciones por tempo**
  - Categoriza las canciones en tres grupos:
    - Lentas (< 80 BPM)
    - Moderadas (80–120 BPM)
    - Rápidas (> 120 BPM)

### Por mejorar:

- Validación de entrada más robusta (por ejemplo, evitar tempos vacíos).
- Posibilidad de exportar resultados a archivos.
- Incorporar más criterios de búsqueda, como el año o la duración.

## Ejemplo de uso

### Paso 1: Leer canciones desde CSV

```
Ingrese la ruta del archivo CSV: canciones.csv
245 canciones cargadas correctamente.
```

### Paso 2: Buscar por género

```
Ingrese el genero a buscar: rock
Resultados para genero: rock
...
```

### Paso 3: Buscar por artista

```
Ingrese el artista a buscar: queen
Resultados para artista: queen
...
```

### Paso 4: Buscar por tempo

```
Seleccione categoria de tempo:
1. Lentas (<80 BPM)
2. Moderadas (80-120 BPM)
3. Rapidas (>120 BPM)
Opcion: 3
Resultados para tempo Rapidas (120-1000 BPM)
...
```

## Créditos

Desarrollado como proyecto universitario para la asignatura de estructuras de datos.  
Autor: [Tu nombre o alias aquí]  
Carrera: Ingeniería Civil Informática – PUCV