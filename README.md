# 🎵 Spotifind – Buscador de Canciones

## 📌 Descripción

**Spotifind** es una aplicación en lenguaje C que permite gestionar y buscar canciones a partir de un archivo CSV. Los usuarios pueden importar una base de datos de canciones y filtrarlas por género, artista o tempo (BPM).

---

## ⚙️ Cómo compilar y ejecutar

Este programa está escrito en **C** y se recomienda ejecutar en ambientes como **Visual Studio Code**.

### ✅ Requisitos previos

- [Visual Studio Code](https://code.visualstudio.com/)
- Extensión **C/C++** de Microsoft
- Compilador **gcc** (en Windows se recomienda [MinGW](https://www.mingw-w64.org/) o [WSL](https://learn.microsoft.com/en-us/windows/wsl/))

### 🚀 Instrucciones

1. **Clona o descarga** este repositorio y descomprímelo en una carpeta de tu elección.
2. **Abre el proyecto en Visual Studio Code**  
   `Archivo > Abrir carpeta...`
3. **Compila el proyecto** desde la terminal integrada:
    ```bash
    gcc tdas/*.c tarea2_lecturacsv.c -Wno-unused-result -o tarea2_lecturacsv
    ```
4. **Ejecuta el programa**:
    ```bash
    ./tarea2_lecturacsv
    ```

> 📁 Asegúrate de tener todos los archivos `.c` y `.h` (incluyendo los de la carpeta `tdas/`) en la misma carpeta o configurados correctamente.

---

## 🎯 Funcionalidades

### ✔️ Implementadas

- Lectura de canciones desde un archivo CSV.
- Búsqueda por:
  - Género
  - Artista
  - Tempo (Lentas, Moderadas, Rápidas)

### 🔧 En desarrollo / Por mejorar

- Validación avanzada de entradas del usuario.
- Exportación de resultados a un archivo.
- Filtros por año o duración de la canción.
- Interfaz más amigable en terminal.

---

## 🧪 Ejemplo de uso

### 1️⃣ Leer canciones desde archivo

```bash
Ingrese la ruta del archivo CSV: data/canciones.csv
245 canciones cargadas correctamente.
```

### 2️⃣ Buscar por género

```bash
Ingrese el genero a buscar: rock
Resultados para genero: rock
...
```

### 3️⃣ Buscar por artista

```bash
Ingrese el artista a buscar: queen
Resultados para artista: queen
...
```

### 4️⃣ Buscar por tempo

```bash
Seleccione categoria de tempo:
1. Lentas (<80 BPM)
2. Moderadas (80-120 BPM)
3. Rapidas (>120 BPM)
Opcion: 3
Resultados para tempo Rapidas (120-1000 BPM)
...
