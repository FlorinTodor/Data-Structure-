# Data-Structure-

## Repositorio basado en la asignatura "Estructura de Datos" de la Universidad de Granada.

### En dicho repositorio se encuentran las diferentes prácticas realizadas durante el curso 2022-2023 y los diferentes retos pedidos en la teoría

# 📘 Proyecto – Estructuras de Datos

Este repositorio contiene las prácticas de la asignatura **Estructuras de Datos** (Grado en Ingeniería Informática, Doble Grado en Informática + Matemáticas / ADE).
El proyecto está dividido en **una práctica preliminar (P0)** sobre eficiencia y **cuatro prácticas principales (P1–P4)**, cada una enfocada en un conjunto de estructuras de datos y problemas aplicados.

---

## 📂 Contenido

### Práctica 0 – Eficiencia
-   Estudio experimental de la eficiencia temporal de distintos algoritmos.
-   Análisis de tiempos de ejecución y comparación con funciones de complejidad teórica.
-   Gráficas y ajuste de curvas para comprobar el coste computacional.

---

### Práctica 1 – Imágenes digitales (TDA Imagen)
-   Manipulación de imágenes en niveles de gris (formato PGM).
-   Implementación del **TDA `Image`** con operaciones básicas: creación, carga, guardado, acceso y modificación de píxeles.
-   Programas desarrollados:
    -   `negativo.cpp` → obtener el negativo de una imagen.
    -   `subimagen.cpp` → extracción de subimágenes.
    -   `zoom.cpp` → ampliación 2X de una región.
    -   `icono.cpp` → reducción de imágenes para generar iconos.

---

### Práctica 2 – Colas y Pilas con máximo
-   Implementación de **TDAs lineales**: pilas (LIFO) y colas (FIFO).
-   Extensión con estructuras **MaxStack** y **MaxQueue**, que permiten conocer en todo momento el valor máximo almacenado.
-   Programas de prueba:
    -   `pila_max.cpp` → test de inserciones/extracciones en pila con máximo.
    -   `cola_max.cpp` → test de inserciones/extracciones en cola con máximo.

---

### Práctica 3 – Contenedores de letras y Diccionario
-   Basada en el juego de *Cifras y Letras* (prueba de las letras).
-   Implementación de los TDAs:
    -   **`LettersSet`**: conjunto de letras con repeticiones y puntuaciones.
    -   **`Bag<T>`**: clase genérica (template) que permite extracción aleatoria sin reemplazo.
    -   **`LettersBag`**: bolsa de letras específica basada en `Bag<char>`.
    -   **`Dictionary`**: diccionario de palabras válido para el juego.
-   Archivos de entrada:
    -   `letras.txt` → definición de letras, repeticiones y puntuaciones.
    -   `diccionario.txt` → listado de palabras permitidas.

---

### Práctica 4 – Árbol de letras y Solver
-   Optimización del TDA `Dictionary` mediante un **árbol LCRS (Left-Child Right-Sibling)**.
-   Implementación del **iterador del diccionario** para recorrer palabras en orden alfabético.
-   Estructuras utilizadas:
    -   **`tree`** (árbol general LCRS).
    -   **`Dictionary`** implementado sobre árbol para reducir espacio y mejorar eficiencia.
-   Desarrollo de un **Solver** para el juego de las letras:
    -   Versión inicial.
    -   Versión eficiente con iterador de palabras válidas.
-   Análisis de eficiencia y comparativa entre distintos solvers.

---

## 🛠 Tecnologías y Lenguaje
-   Lenguaje: **C++**
-   Librerías estándar: `set`, `map`, `queue`, `stack`, `vector`.
-   Uso de **clases template** e **iteradores personalizados**.
-   Entrada/salida estándar y ficheros externos (`.txt`, `.pgm`).

---

## 📈 Aprendizajes Clave
-   Modelado de problemas reales (imágenes, juegos, colecciones de datos) con TDAs.
-   Implementación modular de clases en C++.
-   Uso de plantillas para estructuras genéricas.
-   Técnicas de eficiencia: análisis teórico y medición experimental.
-   Recorridos de árboles y diseño de iteradores.
-   Comparación entre representaciones y estructuras para optimizar memoria y tiempo.

---

## 📄 Organización del Repositorio
```bash
.
├── P0_Eficiencia/   # Scripts y gráficas de eficiencia
├── P1_Imagenes/     # Código de la práctica 1 (TDA Imagen, negativo, subimagen, zoom, icono)
├── P2_Colas_Pilas/  # Código de la práctica 2 (MaxStack, MaxQueue)
├── P3_Contenedores/ # Código de la práctica 3 (LettersSet, Bag, LettersBag, Dictionary)
├── P4_Arbol/        # Código de la práctica 4 (Tree, Dictionary sobre árbol, Solver)
└── README.md        # Documentación general del proyecto
```

---

## 📚 Referencias
- Documentación STL de C++:  
  - [queue](https://www.cplusplus.com/reference/queue/queue/)  
  - [stack](https://www.cplusplus.com/reference/stack/stack/)  
  - [set](https://www.cplusplus.com/reference/set/set/)  
  - [map](https://www.cplusplus.com/reference/map/map/)

