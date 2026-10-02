# 🎓 Sistema de Gestión Académica en C++

Sistema de gestión académica desarrollado en **C++** aplicando los principios de **Programación Orientada a Objetos (POO)**. Permite administrar alumnos, materias, calificaciones, maestros y administradores mediante una interfaz de consola.

---

## 📑 Tabla de Contenidos

- [Descripción](#-descripción)
- [Objetivo](#-objetivo)
- [Jerarquía de Clases](#-jerarquía-de-clases)
- [Estructura de Clases](#-estructura-de-clases)
- [Conceptos de POO Aplicados](#-conceptos-de-poo-aplicados)
- [Menú Principal](#-menú-principal)
- [Funcionalidades](#-funcionalidades)
- [Tecnologías y Librerías](#-tecnologías-y-librerías)
- [Requisitos](#-requisitos)
- [Compilación y Ejecución](#-compilación-y-ejecución)
- [Estructura del Proyecto](#-estructura-del-proyecto)
- [Mejoras Futuras](#-mejoras-futuras)
- [Uso de IA](#-uso-de-inteligencia-artificial)
- [Conclusión](#-conclusión)

---

## 📖 Descripción

Este proyecto consiste en un **Sistema de Gestión Académica** desarrollado en C++, diseñado para administrar diferentes tipos de personas dentro de una institución educativa.

El sistema permite trabajar con:

- 👨‍🎓 Alumnos
- 👨‍🏫 Maestros
- 👨‍💼 Administradores
- 📚 Materias
- 📝 Calificaciones
- 📖 Historial académico

---

## 🧠 Objetivo

Desarrollar un sistema académico sencillo que permita **practicar y demostrar el uso de POO en C++**, utilizando clases relacionadas mediante herencia, polimorfismo y memoria dinámica.

---

## 🏗️ Jerarquía de Clases

La estructura principal se basa en una clase padre `Persona`, de la cual heredan `Alumno`, `Maestro` y `Administrador`:

```
                 ┌──────────────┐
                 │   Persona    │
                 └──────┬───────┘
                        │
          ┌─────────────┼─────────────┐
          │             │             │
     ┌────▼────┐   ┌────▼─────┐  ┌────▼─────────┐
     │ Alumno  │   │ Maestro  │  │Administrador │
     └─────────┘   └──────────┘  └──────────────┘
```

---

## 🧩 Estructura de Clases

### 👤 Clase `Persona` (Base)

Atributos comunes:

```cpp
string nombre;
int edad;
```

**Métodos principales:**

| Método          | Función              |
|-----------------|----------------------|
| `setNombre()`   | Modifica el nombre   |
| `getNombre()`   | Obtiene el nombre    |
| `setEdad()`     | Modifica la edad     |
| `getEdad()`     | Obtiene la edad      |
| `mostrar()`     | Muestra los datos    |

Incluye un **destructor virtual** para permitir el uso correcto de polimorfismo con punteros:

```cpp
virtual ~Persona() {}
```

---

### 🎓 Clase `Alumno`

Hereda de `Persona`:

```cpp
class Alumno : public Persona
```

Atributos adicionales:

```cpp
string matricula;
Materia materias[10];
Calificacion calificaciones[10];
int numMaterias;
int numCalificaciones;
```

**Funcionalidades:**

- 🆔 Tener una matrícula
- 📚 Registrar materias
- 📝 Registrar calificaciones
- 🔍 Buscar materias por clave
- 📖 Consultar historial académico

---

### 📚 Clase `Materia`

```cpp
string nombre;
string clave;
```

Ejemplo: `Programacion` — `PROG01`

Métodos: `setNombre()`, `getNombre()`, `setClave()`, `getClave()`, `mostrar()`.

---

### 📝 Clase `Calificacion`

```cpp
string claveMateria;
float nota;
```

La nota debe estar en el rango **0 – 10**. Si se introduce fuera de rango, se muestra:

```
Nota invalida.
```

---

### 👨‍🏫 Clase `Maestro`

```cpp
class Maestro : public Persona
```

Atributo adicional:

```cpp
string especialidad;
```

Ejemplo:
```
Nombre: Carlos
Edad: 35
Especialidad: Matematicas
```

---

### 👨‍💼 Clase `Administrador`

```cpp
class Administrador : public Persona
```

Atributo adicional:

```cpp
string departamento;
```

Ejemplo:
```
Nombre: Ana
Edad: 40
Departamento: ControlEscolar
```

---

## 🧬 Conceptos de POO Aplicados

### 🔒 Encapsulamiento

Los atributos se mantienen privados y se accede mediante getters/setters:

```cpp
private:
    string matricula;
```

### 🔄 Herencia

```cpp
class Alumno : public Persona
class Maestro : public Persona
class Administrador : public Persona
```

### 🎭 Polimorfismo

Uso de punteros de la clase base:

```cpp
Persona* personas[100];
personas[numPersonas] = new Maestro(n, e, esp);
personas[i]->mostrar();
```

### 🏗️ Constructores

Cada clase posee constructores para inicializar sus atributos.

### 🧹 Destructor virtual

```cpp
virtual ~Persona() {}
```

### 💾 Memoria dinámica

Liberación al finalizar el programa:

```cpp
for (int i = 0; i < numPersonas; i++) {
    delete personas[i];
}
```

---

## 🎮 Menú Principal

```
╔════════════════════════════════════════╗
║              📚 MENÚ                   ║
╠════════════════════════════════════════╣
║ 1.  Registrar Alumno                   ║
║ 2.  Mostrar un Alumno                  ║
║ 3.  Mostrar Todos los Alumnos          ║
║ 4.  Calcular Promedio                  ║
║ 5.  Buscar Alumno por nombre           ║
║ 6.  Eliminar Alumno                    ║
║ 7.  Modificar Alumno                   ║
║ 8.  Agregar Materia                    ║
║ 9.  Registrar Calificación             ║
║ 10. Mostrar Historial Académico        ║
║ 11. Registrar Maestro                  ║
║ 12. Registrar Administrador            ║
║ 13. Mostrar Maestros y Administradores ║
║ 14. Salir                              ║
╚════════════════════════════════════════╝
```

---

## ⚙️ Funcionalidades

### 👨‍🎓 Registrar Alumno

Solicita:
- Nombre
- Edad
- Matrícula

```
Nombre: Juan
Edad: 20
Matricula: A001

Alumno registrado.
```

### 🔎 Buscar Alumno por Nombre

```
Nombre del alumno a buscar: Juan

Alumno encontrado en la posicion 1:
Nombre: Juan
Edad: 20
Matricula: A001
```

### ✏️ Modificar Alumno

Permite cambiar: nombre, edad y matrícula.

### 🗑️ Eliminar Alumno

Desplaza los elementos posteriores para ocupar el hueco:

```cpp
for (int i = indice; i < cantidadAlumnos - 1; i++) {
    alumnos[i] = alumnos[i + 1];
}
cantidadAlumnos--;
```

### 📚 Agregar Materia

```
Nombre de la materia: Programacion
Clave de la materia: PROG01

Materia agregada.
```

### 📝 Registrar Calificación

Requiere que la materia exista previamente:

```
Clave de la materia: PROG01
Nota: 9.5

Calificacion registrada.
```

Si no existe: `La materia no existe.`

### 📖 Historial Académico

```
Historial de Juan

Materia: Programacion
Clave: PROG01
Nota: 9.5
---------------------

Materia: Matematicas
Clave: MAT01
Nota: 8.7
---------------------
```

### 👨‍🏫 Registrar Maestro

```
Nombre: Carlos
Edad: 35
Especialidad: Programacion

Maestro registrado.
```

### 👨‍💼 Registrar Administrador

```
Nombre: Ana
Edad: 40
Departamento: Servicios

Administrador registrado.
```

### 👥 Mostrar Maestros y Administradores

Recorre el arreglo `Persona* personas[100]`, demostrando el uso de **punteros, herencia y polimorfismo**.

### 📊 Calcular Promedio

Actualmente calcula el **promedio de edades** de los alumnos:

```cpp
double suma = 0;
for (int i = 0; i < cantidadAlumnos; i++) {
    suma += alumnos[i].getEdad();
}
double promedio = suma / cantidadAlumnos;
```

Ejemplo:
```
Promedio de edades: 20.5
```

> 💡 **Nota:** Aunque la opción se llama "Calcular Promedio", en esta versión calcula el promedio de las edades, no el de las calificaciones.

### 📏 Límites del sistema

| Elemento            | Máximo |
|---------------------|--------|
| Alumnos             | 10     |
| Materias por alumno | 10     |
| Calificaciones      | 10     |

---

## 🛠️ Tecnologías y Librerías

| Tecnología           | Uso                                        |
|----------------------|--------------------------------------------|
| 🟦 C++               | Lenguaje principal                         |
| 🧱 POO               | Estructura del proyecto                    |
| 🔗 Herencia          | Relación entre `Persona` y sus derivadas   |
| 🧬 Polimorfismo      | Uso de punteros `Persona*`                 |
| 📦 Arreglos          | Almacenamiento de datos                    |
| 💾 Memoria dinámica  | Creación de maestros y administradores     |
| 🖥️ Consola           | Interfaz del programa                      |

**Librerías utilizadas:**

```cpp
#include <iostream>
#include <string>
```

- `iostream` → entrada/salida (`cin`, `cout`)
- `string` → cadenas de texto (`string nombre`, `string matricula`, etc.)

---

## 💻 Requisitos

- Un compilador de C++ (GCC, MinGW, Visual Studio, etc.)
- Un IDE compatible (Code::Blocks, Dev-C++, VS Code, etc.)
- Soporte para C++

---

## ▶️ Compilación y Ejecución

**Compilar con g++:**

```bash
g++ main.cpp -o sistema
```

**Ejecutar:**

🪟 **Windows:**
```bash
sistema.exe
```

🐧 **Linux / 🍎 macOS:**
```bash
./sistema
```

---

## 📁 Estructura del Proyecto

```
📂 SistemaGestionAcademica
│
├── 📄 main.cpp
└── 📄 README.md
```

---

## 🚀 Mejoras Futuras

- 💾 Guardar información en archivos `.txt`
- 📂 Cargar automáticamente los datos al iniciar
- 🔐 Sistema de usuarios y contraseñas
- 📊 Calcular el promedio real de las calificaciones
- 📈 Generar estadísticas académicas
- 🔎 Búsqueda por matrícula
- 🗃️ Usar `vector` en lugar de arreglos estáticos
- 🧱 Separar las clases en archivos `.h` y `.cpp`
- 🗄️ Implementar una base de datos
- 🖥️ Crear una interfaz gráfica
- 📝 Permitir nombres con espacios usando `getline()`
- 🛡️ Validación de entradas del usuario

---

## 🤖 Uso de Inteligencia Artificial

Este proyecto puede apoyarse en herramientas de IA durante su desarrollo. La IA puede utilizarse como apoyo para:

- 💡 Generar ideas para la estructura del programa
- 🧠 Comprender conceptos de C++
- 🐛 Detectar errores
- 📚 Explicar funciones y clases
- ✨ Mejorar la documentación
- 📝 Organizar el README
- 🚀 Proponer mejoras

La **revisión, comprensión, adaptación y ejecución del código** forman parte del proceso de desarrollo del proyecto.

---

## 🎯 Conclusión

Este Sistema de Gestión Académica representa una aplicación práctica de los fundamentos de **Programación Orientada a Objetos en C++**.

A través de sus clases y funcionalidades es posible administrar:

```
👨‍🎓 Alumnos  →  📚 Materias  →  📝 Calificaciones
```

Y también:

```
                 👤 Persona
                    │
        ┌───────────┼───────────┐
        ↓           ↓           ↓
   🎓 Alumno    👨‍🏫 Maestro   👨‍💼 Administrador
```

El proyecto demuestra cómo diferentes conceptos de C++ pueden combinarse para crear un sistema **funcional, organizado y fácilmente ampliable**. 🚀

---

```
╔══════════════════════════════════════════╗
║      🎓 SISTEMA DE GESTIÓN ACADÉMICA    ║
║                                          ║
║          💻 Desarrollado en C++          ║
║          🧠 Programación Orientada a     ║
║             Objetos                      ║
║                                          ║
║          🤖 + 💻 + 📚 + 🚀               ║
╚══════════════════════════════════════════╝
```

> ✨ *"Cada línea de código es un paso más hacia convertir una idea en un programa."* 💻🚀

---

⭐ **Proyecto académico**
