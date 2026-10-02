🎓✨ Sistema de Gestión Académica en C++

🤖 Proyecto desarrollado en C++ aplicando Programación Orientada a Objetos (POO)
📚 Gestión de alumnos, materias, calificaciones, maestros y administradores.
💻 Interfaz completamente basada en consola.

🌟 Descripción del proyecto

Este proyecto consiste en un Sistema de Gestión Académica desarrollado en C++, diseñado para administrar diferentes tipos de personas dentro de una institución educativa.

El sistema permite trabajar con:

👨‍🎓 Alumnos

👨‍🏫 Maestros

👨‍💼 Administradores

📚 Materias

📝 Calificaciones

📖 Historial académico

Además, el proyecto implementa conceptos importantes de Programación Orientada a Objetos, como:

🔹 Encapsulamiento
🔹 Herencia
🔹 Polimorfismo
🔹 Constructores
🔹 Métodos get y set
🔹 Arreglos de objetos
🔹 Punteros
🔹 Memoria dinámica

🧠 Objetivo

El objetivo principal del proyecto es desarrollar un sistema académico sencillo que permita practicar y demostrar el uso de POO en C++, utilizando diferentes clases relacionadas entre sí.

La estructura principal se basa en una clase padre:

Persona


de la cual heredan:

Alumno
Maestro
Administrador


De esta manera, se representa una relación de herencia dentro del sistema:

                 ┌──────────────┐
                 │   Persona    │
                 └──────┬───────┘
                        │
          ┌─────────────┼─────────────┐
          │             │             │
     ┌────▼────┐   ┌────▼─────┐  ┌────▼─────────┐
     │ Alumno  │   │ Maestro  │  │Administrador │
     └─────────┘   └──────────┘  └──────────────┘

🏗️ Estructura de clases
👤 Clase Persona

Es la clase base del sistema.

Contiene los atributos comunes para las personas:

string nombre;
int edad;


También proporciona métodos para modificar y consultar estos datos.

🔧 Principales métodos
Método	Función
setNombre()	Modifica el nombre
getNombre()	Obtiene el nombre
setEdad()	Modifica la edad
getEdad()	Obtiene la edad
mostrar()	Muestra los datos

Además, posee un destructor virtual:

virtual ~Persona() {
}


Esto permite trabajar correctamente con herencia y punteros de tipo Persona.

🎓 Clase Alumno

La clase Alumno hereda de Persona:

class Alumno : public Persona


Además de los datos heredados, contiene:

string matricula;
Materia materias[10];
Calificacion calificaciones[10];
int numMaterias;
int numCalificaciones;

📌 Funcionalidades

El alumno puede:

🆔 Tener una matrícula.

📚 Registrar materias.

📝 Registrar calificaciones.

🔍 Buscar materias mediante su clave.

📖 Consultar su historial académico.

📚 Clase Materia

Representa una materia académica.

Sus atributos son:

string nombre;
string clave;


Ejemplo:

Materia: Programacion
Clave: PROG01

🔧 Métodos principales
setNombre()
getNombre()

setClave()
getClave()

mostrar()

📝 Clase Calificacion

Representa una calificación asociada a una materia.

Contiene:

string claveMateria;
float nota;


La nota solamente puede encontrarse dentro del rango:

0 ─────────────── 10


Si se introduce una calificación fuera de ese rango, el programa muestra:

Nota invalida.

👨‍🏫 Clase Maestro

La clase Maestro también hereda de Persona:

class Maestro : public Persona


Agrega el atributo:

string especialidad;


Ejemplo:

Nombre: Carlos
Edad: 35
Especialidad: Matematicas

👨‍💼 Clase Administrador

La clase Administrador hereda igualmente de Persona:

class Administrador : public Persona


Su atributo adicional es:

string departamento;


Ejemplo:

Nombre: Ana
Edad: 40
Departamento: ControlEscolar

🔄 Herencia

Una de las partes importantes del proyecto es la utilización de herencia.

Tanto Alumno, Maestro como Administrador utilizan los atributos y métodos de Persona.

class Alumno : public Persona

class Maestro : public Persona

class Administrador : public Persona


Esto evita repetir código y permite reutilizar funcionalidades comunes.

🧬 Polimorfismo

El programa también utiliza polimorfismo mediante punteros.

Se utiliza un arreglo de punteros:

Persona* personas[100];


En este arreglo pueden almacenarse objetos de diferentes clases derivadas:

personas[numPersonas] = new Maestro(n, e, esp);


o:

personas[numPersonas] = new Administrador(n, e, d);


Posteriormente se puede recorrer el arreglo y llamar:

personas[i]->mostrar();


De esta manera, cada objeto utiliza su propia implementación del método mostrar().

🧮 Gestión de alumnos

El programa puede almacenar hasta:

const int MAX = 10;


Por lo tanto:

👨‍🎓 Máximo de alumnos: 10

Cada alumno puede tener:

📚 Máximo de materias: 10

y:

📝 Máximo de calificaciones: 10

🎮 Menú principal

Al iniciar el programa aparece el siguiente menú:

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

⚙️ Funcionalidades
👨‍🎓 Registrar alumno

Permite introducir:

Nombre
Edad
Matrícula


Ejemplo:

Nombre: Juan
Edad: 20
Matricula: A001

Alumno registrado.

🔎 Buscar alumno

El sistema permite buscar un alumno utilizando su nombre.

Nombre del alumno a buscar: Juan


Si existe:

Alumno encontrado en la posicion 1:

Nombre: Juan
Edad: 20
Matricula: A001

✏️ Modificar alumno

Permite cambiar:

👤 Nombre

🎂 Edad

🆔 Matrícula

🗑️ Eliminar alumno

El sistema busca al alumno y posteriormente mueve los elementos siguientes del arreglo para ocupar su lugar.

Esto se realiza mediante:

for (int i = indice; i < cantidadAlumnos - 1; i++) {
    alumnos[i] = alumnos[i + 1];
}


Después se reduce la cantidad de alumnos:

cantidadAlumnos--;

📚 Agregar materia

Primero se busca al alumno y después se registra:

Nombre de la materia
Clave de la materia


Ejemplo:

Nombre de la materia: Programacion
Clave de la materia: PROG01

Materia agregada.

📝 Registrar calificación

Para registrar una calificación es necesario que la materia exista previamente.

Ejemplo:

Clave de la materia: PROG01
Nota: 9.5

Calificacion registrada.


Si la materia no existe:

La materia no existe.

📖 Historial académico

La opción:

10. Mostrar Historial Academico.


permite visualizar las materias y sus respectivas calificaciones.

Ejemplo:

Historial de Juan

Materia: Programacion
Clave: PROG01
Nota: 9.5
---------------------

Materia: Matematicas
Clave: MAT01
Nota: 8.7
---------------------

👨‍🏫 Registro de maestros

El sistema permite registrar maestros mediante:

Nombre
Edad
Especialidad


Ejemplo:

Nombre: Carlos
Edad: 35
Especialidad: Programacion

Maestro registrado.

👨‍💼 Registro de administradores

También es posible registrar administradores:

Nombre
Edad
Departamento


Ejemplo:

Nombre: Ana
Edad: 40
Departamento: Servicios

Administrador registrado.

👥 Mostrar personas

La opción:

13. Mostrar Maestros y Administradores.


recorre el arreglo:

Persona* personas[100];


y muestra la información almacenada.

Esto permite demostrar el uso de punteros, herencia y polimorfismo. 🧠✨

📊 Cálculo del promedio

La opción:

4. Calcular Promedio.


calcula actualmente el promedio de edades de los alumnos registrados.

La operación utilizada es:

double suma = 0;

for (int i = 0; i < cantidadAlumnos; i++) {
    suma += alumnos[i].getEdad();
}

double promedio = suma / cantidadAlumnos;


Ejemplo:

Promedio de edades: 20.5


💡 Nota: Aunque la opción se llama "Calcular Promedio", en esta versión calcula el promedio de las edades, no el promedio de las calificaciones.

🛠️ Tecnologías utilizadas
Tecnología	Uso
🟦 C++	Lenguaje principal
🧱 POO	Estructura del proyecto
🔗 Herencia	Relación entre Persona y sus clases derivadas
🧬 Polimorfismo	Uso de punteros Persona*
📦 Arreglos	Almacenamiento de datos
💾 Memoria dinámica	Creación de maestros y administradores
🖥️ Consola	Interfaz del programa
📦 Librerías utilizadas

El proyecto utiliza principalmente:

#include <iostream>
#include <string>

iostream

Se utiliza para la entrada y salida de datos:

cin
cout

string

Permite trabajar con cadenas de texto:

string nombre;
string matricula;
string especialidad;

🧹 Liberación de memoria

Los maestros y administradores se crean dinámicamente mediante:

new


Por ejemplo:

personas[numPersonas] = new Maestro(n, e, esp);


Por esta razón, al finalizar el programa se libera la memoria:

for (int i = 0; i < numPersonas; i++) {
    delete personas[i];
}


Esto ayuda a evitar fugas de memoria. 🧹💾

📁 Estructura del proyecto

Una estructura sencilla del proyecto sería:

📂 SistemaGestionAcademica
│
├── 📄 main.cpp
│
└── 📄 README.md

💻 Requisitos

Para ejecutar el proyecto necesitas:

💻 Un compilador de C++.

🛠️ GCC / MinGW / Visual Studio / Code::Blocks / Dev-C++ u otro IDE compatible.

📚 Soporte para C++.

▶️ Compilar y ejecutar

Si utilizas g++, puedes compilar el proyecto con:

g++ main.cpp -o sistema


Después ejecuta:

🪟 Windows
sistema.exe

🐧 Linux / 🍎 macOS
./sistema

🧠 Conceptos de POO aplicados

Este proyecto permite observar varios conceptos fundamentales:

🔒 Encapsulamiento

Los atributos se mantienen privados:

private:
    string matricula;


y se accede a ellos mediante métodos:

setMatricula()
getMatricula()

🧬 Herencia

Las clases derivadas utilizan:

: public Persona

🎭 Polimorfismo

Se utilizan punteros de la clase base:

Persona* personas[100];


para almacenar diferentes tipos de objetos.

🏗️ Constructores

Cada clase posee constructores para inicializar sus atributos.

🧹 Destructor virtual

La clase Persona cuenta con:

virtual ~Persona() {
}


lo cual es importante cuando se trabaja con objetos derivados mediante punteros de la clase base.

🚀 Posibles mejoras futuras

El proyecto puede continuar creciendo con nuevas funcionalidades:

💾 Guardar información en archivos .txt.

📂 Cargar automáticamente los datos al iniciar.

🔐 Agregar un sistema de usuarios y contraseñas.

📊 Calcular el promedio real de las calificaciones.

📈 Generar estadísticas académicas.

🔎 Permitir búsquedas por matrícula.

🗃️ Utilizar vector en lugar de arreglos estáticos.

🧱 Separar las clases en archivos .h y .cpp.

🗄️ Implementar una base de datos.

🖥️ Crear una interfaz gráfica.

📝 Permitir nombres con espacios utilizando getline().

🛡️ Agregar validación de entradas del usuario.

🤖 Uso de Inteligencia Artificial

Este proyecto puede contar con apoyo de herramientas de Inteligencia Artificial 🤖 durante su desarrollo.

La IA puede utilizarse como apoyo para:

💡 Generar ideas para la estructura del programa.

🧠 Comprender conceptos de C++.

🐛 Detectar errores.

📚 Explicar funciones y clases.

✨ Mejorar la documentación.

📝 Organizar el README.

🚀 Proponer mejoras para el proyecto.

La revisión, comprensión, adaptación y ejecución del código forman parte del proceso de desarrollo del proyecto.

🎯 Conclusión

Este Sistema de Gestión Académica representa una aplicación práctica de los fundamentos de Programación Orientada a Objetos en C++.

A través de sus diferentes clases y funcionalidades es posible administrar:

👨‍🎓 Alumnos
        ↓
📚 Materias
        ↓
📝 Calificaciones


y también:

                 👤 Persona
                    │
        ┌───────────┼───────────┐
        ↓           ↓           ↓
   🎓 Alumno    👨‍🏫 Maestro   👨‍💼 Administrador


El proyecto demuestra cómo diferentes conceptos de C++ pueden combinarse para crear un sistema funcional, organizado y fácilmente ampliable. 🚀

⭐ Proyecto académico
╔══════════════════════════════════════════╗
║      🎓 SISTEMA DE GESTIÓN ACADÉMICA    ║
║                                          ║
║          💻 Desarrollado en C++          ║
║          🧠 Programación Orientada a     ║
║             Objetos                     ║
║                                          ║
║          🤖 + 💻 + 📚 + 🚀              ║
╚══════════════════════════════════════════╝


✨ "Cada línea de código es un paso más hacia convertir una idea en un programa." 💻🚀
